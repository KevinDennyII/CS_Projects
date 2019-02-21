#ifndef DROPOUTSTACKT_H 
#define DROPOUTSTACKT_H 
#include <iostream> 
#include <iomanip> 
#include <new> 
#include <stdexcept> 
using namespace  std;
template <typename T> class DropOutStackT 
{
    // Drop-Out Stack Data Type
    // a stack variant that modifies the standard stack push() operation
    // so that the bottom element in the stack is dropped out (lost)
    // if the stack is full.

  friend class  Javert;

  private:
    T* stk;               //pointer to stack array
    unsigned int cap;     //capacity (dimension) of stack array
    unsigned int top;     //index for next push 
    unsigned int usage;   //# of elements stored 

  public:
    DropOutStackT(unsigned int capacity=0);    //Default constructor
    DropOutStackT(const DropOutStackT<T>& source); //Copy constructor 
    DropOutStackT<T>& operator=(const DropOutStackT<T>& rhs); //Assignment operator

    bool push(const T& elem);      //insert Elem at Top
    bool pop(T& elem);             //remove top-most element and return it
    T* const peek() const;         //provide access to top-most element
    void clear();                     //reset stack to empty state

    bool isEmpty() const;             //check for empty stack
    unsigned int capacity() const;    //report stack capacity
    unsigned int size() const;        //report stack usage
	
	void Display(ostream& out);

    //display stack contents
    friend ostream& operator<<(ostream& out, const DropOutStackT<T>& source); 
    ~DropOutStackT(); //Destructor 
};


// import template implementation code:
#include "DropOutStackT.cpp"

#endif
