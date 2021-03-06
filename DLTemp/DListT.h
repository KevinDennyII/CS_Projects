// Project Minor 1 for CS 2604 Fall 2005
//
// Programmer:	Kevin Denny
// OS:		Mac OS X
// System:	
// Compiler: 	
// Last Modified: Septmenber 1, 2005
//
// Purpose:
// The purpose of this program is to implement a doubly linked list using iterators
// and constant iterators to traverse through the list and carry out task.
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

// DListT.h
// This version uses fore and aft sentinel nodes.
#ifndef DLISTT_H
#define DLISTT_H
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
using namespace std;

#include "DNodeT.h"

template <typename T> class DListT {
	friend class Javert;
private:
   DNodeT<T>* Head;   // handle on first data node
   DNodeT<T>* Tail;   // handle on last data node
   DNodeT<T>* Fore;   // handle on leading sentinel node
   DNodeT<T>* Aft;    // handle on trailing sentinel node

public:
   DListT();                                        // make empty list
   DListT(const DListT<T>& Source);                 // deep copy support
   DListT<T>& operator=(const DListT<T>& Source);
   ~DListT();                                       // deallocate all nodes

   bool isEmpty() const;                 // true iff list has no data nodes
   void Clear();                         // restore list to empty state

   void Display(ostream& Out) const;     // display formatted contents

////////////////////////////////////////// iterator
//class DListT<T>::iterator;
#include "iterator.h"
   
////////////////////////////////////////// const_iterator
//class DListT<T>::const_iterator;
#include "const_iterator.h"   
 

   iterator begin();               // return iterator to head node,
                                   //   if any, else return end()
   iterator end();                 // return iterator to trailing sentinel

   const_iterator begin() const;   // analagous to previous functions
   const_iterator end() const;

   // if iterator It targets a data node or the trailing sentinel,
   // insert data value preceding target of iterator
   // otherwise, behavior is undefined
   iterator Insert(iterator It, const T& Elem) throw (range_error);

   // if value Elem occurs in list, return iterator to first node
   //   holding the value
   // otherwise, return end()
   iterator Find(const T& Elem);

   // if value Elem occurs in list, return const_iterator to first node
   //   holding the value
   // otherwise, return end()
   const_iterator Find(const T& Elem) const;

   // if target of iterator is not a sentinel, delete the node
   // otherwise, throw exception
   void Delete(iterator It) throw (range_error);
};

// implementations of template member functions follow...
/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for DListT class.

Parameters:	none
Pre:		none
Post:		Node pointers set to NULL
*/
template <typename T>
DListT<T>::DListT()
{
	Head = 	Tail = NULL; // intializing head & tail to null
	
	Fore = new DNodeT<T>;//creating new object for fore
	Aft = new DNodeT<T>;//creating new object for fore
	
	Fore->Prev = Fore;//beginning sentinel pointer that points to its self
	Fore->Next = Aft;//pointer from begin sentinel to end setinel for empty list
	
	Aft->Prev = Fore;//a setinel pointer that points to its self
	Aft->Next = Aft;//pointer from end setinel to begiin setinel for empty list

}

/*COPY CONSTRUCTOR for DListT class.
.
Parameters:	const DListT<T>& Source
Pre:		none
Post:		a deep copy of the list
*/
template <typename T>
DListT<T>::DListT(const DListT<T>& Source)
{
	Head = Tail = NULL;

	Fore = new DNodeT<T>;//creating new object for forer;
	Aft = new DNodeT<T>;//creating new object for fore
	
	Fore->Prev = Fore;//beginning sentinel pointer that points to its self
	Fore->Next = Aft;//pointer from begin sentinel to end setinel for empty li
	
	Aft->Prev = Fore;//a setinel pointer that points to its 
	Aft->Next = Aft;//pointer from end setinel to begiin setinel for empty list
						      
	//setting the iterator to its beginning
	const_iterator Curnode = Source.begin();

	//checking to make sure interator is not at the end and
	//inserting node into "this" then updating the node
	while(Curnode != Source.end())
	{
		Insert(this->end(), *Curnode);
		Curnode++;
	}
	
	if(!isEmpty())
	{
		Head = Fore->Next;
		Tail = Aft->Prev;
	}
}

