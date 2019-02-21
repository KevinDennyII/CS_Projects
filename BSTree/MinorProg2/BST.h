// Project Minor 2 for CS 2604 Fall 2005
//
// Programmer:	Kevin Denny
// OS:		OS X Tiger
// System:	1.33ghz powerpc G4
// Compiler: 	Xcode 2.0
// Last Modified:	October 1, 2005
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
#ifndef BST_HH
#define BST_HH
#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
using namespace std;

#include "BinNodeT.h"

template <typename T> class BST {
private:
   BinNodeT<T>* Root;                     // access to root node, if any		  
   T LeftMost(BinNodeT<T>* sRoot); //finds the left most node
   void TreeCopyHelper(BinNodeT<T>*& TargetRoot, BinNodeT<T>* SourceRoot); //helper function for copy constructor
   bool InsertHelper(const T& D, BinNodeT<T>*& sRoot);// helper function for 
   bool DeleteHelper(const T& D, BinNodeT<T>*& sRoot);//secure.hosting.vt.edu/www.erc.vt.edu/div&access.htm/ helper function for delete
   const T* const FindHelper(const T& toFind, BinNodeT<T>* sRoot) const; // helper function for const Find
   T* const FindHelper(const T& toFind, BinNodeT<T>* sRoot); //helper function for find
   BinNodeT<T>* Locate(const T& D, BinNodeT<T>* sRoot); // function locate exact location of element in tree
   BinNodeT<T>* LeftMostN(BinNodeT<T>* sRoot);
   void DisplayHelper(BinNodeT<T>* sRoot, ostream& Out, unsigned int Level) const; //helper for dislpay
   void ClearHelper(BinNodeT<T>* sRoot);	//helper function for clear
   // . . . the rest is up to you . . .

public:
   BST();                                 // create empty BST
   BST(const T& D);                       // create one-node BST with given data
   BST(const BST<T>& Source);             // deep copy support
   BST<T>& operator=(const BST<T>& Source);

   bool Insert(const T& D);               // insert data into new node
 
   bool Delete(const T& D);               // delete node with matching data

   T* const Find(const T& D);             // return pointer to matching data,
                                          //  or NULL if not found

   const T* const Find(const T& D) const; // same, but safe access
   void Display(ostream& Out) const;      // write formatted tree contents
   void Clear();                          // reset tree to empty state

   ~BST();                                // destroy all tree contents

   friend class Monk;                     // give the test harness access
 };

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for BST class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>  
BST<T>::BST()
{
	Root = NULL;
} 

/*CONSTRUCTOR for BST class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>  
BST<T>::BST(const T& D)
{
	Root = new(nothrow) BinNodeT<T>(D);
} 


/*COPY CONSTRUCTOR for BST class.

Parameters:	const BST<T>& Source
Pre:		none
Post:		tree structure with nodes and data copied
*/
template <typename T>  
BST<T>::BST(const BST<T>& Source)
{	

	if(Source.Root == NULL)
	{
		Root = NULL;
	}
	else
		TreeCopyHelper(Root,Source.Root);  
	
} 

//////////////////////////////////////////////////////////////// TreeCopyHelper()
// Creates a copy of the BST by copying the source(the orignal tree) to a target(the exact copy of the source tree)
//
// Parameters:	BinNodeT<T>* TargetRoot, BinNodeT<T>* SourceRoo
//
// Pre:       	checks to see if tree is empty, then if not empty if each subRoot has a children or a child and
//		copies that data
//
// Post:      	tree is copied
//
// Returns:  	exact copy of BST
//
// Called by: 	BST Copy Constructor(BST())
// Calls:   	TreeCopyHelper
template <typename T>
void BST<T>::TreeCopyHelper(BinNodeT<T>*& TargetRoot, BinNodeT<T>* SourceRoot)
{
	// if tree is empty
	if(SourceRoot == NULL)
	{
		TargetRoot = NULL;
		return;
	}
		
	else
		TargetRoot = new(nothrow) BinNodeT<T>(SourceRoot->Element);
		TreeCopyHelper(TargetRoot->Left, SourceRoot->Left);
		TreeCopyHelper(TargetRoot->Right, SourceRoot->Right);
}

/*ASSIGNMENT OPERATOR for BST class.

Parameters:	const BST<T>& Source
Pre:		checks for null, else use treecopyHelper
Post:		equals operator assigned
returns:	this
Calls:   	TreeCopyHelper()
*/
template <typename T>           
BST<T>& BST<T>::operator=(const BST<T>& Source)
{
	if(this != &Source)
	{
		if(Source.Root == NULL)
		{
			Root = NULL;
		}
		else
			TreeCopyHelper(Root,Source.Root);
	}
	return( *this ); 
}

