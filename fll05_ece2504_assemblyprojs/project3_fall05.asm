;***********************************************************************
;	Project 3 ECE 2504 Fall 05
;	Programmer: Kevin Denny
;	28 November 2005
;	2504 Class Software Project 3
;***********************************************************************


	list P=16F84
	include	P16F84.INC
;***********************************************************************
; Define the direction bit types
;***********************************************************************

f	equ	1	; store the result in f
w	equ	0	; register - store the result in w
n	equ 0x10


one	equ	0x21
two	equ	0x31
sum	equ	0x41	 

	org	0
	
start	clrw
		clr 0x41
		clr	0x42
		clr	0x43
		clr	0x44
		clr	0x45
		clr	0x46
		clr	0x47
		clr	0x48
		clr 0x49
		
	addwf	one,w
	
	addwf	two,w
	
	movwf	sum,w

	end

