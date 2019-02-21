;***********************************************************************
;	Program Name: Direct Addressing Example
;	J.S. Thweatt
;	06 April 2003
;	2504 Class Software Project 1
;***********************************************************************

;***********************************************************************
; Microchip-developed include file
;
; This include file is a set of equate statements that allows the use of
; address and symbolic labels such as STATUS for file memory location
; 0x04, and C for the carry bit of the STATUS register.
;***********************************************************************

	include P16F84.inc

;***********************************************************************
; Local equate table
;
; These are user-defined equate statements.  They name symbolic
; variables that are specific to this program.
;***********************************************************************

w	equ	0	; DDR = 0 - store the result in w
f	equ	1	; DDR = 1 - store the result in f

one	equ	0x11	; The address of the first addend
two	equ	0x12	; The address of the second addend
sum	equ	0x13	; The address for sum storage

;***********************************************************************
; The ORG statement means that the first line of the executable program
; code after the ORG statement will be placed in program memory location
; 0, and that successive instructions will be placed in the next
; consecutive program memory location.
;***********************************************************************

	org	0

;***********************************************************************
; It's a sad day when there are more comments in a program than there is
; program in the program, but this is supposed to be illustrative.  In
; order to add the two numbers using direct addressing, we only have to
; use the proper instructions to operate on the addresses where addends
; are stored.
;***********************************************************************

start	clrw		; We start by setting W = 0

	addwf	one,w	; W = W plus the first addend.  Note that the
			; result is maintanined in W, since the data
			; direction bit is 0.

	addwf	two,w	; W = W plus the second addend.  Since we kept
			; the first sum in W, W now holds the sum of
			; the addends. 

	movwf	sum	; Move the contents of W into address SUM.  The
			; direction of data is implied, (w => f)  so no
			; data direction bit is needed

finish	goto	finish	; Since PIC Assembly has no HALT statement, we
			; need an "instruction" that will put the
			; processor in a state where no changes can
			; possibly happen to the processor's state.  An
			; infinite loop does the job adequately.

;***********************************************************************
; The last line of executable code must be followed with the END
; statement.
;***********************************************************************

	end