//////////////////////////////////////////////////////////////// Insert()
// Client is able to insert a node into the BST by calling this function
//
// Parameters:	D, Root
//ttps:
// Pre:       	none
//
// Post:      	node inserted
//
// Returns:   	call to the InsertHelper function
//
// Called by: 	none
// Calls:     	InsertHelper()
template <typename T> 
bool BST<T>::Insert(const T& D)
{
	return InsertHelper(D, Root);
}

//////////////////////////////////////////////////////////////// InsertHelper()
// This function serves as a helper to the insert. Compares element being passed in, to the parent node of what is 
// to become the new child to be created to determine if will be the right of left of the parent.
//
// Parameters:	const T& D, BinNodeT<T>*& sRoot
//
// Pre:      none	 
//
// Post:      new node has been inserted after Insert() is called
//
// Returns:   returns a bool for true if a node is able to be inserted and false for a node not able to be inserted
//
// Called by: Insert()
// Calls:     InsertHelper()
template <typename T>
bool BST<T>::InsertHelper(const T& D, BinNodeT<T>*& sRoot)
{
	// checking for the value to be equal
	// if ((current->Left != NULL && current->Left->Element == D)
	//	 || current->Right != NULL && current->Right->Element == D)
	
	// if root points to NULL creat new child node
	if (sRoot == NULL)// found the location
	{
		BinNodeT<T>* Temp = new(nothrow) BinNodeT<T>(D);
		if (Temp == NULL) //checking for data that doesnt not exist
			return false;
		sRoot = Temp;
		return true;
	}
	//creating new left node recursively
	else if((sRoot->Element) > D)
	{
		InsertHelper(D, sRoot->Left);
		return true;
	}
	
	//creating new right node recursively
	else if((sRoot->Element) < D)
	{
		InsertHelper(D, sRoot->Right);
		return true;
	}

	else
	 	return false;

}

//////////////////////////////////////////////////////////////// Delete()
// Client is able to delete a node into the BST by calling this function
//
// Parameters:	const T& D
//
// Pre:       checks for empty tree
//
// Post:      node is delete
//
// Returns:   returns false if tree is empty else, DeleteHelper() which is a bool
//
// Called by: none
// Calls:     DeleteHelper()
template <typename T>           
bool BST<T>::Delete(const T& D)
{
	if ( Root == NULL )
		return false;
	
	return DeleteHelper(D, Root);
		
}  

//////////////////////////////////////////////////////////////// DeleteHelper()
// <Brief description of what the function does.>
//
// Parameters:	ostream& Out
//
// Pre:       
//
// Post:      
//
// Returns:   Describe what value the function returns, if any.
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     
template <typename T>
bool BST<T>::DeleteHelper(const T& D, BinNodeT<T>*& sRoot)
{
	//if tree is empty
	if(sRoot == NULL)
		return false;
	
	
	//checking to see if element is the right side of the tree
	//or if element is in the left side of the tree		
	if(sRoot->Element < D)
		return DeleteHelper(D, sRoot->Right);
	else if(sRoot->Element > D)
		return DeleteHelper(D, sRoot->Left);
		
	// node is a leaf
		if(sRoot->isLeaf() == true)
		{ 
			if(sRoot == Root)
			{	
				delete Root;
				Root = NULL;
				return true;
			}
			delete sRoot;
			sRoot= NULL;
			return true;
		}
		// if node has two children
		else if((sRoot->Left != NULL) && (sRoot->Right != NULL))
		{
		
			if(sRoot->Right->Left != NULL)
			{	
				//T Swapper = LeftMost(sRoot->Right); //settin swapper to left most node
				BinNodeT<T>* Swapper = LeftMostN(sRoot->Right);//Left Most Node function
				cout<<Swapper->Element<<endl;
				//sRoot->Element = Swapper; //switching data
				Swapper->Left = Root->Left;//resetting root left or left subtree
				Swapper->Right = Root->Right;//resetting root right or right subtree
				delete Root;//deleting root
				Root = Swapper;//reassigning root
				
			}
			else
			{
				BinNodeT<T>* Swapper = sRoot->Right;
				DeleteHelper(Swapper->Element, sRoot->Right);
				sRoot = Swapper;
			}

			    // repaired after delete for node
				return true;
		}
	
		//if node has one child
		else if(sRoot->Left != NULL)
		{
			if(sRoot == Root)
			{	
				//BinNodeT<T>* Temp = new(nothrow) BinNodeT<T>(D);// temp node pointing to root
				Root = Root->Left;//swapping root and root left for deletion
				Root->Left=NULL;
				delete Root->Left;
				
				return true;
			}
			else
			{
				sRoot = sRoot->Left; //switching parent node pointer of sRoot to point to sRoot's left
				delete sRoot->Left; //deleting  node
				sRoot->Left = NULL;
				return true;
			}
		}
		else if(sRoot->Right != NULL)
		{
			if(sRoot == Root)
			{	
				Root = Root->Right;//swapping root and root left for deletion
				//delete sRoot;//delete root
				//Root->Right = sRoot->Right->Right;
				Root->Right = NULL;
				delete Root->Right;
				return true;
			}
			else
			{
				
				sRoot = sRoot->Right;//switching parent node pointer of sRoot to point to sRoot's right
				delete sRoot->Right; //deleting node
				sRoot->Right = NULL;
				return true;
			}
		}
	
		else
			return false;
}