/*ASSIGNMENT OPERATOR for DListT class.

Parameters:	const DListT<T>& Source
Pre:		none
Post:		DListT can now be overloaded
*/
template <typename T>
DListT<T>& DListT<T>::operator=(const DListT<T>& Source)
{
	Head = Tail = NULL;
	if(this != &Source)
	{
		const_iterator Curnode = Source.begin();
		while(Curnode != Source.end())
		{
			Insert(this->end(), *Curnode);
			Curnode++;
		}
		if(!isEmpty())
		{
			Head = Fore->Next;
			Tail = Aft->Prev;
		}
	}
	return(*this);

}

/////////////////////////////////////////////////////////
//                ****DECONSTRUCTOR****
//
//
//
//
template <typename T>
DListT<T>::~DListT()
{

	if ( Head == NULL)
		return;
	DNodeT<T>* destroy = Head; // temporary pointer for Head
	//deleting objects of the list until the head is NULL meaning the list
	//is empty
	while(destroy != Aft)
	{
		Head = Head->Next;
		delete destroy;
		destroy = Head;
	}
	
}

/*isEmpty() - returns a bool if the list is empty
Parameters:	none
Pre:		to know that list is empty
Post:		returns true to show list is empty else false
*/
template <typename T>
bool DListT<T>::isEmpty() const
{
	return(Fore->Next==Aft);
}

/*Clear() - deletes all nodes except sentinels, head and tail to empty the list
Parameters:	none
Pre:		none
Post:		list a is now empty
*/
template <typename T>
void DListT<T>::Clear()
{
	if ( Head == NULL)
		return;
	DNodeT<T>* destroy = Head; // temporary pointer for Head
	//deleting objects of the list until the head is NULL meaning the list
	//is empty
	while(destroy != Aft)
	{
		Head = Head->Next;
		delete destroy;
		destroy = Head;
	}

	//returning pointers back to NULL
	Head = Tail = NULL;
	Fore->Next = Aft;
	//Fore->Prev = Fore;
	Aft->Prev = Fore;
	
}

/*Display() - to display output of list
Parameters:	ostream& Out
Pre:		none
Post:		none
*/
template <typename T>
void DListT<T>::Display(ostream& Out) const
{
	DNodeT<T>* currPtr = Head;  // pointer for use of loop
	
	if(Head == NULL)
		return;
	// goes through each node and dispalys contents then move pointer
	// to the next node
	while (currPtr != Aft)
	{
		Out<< currPtr->Element <<endl;
		currPtr = currPtr->Next;
	}
}
/*begin() - basically has the iterator pointing at Head
Parameters:	none
Pre:		none
Post:		returns iterator to the Head
*/
template <typename T>
typename DListT<T>::iterator DListT<T>::begin()
{
	iterator It(Fore->Next);
	return It;
}

/*end() - basically has the iterator pointing at Tail
Parameters:	none
Pre:		none
Post:		returns iterator to the Tail
*/
template <typename T>
typename DListT<T>::iterator DListT<T>::end()
{               
	// return iterator to trailing sentinel
	iterator It(Aft);
	return It;
	
}

/*begin() - same as other begin except the iterator is constant
Parameters:	none
Pre:		nonePost:		returns constant iterator to Head
*/
template <typename T>
typename DListT<T>::const_iterator DListT<T>::begin() const
{
	const_iterator It(Fore->Next);
	return It;
}

/*end() - same as other end except the iterator is constant
Parameters:	none
Pre:		none
Post:		returns constant iterator to Tail
*/
template <typename T>
typename DListT<T>::const_iterator DListT<T>::end() const
{               
	// return iterator to trailing sentinel
	const_iterator It(Aft);
	return It;
	
}

