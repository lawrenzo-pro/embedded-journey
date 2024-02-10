	.file	"main.c"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.global	__mulsf3
.global	__ltsf2
.global	__gtsf2
.global	__fixunssfsi
.global	main
	.type	main, @function
main:
	push r28
	push r29
	in r28,__SP_L__
	in r29,__SP_H__
	sbiw r28,36
	in __tmp_reg__,__SREG__
	cli
	out __SP_H__,r29
	out __SREG__,__tmp_reg__
	out __SP_L__,r28
/* prologue: function */
/* frame size = 36 */
/* stack size = 38 */
.L__stack_usage = 38
	ldi r24,lo8(36)
	ldi r25,0
	std Y+2,r25
	std Y+1,r24
	ldi r24,lo8(37)
	ldi r25,0
	std Y+4,r25
	std Y+3,r24
	ldi r24,lo8(42)
	ldi r25,0
	std Y+6,r25
	std Y+5,r24
	ldi r24,lo8(43)
	ldi r25,0
	std Y+8,r25
	std Y+7,r24
	ldd r24,Y+5
	ldd r25,Y+6
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,32
	ldd r24,Y+5
	ldd r25,Y+6
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+5
	ldd r25,Y+6
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,64
	ldd r24,Y+5
	ldd r25,Y+6
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+1
	ldd r25,Y+2
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,1
	ldd r24,Y+1
	ldd r25,Y+2
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+1
	ldd r25,Y+2
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,2
	ldd r24,Y+1
	ldd r25,Y+2
	movw r30,r24
	std Z+1,r19
	st Z,r18
.L18:
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,32
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	andi r18,191
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+3
	ldd r25,Y+4
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,2
	ldd r24,Y+3
	ldd r25,Y+4
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldi r24,0
	ldi r25,0
	ldi r26,lo8(-6)
	ldi r27,lo8(67)
	std Y+23,r24
	std Y+24,r25
	std Y+25,r26
	std Y+26,r27
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(122)
	ldi r21,lo8(69)
	ldd r22,Y+23
	ldd r23,Y+24
	ldd r24,Y+25
	ldd r25,Y+26
	call __mulsf3
	movw r26,r24
	movw r24,r22
	std Y+27,r24
	std Y+28,r25
	std Y+29,r26
	std Y+30,r27
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-128)
	ldi r21,lo8(63)
	ldd r22,Y+27
	ldd r23,Y+28
	ldd r24,Y+29
	ldd r25,Y+30
	call __ltsf2
	cp r24, __zero_reg__
	brge .L23
	ldi r24,lo8(1)
	ldi r25,0
	std Y+32,r25
	std Y+31,r24
	rjmp .L4
.L23:
	ldi r18,0
	ldi r19,lo8(-1)
	ldi r20,lo8(127)
	ldi r21,lo8(71)
	ldd r22,Y+27
	ldd r23,Y+28
	ldd r24,Y+29
	ldd r25,Y+30
	call __gtsf2
	cpi r24,lo8(1)
	brlt .L24
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(32)
	ldi r21,lo8(65)
	ldd r22,Y+23
	ldd r23,Y+24
	ldd r24,Y+25
	ldd r25,Y+26
	call __mulsf3
	movw r26,r24
	movw r24,r22
	movw r22,r24
	movw r24,r26
	call __fixunssfsi
	movw r26,r24
	movw r24,r22
	std Y+32,r25
	std Y+31,r24
	rjmp .L7
.L8:
	ldi r24,lo8(-112)
	ldi r25,lo8(1)
	std Y+34,r25
	std Y+33,r24
	ldd r24,Y+33
	ldd r25,Y+34
/* #APP */
 ;  105 "/usr/avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	std Y+34,r25
	std Y+33,r24
	nop
	ldd r24,Y+31
	ldd r25,Y+32
	sbiw r24,1
	std Y+32,r25
	std Y+31,r24
.L7:
	ldd r24,Y+31
	ldd r25,Y+32
	sbiw r24,0
	brne .L8
	rjmp .L9
