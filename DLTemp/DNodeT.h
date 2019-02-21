// Project Minor 1 for CS 2604 Fall 2005
//
// Programmer:  Kevin Denny
// OS:          Mac OS X
// System:      
// Compiler:    
// Last Modified: September 1, 2005
//
// Purpose:
// The purpose of this program is to implement a doubly linked list using iterators
// and constant iterators to traverse through the list and carry out task.

//
#ifndef DNODET_H
#define DNODET_H
#include <iostream>
using namespace std;

template <typename T> class DNodeT {
public:
   T          Element;
   DNodeT<T>* Prev;
   DNodeT<T>* Next;

   DNodeT();
   DNodeT(const T& Elem, DNodeT<T>* P=NULL, DNodeT<T>* N=NULL);
   ~DNodeT();
};

// implementations of template member functions follow...
/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//                     
//
/*DEFAULT CONSTRUCTOR for DNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>
DNodeT<T>::DNodeT()
{
}

/*CONSTRUCTOR for DNodeT class.

Parameters:	const T& Elem, DNodeT<T>* P, DNodeT<T>* N
Pre:		none
Post:		pointer P & N are set to NULL.
*/
template <typename T>
DNodeT<T>::DNodeT(const T& Elem, DNodeT<T>* P, DNodeT<T>* N)
{
	//setting pointers to NULL
	Element = Elem;
	Prev = P;
	Next = N;
}
/////////////////////////////////////////////////////////
//                ****DECONSTRUCTOR****
//                     
//
/*CONSTRUCTOR for DNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>
DNodeT<T>::~DNodeT()
{
	cout << "deleting node holding " << Element <<endl;
	  
}
#endif
