#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define ss_pin 10
#define reset_pin 9
#define RED 7
#define BLUE 6
#define BEEP 5
MFRC522 mfrc522(ss_pin,reset_pin);
Servo myservo;
LiquidCrystal_I2C lcd(0x3f,16,2);
int pos = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.init();
  lcd.backlight();
  myservo.attach(3);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(BEEP,OUTPUT);
}
void sweep(){
  while(pos <= 180){
    myservo.write(pos);
    pos++;
    delay(5);
  }
}
void antisweep(){
  while(pos >= 0){
    myservo.write(pos);
    pos--;
    delay(5);
  }
}
void alarm(){
  for(int i = 0; i <= 5;i++){
    digitalWrite(BEEP,HIGH);
    delay(100);
    digitalWrite(BEEP,LOW);
    delay(100);
  }
}
void auth(){
  lcd.setCursor(0,0);
  lcd.print("Scan your card");
}
void loop() {
  // put your main code here, to run repeatedly:
  //lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Welcome!");
  lcd.setCursor(0, 1);
  antisweep();
  lcd.print("Scan your tag!");
  if(!mfrc522.PICC_IsNewCardPresent()){
    return ;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return ;
  }
  String content = " ";
  for(byte i = 0; i<mfrc522.uid.size;i++){
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content = content.substring(1);
  content.toUpperCase();
  if(content == " 43 C8 56 A8"){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access Granted!");
    digitalWrite(BLUE,HIGH);
    sweep();
    delay(1000);
    lcd.clear();
    digitalWrite(BLUE,LOW);
  }
  else{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Access denied!");
    digitalWrite(RED,HIGH);
    alarm();
    //delay(1000);
    lcd.clear();
    digitalWrite(RED,LOW);
  }
  Serial.println(content);
}