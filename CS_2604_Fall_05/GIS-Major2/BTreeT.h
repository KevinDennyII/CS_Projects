// Project Major 2 for CS 2604 Fall 2005
//
// Programmer:	Kevin Denny
// OS:		OS X Tiger
// System:	1.33ghz powerpc G4
// Compiler: 	Xcode 2.0
// Last Modified:	November 10, 2005
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
 
#ifndef BTreeT_H
#define	BTreeT_H
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <algorithm>
using namespace std;

#include "BNodeT.h"

template <typename T, int m> class BTreeT{
private:
   BNodeT<T,m>* Root;
   void TreeCopyHelper(BNodeT<T,m>*& TargetRoot, BNodeT<T,m>* SourceRoot); //helper function for deep copy support
   bool insertHelper(const T& D, BNodeT<T,m>*& sRoot, const T& E, bool& overflow); //helper function for insert
   bool deleteHelpler(const T& D, BNodeT<T,m>*& sRoot, const T& E, bool& underflow); //helper function for delete
   const T* const FindHelper(const T& toFind, BNodeT<T,m>* sRoot) const; // helper function for const Find
   T* const FindHelper(const T& toFind, BNodeT<T,m>* sRoot); //helper function for find
   void displayHelper(BNodeT<T,m>* sRoot, ostream& Out, unsigned int Level) const; // helper function for display fuction

public:
   BTreeT();                              // create empty BTreeT
   BTreeT(const T& D);                    // create one-node BTreeT with given data
   BTreeT(const BTreeT<T,m>& Source);     // deep copy support
   BTreeT<T,m>& operator=(const BTreeT<T,m>& Source);

   bool Insert(const T& D);               // insert data into new node
 
   bool Delete(const T& D);               // delete node with matching data

   T* const Find(const T& D);             // return pointer to matching data,
                                          //  or NULL if not found

   const T* const Find(const T& D) const; // same, but safe access
   void Display(ostream& Out) const;      // write formatted tree contents
   void Clear();                          // reset tree to empty state

   ~BTreeT();                             // destroy all tree contents

};

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for BTreeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T, int m>
BTreeT<T,m>::BTreeT()
{
	Root = NULL;
}

/*CONSTRUCTOR for BTreeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T, int m>
BTreeT<T,m>::BTreeT(const T& D)
{
	Root = new(nothrow) BNodeT<T,m>(D);
}

/*CONSTRUCTOR for BTreeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T, int m>
BTreeT<T,m>::BTreeT(const BTreeT<T,m>& Source)
{
	
}

//////////////////////////////////////////////////////////////// TreeCopyHelper()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
void BTreeT<T,m>::TreeCopyHelper(BNodeT<T,m>*& TargetRoot, BNodeT<T,m>* SourceRoot)
{
	
}

//////////////////////////////////////////////////////////////// Insert()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
bool BTreeT<T,m>::Insert(const T& D)
{	
	T el; //variable for element being set
	bool overflow = false;
	
	//tree is empty
	if(Root == NULL)
	{
		cout << "Root is Null"<< endl;
		Root = new BNodeT<T,m>(D);
		cout << "Element: " << D << endl;
		return true;
	}
	
	cout << "going into inserthelper" << endl;
	//checkin' if insert is working
	if(!insertHelper(D, Root, el, overflow))
		return false;
	
	//root is null and grow new root
	if(overflow)
	{
		unsigned int middle = (m)/2;
		T mid = Root->keys[middle];
		Root = new BNodeT<T,m>(mid);
		
		//inserting new data
		if(D < mid)
		{
			Root->bptrs[0] = new BNodeT<T,m>(D);//left of element
		}
		else
			Root->bptrs[1] = new BNodeT<T,m>(D);//right of element
		
		int i=0;
		//restructing first half of the tree
		while(i < middle)
		{
			
			Root->bptrs[0] = new BNodeT<T,m>(Root->insert(Root->keys[i]));
			i++;
		}
		
		//restructuring second half of the tree
		int x =0;
		while(middle < m)
		{
			Root->bptrs[1] = new BNodeT<T,m>(Root->insert(Root->keys[x]));
			//middle++;
			x++;
		}
	}
	
}

//////////////////////////////////////////////////////////////// insertHelper()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
bool BTreeT<T,m>::insertHelper(const T& D, BNodeT<T,m>*& sRoot, const T& E, bool& overflow)
{	
	overflow = false;
	//leaf is full
	if(sRoot->isLeaf())
	{
		cout << "inside is leaf" << endl;
		if(!sRoot->isFull())
		{
			//cout << "able to insert " << D << " inside leaf" << endl;
			sRoot->insert(D);
			return true;
		}
		else
			return overflow;
	}
	
	cout << "before isFull check" << endl;
	//tree is full
	if(sRoot->isFull())
	{
		return true;
	}
}

//////////////////////////////////////////////////////////////// Delete()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
bool BTreeT<T,m>::Delete(const T& D)
{
	
}

//////////////////////////////////////////////////////////////// deleteHelper()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
bool BTreeT<T,m>::deleteHelpler(const T& D, BNodeT<T,m>*& sRoot, const T& E, bool& underflow)
{
	
}

//////////////////////////////////////////////////////////////// Find()const
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
const T* const BTreeT<T,m>::Find(const T& D) const
{
	return FindHelper(D, Root);
}

//////////////////////////////////////////////////////////////// FindHelper()const 
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
const T* const BTreeT<T,m>::FindHelper(const T& toFind, BNodeT<T,m>* sRoot) const
{
	
}

//////////////////////////////////////////////////////////////// Find()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
T* const BTreeT<T,m>::Find(const T& D)
{
	return FindHelper(D, Root);
}

//////////////////////////////////////////////////////////////// FindHelper()
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
T* const BTreeT<T,m>::FindHelper(const T& toFind, BNodeT<T,m>* sRoot)
{
	
}

//////////////////////////////////////////////////////////////// Dislpay()const
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
void BTreeT<T,m>::Display(ostream& Out) const
{
	displayHelper(Root, Out, 0);
}

//////////////////////////////////////////////////////////////// displayHelper()const
// <Brief description of what the function does.>
//
// Parameters:
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T, int m>
void BTreeT<T,m>::displayHelper(BNodeT<T,m>* sRoot, ostream& Out, unsigned int Level) const
{
	if (Root == NULL) 
	{
		cout << "Your tree is empty."<<endl;
		return;
	}
	
	if (sRoot == NULL)
		return;
	

	
	//for loop to reach every index of node pointers	
	for(int i = 0; i < m; i++)
	{	
		if(sRoot->bptrs[i] != NULL)
		{
			displayHelper(sRoot->bptrs[i], Out, Level + 1); //recursive call display of nodes 
		}
		else
			cout << "pointing to NULL" << endl;
	}
	
	if( Level > 0 ) 
	{
		cout << setfill('-') << setw(3*Level) <<'-';
		
	}
	
	//for loop to display every element in the keys arrays
	for(int i = 0; i <(m-1); i++)
	{
			cout << "["<<i<<"]:"<< sRoot->keys[i] << endl;
			cout << setfill(' ');
	}
	//DisplayHelper(sRoot->Right, Out, Level + 1);
}

/////////////////////////////////////////////////////////
//                ****DECONSTRUCTOR****
//
//
template <typename T, int m>
BTreeT<T,m>::~BTreeT()
{
	
}
#endif
 

