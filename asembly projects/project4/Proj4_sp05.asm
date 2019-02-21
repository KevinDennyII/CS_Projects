	list P=16F84
	include	P16F84.INC

; Define the direction bit types
f	equ	1
w	equ	0
status equ 3
coinreturn	equ	1	;coin return button set bit1
penny		equ	2	;inserting a penny sets bit2 
nickel		equ	3	;inserting a nickel sets bit3
dime		equ	4	;inserting a dime sets bit4
quarter		equ	5	;inserting a quarter sets bit5
enough		equ	0x37	;current cost of a coke is $0.55
						;change this value if needed

;Define memory areas for output
			org 0x10
allreturn	res	1	;write 0xFF to this location to return all coins
somereturn	res	1	;write 0x01 to return a nickel, 0x02 to return a dime
releasecoke	res	1	;write 0xFF to this location to dispense a coke

; Define the data storage locations
; these definitions at 0x20 are supplied to the user and must not be modified
			org	0x20
totalcoins	res	1	;the total amount of coins inserted thusfar (cents)
change		res 1	;the amount of change to be returned (cents)
inttempw	res 1	;a location to hold w during int service routine
tempw		res 1	;a location to hold w temporarily
tencount	res	1	;hold count for output timing
inval		res 1	;the last velocity value read (m/s)
semaphore	res	1	;an indicator that a new velocity value has been loaded into inval

; do not change this section
; start defining the program
; jump around the interrupt handler return to the main program
	org	0x0
start	bsf	INTCON,GIE		;enable interrupts
		bsf	INTCON,INTE		;enable interrupts
		clrf	semaphore	;clear local signally variable
		goto	main

; handler is supplied to the user
; it reads a 4-bit value from PORTB and stores it in location
; "inval"
; in this assignment, we are assuming that at least ~200 hundred
; cycles passes between interrupts
; do not modify the handler code
	org 0x4
handler	nop
		movwf	inttempw	;temporaily store current w during interrupt
		movf	PORTB,w		;get pin values
		andlw	0xFE		;zero out low order bit (INT pin)
		movwf	inval		;put the pin values in inval
		bsf		semaphore,0	;indicate that new pin values are avilable
		movf	inttempw, w	;restore the old value of w
		bcf		INTCON,INTF	;re-enable interrupts
		bcf		PORTB, 0
		retfie				;return to the instruction at which the int occured
; end of section not to change

; beginning of the "real" program
; start by clearing all working values to 0
	org 0x100
main	clrf	totalcoins
;		the program sits in this loop waiting for interrupts
;		when a new input value is available, semaphore is set to 1
loop	btfss	semaphore,0
		goto	loop
;		at this point, the location "inval" will have the last
;       5-bit value read from port B
;		this 5-bit values represents the coins input
		bcf		semaphore,0

;		STUDENT SUBROUTINES SHOULD BE INSERTED HERE
;		
		call	compcoins

;       end of student subroutines, return to the loop waiting for the next interrupt
		goto	loop

; Compute the value of the coins inserted and determine whether or not to 
;dispense a soda and/or give change

compcoins	btfsc inval,5	;test the 5 bits of inval to see which coin is
		goto SetQ	;inserted or if return is pressed
		btfsc inval,4
		goto SetD
		btfsc inval,3
		goto SetN
		btfsc inval,2
		goto Return
		btfsc inval,1
		goto Return
		goto Add

SetQ		movlw 0x19	;quarter added
		goto Add

SetD		movlw 0x0A	;dime added
		goto Add

SetN		movlw 0x05	;nickel added


Add		addwf totalcoins, 1	;add inserted coin to totalcoins
		movf totalcoins,0	;totalcoins - 37
		sublw 0x37
		btfsc STATUS,Z		;if 0 Enough
		goto TestE		;else totalcoins is less then or more than

Enough		movlw 0xFF		;you have enough
		movwf releasecoke
		return


TestE		movf totalcoins,0	;test to see if totalcoins is less than
		sublw 0x37		;or greater than
		btfsc STATUS,C
		return
		goto Tomuch



Tomuch		call Enough
		sublw 0x0A
		btfsc STATUS,C
		goto changeN
		goto changeD

changeN		movlw 0x01
		movwf somereturn
		call count2ten
		return

changeD		movlw 0x14
		movwf change
		call count2ten
		clrf change
		movlw 0x14
		movwf change
		call count2ten
		return

Return		movlw 0xFF
		movwf allreturn
		return

;
;
;
;This routine delays for about 20 instruction cycles
count2ten	movlw	0x09
			movwf	tencount
again		decfsz	tencount
			goto	again
			return
;


		end

