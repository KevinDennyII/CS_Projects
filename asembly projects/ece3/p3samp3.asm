;***********************************************************************
;	Program Name: Comparison (IF-THEN) Example
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

one	equ	0x11	; The address of the first value
two	equ	0x12	; The address of the second value

gflag	equ	0x13	; A "greater than" flag
lflag	equ	0x14	; A "less than" flag

;***********************************************************************
; The ORG statement means that the first line of the executable program
; code after the ORG statement will be placed in program memory location
; 0, and that successive instructions will be placed in the next
; consecutive program memory location.
;***********************************************************************

	org	0

;***********************************************************************
; All IF-THEN statements are comparisons.  Either the condition
; embodied by the IF matches the desired condition, in which case the
; THEN portion of the statement is executed, or it doesn't, in which
; case an ELSE portion of the statement is executed, if one exists.
;
; There are a lot of different ways that we can compare values; two
; useful ones are comparisons of magnitude (greater than or less than)
; and equality.  This example will compare magnitude with the help of
; the CARRY bit of the STATUS register.  A comparison of equality would
; work similarly, except that it might use the ZERO bit of the status
; register.
;***********************************************************************

start	clrw		; We start by setting W = 0.
	clrf	gflag	; Both flags are initialized to zero.
	clrf	lflag	

	movf	one,w	; The first value is moved into W.

	subwf	two,w	; The syntax of this instruction is "Subtract W
			; from F."  So here, we are performing the
			; operation [two] minus [one].  This is easy
			; to get confused, especially considering what
			; happens next.

;***********************************************************************
; STATUS register bits tell us things about what is happening as a
; a result of the operations that are executed.  Certain instructions
; can change certain bits of the STATUS register, and these conditions
; can be checked by looking at the appropriate STATUS register bit.
;
; Suppose that we want to know which of the two values is greater.  We
; can make that judgement on the following basis:
;
;	If [two] minus [one] > 0, then [two] > one.
;	If [two] minus [one] < 0, then [two] < one.
;
; Normally, the CARRY bit works by indicating whether the result of an
; add operation included a carry-out of the most significant bit.  If
; C = 0, no carry occurred, and if C = 1, a carry occurred.
;
; In the case of subtraction, this is *reversed*.  The CARRY bit now
; becomes a BORROW bit.  But, if B = 1, *no borrow* occurred, while if
; B = 0, a borrow did occur.  With all of this in mind, we can make the
; following conclusion.
;
; 	If [two] > [one], no borrow occured (since the result of the
;       subtraction was positive) and B = 1.
;
;	If [two] < [one], a borrow occurred (since the result of the
;	subtraction was negative) and B = 0.
;
;
; Since we're working with a STATUS bit that records CARRY and BORROW
; events, it's worth noting that if [two] = [one], then no borrow
; occures, and B = 1.
;
; Now, since the subtraction occurred in the previous instruction, all
; we have to do is test the CARRY bit (in its capacity as a BORROW bit)
; to see what happened.
;***********************************************************************

;***********************************************************************
; All of this means that the IF statement is: If [two] >= [one]
;***********************************************************************

	btfsc   STATUS,C

	goto	tbigo	; If C is not clear, we don't skip.  That means
			; that [two] >= [one]. This is the THEN.
	goto	obigt	; If C is clear, we skip the previous line and
			; execute this one.  That means that [two] <
			; [one]. This one is the ELSE.

;***********************************************************************
; Now, whatever happens happens, because the routines TBIGO and OBIGT
; contain the two pieces of code that we might want to run for the two
; separate conditions.
;***********************************************************************

tbigo	incf	gflag,1	; We can make any indication that we want to the
			; flag to show that a given condition has been
			; satisfied.
	goto	finish	; Note that the conditions are mutually
			; exclusive.

obigt	incf	lflag,1	
finish	goto	finish	; Halt execution

;***********************************************************************
; One last thing worth noting is that the order of the conditions after
; the bit test indicate which is the THEN and which is the ELSE.  If you
; want to switch the condition being tested, just switch the order of
; the statements, or the type of bit test being executed, i.e, we could
; have also performed a bit-test-set (BTFSS).
;***********************************************************************

;***********************************************************************
; The last line of executable code must be followed with the END
; statement.
;***********************************************************************

	end
