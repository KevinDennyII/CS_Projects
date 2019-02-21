;***********************************************************************
;	Program Name: Indirect Addressing Example
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

n	equ	0x10	; The number of elements in the array
count	equ	0x11	; A variable to be used in the FOR loop
sum	equ	0x12	; The address for sum storage
first	equ	0x20	; The address of the first array element

;***********************************************************************
; The ORG statement means that the first line of the executable program
; code after the ORG statement will be placed in program memory location
; 0, and that successive instructions will be placed in the next
; consecutive program memory location.
;***********************************************************************

	org	0

;***********************************************************************
; More comments.  To add the array of numbers indirectly, we have to
; initialize the FSR register, which is the PIC processor's "pointer."
; Note that first is being used as a literal, since the value to which
; it has been equated represents the value of the first address in the
; array.  If memory address 0x13 (first) had *contained* the address of
; the first element of the array, we would have used it as a file
; location instead of as a literal.
;***********************************************************************

start	movlw	first	; The value 0x20 is placed into W.  Remember
			; that FIRST is being used as a literal here.

	movwf	FSR	; The value in W is placed into FSR.  Now,
			; indirect instructions are pointing to address
			; 0x20.

	movf	n,w	; The value in N is being moved to W.

	movwf	count	; The value in W is being moved to COUNT.  Now,
			; COUNT = N, and we have a copy of N that we
			; can change.  This is useful when we want to
			; leave the original variable value in place.

	clrw		; Set W = 0.  	

	call	add	; A subroutine call.  Why not?

	movwf	sum	; Move the contents of W into address SUM.
			; Since we returned from the subroutine with the
			; sum of the array elements in W, we can just
			; move what's in W into the address SUM.  Had
			; we performed other instructions in the
			; subroutine that changed W, this wouldn't have
			; been so easy.

finish	goto	finish	; Here's our "HALT" statement again.

;***********************************************************************
; Here's the subroutine.  Operation will continue in this block of code
; until the RETURN instruction is executed, at which point the program
; will return to the line following the subroutine CALL.
;***********************************************************************

add	addwf	INDF,w	; Indirect addressing works as follows:
			; 1. Look in FSR.  The value that you find there
			;    is not the operand, but an address.
			; 2. Look in the address whose value was found
			;    in FSR.  The value that you find there is
			;    the operand.

	decfsz	count,f	; COUNT = COUNT - 1.  Note that the decremented
			; value of COUNT is returned to address COUNT.
			; That way, each successive decrement will
			; operate on the same value, until it hits zero.
	
	goto	update	; If COUNT ~= 0, this line gets executed.  When
			; COUNT ~=  0, it means that we haven't finished
			; adding up all the array elements.  We need to
			; update FSR and go back to the top of the loop.

	return		; If COUNT = 0, this line gets executed.  When
			; COUNT = 0, it means that we have finished
			; adding all of the array elements.  We need to
			; go back to the main routine and store the
			; result

update	incf	FSR,1	; FSR = FSR + 1.  Note that the incremented
			; value of FSR is returned to address FSR.  That
			; way, each successive increment will operate on
			; the same value.  The next indirectly addressed
			; instruction will end up taking the value in
			; the next consecutive address.

	goto	add	; With FSR updated, we have to run the summing
			; loop again.

;***********************************************************************
; The last line of executable code must be followed with the END
; statement.
;***********************************************************************

	end