//////////////////////////////////////////////////////////////// LeftMost()
// Traverses through the tree to find the left most node 
//
// Parameters:	BinNodeT<T>* sRoot
//
// Pre:       none
//
// Post:      left most node is found
//
// Returns:   return pointer to subRoot or left most node
//
// Called by: DeleteHelper()
// Calls:     Leftmost()
template <typename T>
T BST<T>::LeftMost(BinNodeT<T>* sRoot)
{
	if(sRoot->Left->Left != NULL)
	{
		return LeftMost(sRoot->Left);
	}
	else {
		
		T Value = sRoot->Left->Element;//setting parents left node to value
		BinNodeT<T>* temp = sRoot->Left;//creating temp for deletion
		sRoot->Left = sRoot->Left->Right; //swapping parent with child's right
		delete temp;//deleting node
		return Value;//holding value 
	
	}
}

//////////////////////////////////////////////////////////////// LeftMost()
// Traverses through the tree to find the left most node 
//
// Parameters:	BinNodeT<T>* sRoot
//
// Pre:       none
//
// Post:      left most node is found
//
// Returns:   return pointer to subRoot or left most node
//
// Called by: DeleteHelper()
// Calls:     Leftmost()
template <typename T>
BinNodeT<T>* BST<T>::LeftMostN(BinNodeT<T>* sRoot)
{
	if(sRoot->Left->Left != NULL)
	{
		return LeftMostN(sRoot->Left);
	}
	else {
		
		//T Value = sRoot->Left->Element;//setting parents left node to value
		BinNodeT<T>* temp = sRoot->Left;//creating temp for deletion
		sRoot->Left = sRoot->Left->Right; //swapping parent with child's right
		//delete temp;
		return temp;//holding value 
		
	}
}

//////////////////////////////////////////////////////////////// Find()
// Client is able to find a speicified node into the BST by calling this function
//
// Parameters:	const T& D
//
// Pre:       none
//
// Post:      specified Data is found within node
//
// Returns:   node that is found
//
// Called by: none
// Calls:     FindeHelper()
template <typename T>         
T* const BST<T>::Find(const T& D)
{
	return FindHelper(D, Root);
}  

//////////////////////////////////////////////////////////////// FindHelper()
// This function basically determines whether or not the element specified is in the tree
// but does not neccessarily locate it within in the tree.
//
// Parameters:	const T& toFind, BinNodeT<T>* sRoot
//
// Pre:       	none
//
// Post:      specified data found with tree
//
// Returns:   pointer to T(data type)
//
// Called by: Find()
// Calls:     FindHelper()
template <typename T>
T* const BST<T>::FindHelper(const T& toFind, BinNodeT<T>* sRoot) 
{
	if (sRoot == NULL) 
		return NULL;

	if (sRoot->Element == toFind)
	{
		
		return &(sRoot->Element);
	}
	if (toFind < sRoot->Element)
		return FindHelper(toFind, sRoot->Left);
	else
		return FindHelper(toFind, sRoot->Right);
}

//////////////////////////////////////////////////////////////// Find()const
// Same as above Find function but returns a constant value
//
// Parameters: const T& D
//
// Pre:       none
//
// Post:      specified data found when findhelper is used
//
// Returns:   call to FindHelper
//
// Called by: none
// Calls:     FindHelper()
template <typename T>                                       
const T* const BST<T>::Find(const T& D) const
{	
	return FindHelper(D, Root);
}

