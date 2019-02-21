// BIGNUM project for CS 2604 Spring 2006
//
// Programmer:	Kevin Denny
// OS:		OS X Tiger
// System:	1.33ghz powerpc G4
// Compiler: 	Xcode 2.0
// Last Modified:	January 29, 2006
//
// Purpose:
// 
//
//    On my honor:
//   
//    - I have not discussed the C++ language code in my program with
//      anyone other than my instructor or the teaching assistants
//      assigned to this course.
//   
//    - I have not used C++ language code obtained from another student,
//      or any other unauthorized source, either modified or unmodified. 
//   
//    - If any C++ language code or documentation used in my program
//      was obtained from another source, such as a text book or course
//      notes, that has been clearly noted with a proper citation in
//      the comments of my program.
//   
//    - I have not designed this program in such a way as to defeat or
//      interfere with the normal operation of the Curator System.
//
//    Kevin Denny, kdenny2

#ifndef CALCULATOR_HH
#define CALCULATOR_HH
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
using namespace std;

class calculator {

private:

public:

	void add();		//method for adding items
	void subtract();	//method for subracting items
	void divide();		//method for divididng items
	void multiply();	//method for multiplying items
	
	int getAdd();		//returns results for addition
	int getSub();		//returns results for subraction
	int getDiv();		//returns results for division
	int getMult();		//returns results for multiplication
	

};
#endif
