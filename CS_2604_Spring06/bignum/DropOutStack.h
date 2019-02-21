// Programmer:  Kevin Denny
// Last Modified:  February 16, 2005
// Compiler:        Eclipse 3.0.1
//
#ifndef DROPOUTSTACK_H 
#define DROPOUTSTACK_H 

#include <iostream> 
#include <iomanip> 
#include <new>

#include "Item.h" 

using namespace  std;

enum ErrorType { NO_ERROR, STACK_UNDERFLOW, STACK_OVERFLOW };

class DropOutStack 
{
    
    // Drop-Out Stack Data Type
    // a stack variant that modifies the standard stack push() operation
    // so that the bottom element in the stack is dropped out (lost)
    // if the stack is full.

  friend class  Javert;

  private:
    Item* stk;            //pointer to stack array
    unsigned int cap;     //capacity (dimension) of stack array
    unsigned int top;     //index for next push 
    unsigned int usage;    //# of elements stored 
    ErrorType LastError;  //indicates last error detected

  public:
    DropOutStack(unsigned int capacity=0);    //Default constructor
    DropOutStack(const DropOutStack& source); //Copy constructor 
    DropOutStack& operator=(const DropOutStack& rhs); //Assignment operator

    bool push(const Item& elem);      //insert Elem at Top
    bool pop(Item& elem);             //remove top-most element and return it
    Item* const peek() const;         //provide access to top-most element
    void clear();                     //reset stack to empty state

    bool isEmpty() const;             //check for empty stack
    //bool isFull() const;            //check for full stack Do NOT implement
    ErrorType getError() const;       //return error state
    unsigned int capacity() const;    //report stack capacity
    unsigned int size() const;        //report stack usage

    void display(ostream& out) const; //display stack contents

    ~DropOutStack(); //Destructor 
};
#endif 

//  On my honor:
//    
//    - I have not discussed the C++ language code in my program with
//   anyone other than my instructor or the teaching assistants 
//     assigned to this course.
//  
//    - I have not used C++ language code obtained from another student, 
//   or any other unauthorized source, either modified or unmodified.  
//    
//    - If any C++ language code or documentation used in my program 
//   was obtained from another source, such as a text book or course
//     notes, that has been clearly noted with a proper citation in
//    the comments of my program.
//   
//    - I have not designed this program in such a way as to defeat or
//      interfere with the normal operation of the Curator System.
//
//    - I have neither given nor received unauthorized aid in the
//   completion of this assignment.
//
//      Kevin Denny, kdenny2@vt.edu