//////////////////////////////////////////////////////////////// Locate)const
// this function finds the exact location for the element i am specifying to be found
//
// Parameters: const T&, BinNodeT<T>* sRoot
//
// Pre:       none
//
// Post:      
//
// Returns:   pointer to located data node
//
// Called by: DeleteHelper()
// Calls:     Locate
template <typename T>
BinNodeT<T>* BST<T>::Locate(const T& D, BinNodeT<T>* sRoot)
{
	
	//checking for empty tree
	if(sRoot == NULL)
		return NULL;
		
	BinNodeT<T>* found = new BinNodeT<T>;// catcher node
	
	//find elment if on the right side of the tree
	if(D < sRoot->Element)
	{	
		found = sRoot->Left;
		if(found->Element == D)
		{
			return sRoot;
		}
		else
		{
			return Locate(D, sRoot->Left);
		}
	}
	
	//find element if one the right side of the tree
	else
	{ 
	
		found = sRoot->Right;
		if(found->Element == D)
		{
			return sRoot;
		}
		else
		{
			return Locate(D, sRoot->Right);
		}
	}
	return 0;
}
//////////////////////////////////////////////////////////////// FindHelper()const
// This basically does the same as the above FindHelper function except it return a constant
//
// Parameters: const T& toFind, BinNodeT<T>* sRoot
//
// Pre:       none
//
// Post:      specified data found within tree
//
// Returns:   constant pointer to T(data type)
//
// Called by: Find()
// Calls:     FindHelper()
template <typename T> 
const T* const BST<T>::FindHelper(const T& toFind, BinNodeT<T>* sRoot) const
{
	//checking for empty tree
	if (sRoot == NULL) 
		return NULL;

	//if element is found return pointer of type
	if (sRoot->Element == toFind)
	{
		return &(sRoot->Element);
	}
	//if element you're looking for is less than root go to left of tree
	if (toFind < sRoot->Element)
		return FindHelper(toFind, sRoot->Left);
	else
		//else go to right of tree
		return FindHelper(toFind, sRoot->Right);
}
//////////////////////////////////////////////////////////////// Display()
// Client calls this function to give display of BST
//
// Parameters:	ostream& Out
//
// Pre:       none
//
// Post:      BST output displayed
//
// Returns:  call to DisplayHelper()
//
// Called by: none
// Calls:     DisplayHelper()
template <typename T>  
void BST<T>::Display(ostream& Out) const
{
	DisplayHelper(Root, Out, 0);
	
}

//////////////////////////////////////////////////////////////// DisplayHelper()
// Displays output structure of BST
//
// Parameters: BinNodeT<T>* sRoot, ostream& Out, unsigned int Level
//
// Pre:       checks to see if tree is empty
//
// Post:      output of BST shown
//
// Returns:   none
//
// Called by: Display()
// Calls:     DisplayHelper()
template <typename T>
void BST<T>::DisplayHelper(BinNodeT<T>* sRoot, ostream& Out, unsigned int Level) const
{
	if (Root == NULL) 
	{
		Out << "Your tree is empty."<<endl;
		return;
	}
	if (sRoot == NULL)
		return;
		
	DisplayHelper(sRoot->Left, Out, Level + 1);

	if( Level > 0 ) 
	{
		Out << setfill('-') << setw(3*Level) <<'-';
		
	}
	Out << sRoot->Element << endl;
	Out << setfill(' ');
	DisplayHelper(sRoot->Right, Out, Level + 1);
}


//////////////////////////////////////////////////////////////// Clear()
// Client calls this to removes nodes from the BST and return it to an empty state
//
// Parameters: none
//
// Pre:       none
//
// Post:      tree is empty
//
// Returns:   none
//
// Called by: none
// Calls:     ClearHelper()
template <typename T>      
void BST<T>::Clear()
{
	ClearHelper(Root);
	Root = NULL;
}                          

//////////////////////////////////////////////////////////////// ClearHelper()
// This functions removes nodes by recursively removing right and left nodes
// of subroots.
//
// Parameters: BinNodeT<T>* sRoot
//
// Pre:       checks for empty tree
//
// Post:      tree is empty after clear has called it
//
// Returns:  none
//
// Called by: <List the name(s) of the function(s) that call this one.>
// Calls:     <List the name(s) of the function(s) that this one calls.>
template <typename T>
void BST<T>::ClearHelper(BinNodeT<T>* sRoot)
{
	// if root is null, indicates empty tree
	if(sRoot == NULL)
		return;
	
	ClearHelper(sRoot->Left); //recursively checking for empty state
	ClearHelper(sRoot->Right); //recursively checking for empty state
	
	//deletes root after recursive calls checking for null ptrs to left and right child
	delete sRoot;
}


/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
template <typename T> 
BST<T>::~BST()
{
	Clear();
}
#endif                        