/*Insert() - inserts a new node 
Parameters:	iterator It, const T& Elem
Pre:		none
Post:		new node inserted otherwise undefined
*/
template <typename T>
typename DListT<T>::iterator DListT<T>::Insert(iterator It, const T& Elem) throw (range_error)
{
	// if iterator It targets a data node or the trailing sentinel,
	// insert data value preceding target of iterator
	// otherwise, behavior is undefinded

	//iterator Temp = new iterator(dum);// giving iterator pointer to node*/
	DNodeT<T>* newPtr;
	
	//if list is empty(meaning Head & Tail are NULL)
	//if current position is NULL)
	if((It.Position == NULL)||(It.Position == Fore))
	{
		throw(range_error("Position is emptry or is at the leading sentinel."));
	}

	//inserting node preceding the target node
	newPtr = new DNodeT<T>(Elem, It.Position->Prev, It.Position);
	It.Position->Prev->Next =  newPtr;
	newPtr->Next = It.Position;
	newPtr->Prev = It.Position->Prev;
	It.Position->Prev = newPtr;
	
	Head = Fore->Next;
	Tail = Aft->Prev;
	return It;
}


/*Find() - searchese the DList using an iterator to find a specified node 
 * Parameters:     const T& Elem
 * Pre:            none
 * Post:           returns iterator to first node holding the element value if found, else return end()
 * */
template <typename T>
typename DListT<T>::iterator DListT<T>::Find(const T& Elem) 
{
	//bool found;
	iterator Searcher; // iterator created to traverse through list

	//traversing through the list
	for(Searcher = begin(); Searcher != end(); Searcher++)
	{
		//found = false;
		//if element is found return address of element
		if((*Searcher) == Elem)
		{
			//found = true;
			//Searcher.Position->Element = Key->Element;
			cout<<*Searcher<<endl;
			return(Searcher);
		}

		//cout<<"Element not found."<<endl;
		
	}
	cout << "Element not found " <<endl;	
	Searcher = end();//creating pointer for end();
	return(Searcher);
}

/*Find() - searchese the DList using a const_iterator to find a specified node
* Parameters:     const T& Elem
* Pre:            none
* Post:           returns const_iterator to first node holding the element value if found, else return end()
* */
template <typename T>
typename DListT<T>::const_iterator DListT<T>::Find(const T& Elem) const
{
	//bool found;
	const_iterator Searcher;
	
	//same as above find function
	for(Searcher = begin(); Searcher != end(); Searcher++)
	{
		// found = false;
		if((*Searcher) == Elem)
		{
			//found = true;
			 //Key->Element = Searcher.Position->Element;
			cout<<*Searcher<<endl;

			return(Searcher);
		}

	}
	Searcher = end();
	return(Searcher);
}

/*Delete() - deletes specified node from the DList
 * Parameters:     iterator It
 * Pre:            none
 * Post:           deletes node and reappoints the pointer effected, if position is empty or pointin at sentinel throws an exception
 * */

template <typename T>
void DListT<T>::Delete(iterator It) throw (range_error)
{
	//temporary nodes to keep track of the next ptr of the previous node,
	//a ptr for the current node, and prev ptr of the next node
	DNodeT<T>* Temp1;//
	DNodeT<T>* Temp2;//
	DNodeT<T>* Temp3;// 
	
	//chekcking for empty node or if pointer is at fore or aft
	if((It.Position == NULL) || (It.Position == Fore) || (It.Position == Aft))
	{
		throw(range_error("Can not delete. Node is NULL or pointing to leading or trailing sentinel."));
		
	}


	//if asked Delete anywhere in list
	Temp1 = It.Position;// temporary pointer is current pointer
	It--;//move position to previous node
		
	Temp2 = It.Position;//reestablishing current pointer
	It++;
		
	It++;//move to one past the current position It is at

	Temp2->Next = It.Position;
		
	Temp3 = It.Position;
		
	Temp3->Prev = Temp2;

	// if list is empty head is null else fore setinel points to head
	if(Fore->Next == Aft)
	{
		Head = NULL;
	}
	else
		Head = Fore->Next;

	//if list is empty tail is null else aft setinel points to tail
	if(Aft->Prev == Fore)
	{
		Tail = NULL;
	}
	else
		Tail = Aft->Prev;

	delete Temp1;//deleting node
}

#endif