.L24:
	ldd r22,Y+27
	ldd r23,Y+28
	ldd r24,Y+29
	ldd r25,Y+30
	call __fixunssfsi
	movw r26,r24
	movw r24,r22
	std Y+32,r25
	std Y+31,r24
.L4:
	ldd r24,Y+31
	ldd r25,Y+32
	std Y+36,r25
	std Y+35,r24
	ldd r24,Y+35
	ldd r25,Y+36
/* #APP */
 ;  105 "/usr/avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	std Y+36,r25
	std Y+35,r24
	nop
.L9:
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,64
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+3
	ldd r25,Y+4
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	ori r18,1
	ldd r24,Y+3
	ldd r25,Y+4
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	ld r24,Z
	ldd r25,Z+1
	movw r18,r24
	andi r18,223
	ldd r24,Y+7
	ldd r25,Y+8
	movw r30,r24
	std Z+1,r19
	st Z,r18
	ldi r24,0
	ldi r25,0
	ldi r26,lo8(-6)
	ldi r27,lo8(67)
	std Y+9,r24
	std Y+10,r25
	std Y+11,r26
	std Y+12,r27
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(122)
	ldi r21,lo8(69)
	ldd r22,Y+9
	ldd r23,Y+10
	ldd r24,Y+11
	ldd r25,Y+12
	call __mulsf3
	movw r26,r24
	movw r24,r22
	std Y+13,r24
	std Y+14,r25
	std Y+15,r26
	std Y+16,r27
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(-128)
	ldi r21,lo8(63)
	ldd r22,Y+13
	ldd r23,Y+14
	ldd r24,Y+15
	ldd r25,Y+16
	call __ltsf2
	cp r24, __zero_reg__
	brge .L25
	ldi r24,lo8(1)
	ldi r25,0
	std Y+18,r25
	std Y+17,r24
	rjmp .L12
.L25:
	ldi r18,0
	ldi r19,lo8(-1)
	ldi r20,lo8(127)
	ldi r21,lo8(71)
	ldd r22,Y+13
	ldd r23,Y+14
	ldd r24,Y+15
	ldd r25,Y+16
	call __gtsf2
	cpi r24,lo8(1)
	brlt .L26
	ldi r18,0
	ldi r19,0
	ldi r20,lo8(32)
	ldi r21,lo8(65)
	ldd r22,Y+9
	ldd r23,Y+10
	ldd r24,Y+11
	ldd r25,Y+12
	call __mulsf3
	movw r26,r24
	movw r24,r22
	movw r22,r24
	movw r24,r26
	call __fixunssfsi
	movw r26,r24
	movw r24,r22
	std Y+18,r25
	std Y+17,r24
	rjmp .L15
.L16:
	ldi r24,lo8(-112)
	ldi r25,lo8(1)
	std Y+20,r25
	std Y+19,r24
	ldd r24,Y+19
	ldd r25,Y+20
/* #APP */
 ;  105 "/usr/avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	std Y+20,r25
	std Y+19,r24
	nop
	ldd r24,Y+17
	ldd r25,Y+18
	sbiw r24,1
	std Y+18,r25
	std Y+17,r24
.L15:
	ldd r24,Y+17
	ldd r25,Y+18
	sbiw r24,0
	brne .L16
	rjmp .L17
.L26:
	ldd r22,Y+13
	ldd r23,Y+14
	ldd r24,Y+15
	ldd r25,Y+16
	call __fixunssfsi
	movw r26,r24
	movw r24,r22
	std Y+18,r25
	std Y+17,r24
.L12:
	ldd r24,Y+17
	ldd r25,Y+18
	std Y+22,r25
	std Y+21,r24
	ldd r24,Y+21
	ldd r25,Y+22
/* #APP */
 ;  105 "/usr/avr/include/util/delay_basic.h" 1
	1: sbiw r24,1
	brne 1b
 ;  0 "" 2
/* #NOAPP */
	std Y+22,r25
	std Y+21,r24
	nop
.L17:
	rjmp .L18
	.size	main, .-main
	.ident	"GCC: (GNU) 13.2.0"
