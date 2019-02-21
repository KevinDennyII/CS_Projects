

#ifndef	BINNODET_H
#define	BINNODET_H
#include <iostream>
using namespace std;

template <typename T> class BinNodeT {
public:
   T            Element;          // client data value
   BinNodeT<T>* Left;             // access to left child, if any
   BinNodeT<T>* Right;            // access to right child, if any

   BinNodeT();
   BinNodeT(const T& newData, BinNodeT<T>* newLeft  = NULL, 
                       BinNodeT<T>* newRight = NULL);

   bool isLeaf() const;           // useful for navigation in member fns
   ~BinNodeT();                   // doesn't really have much to do...
};

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for BinNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>
BinNodeT<T>::BinNodeT()
{
	Left = NULL;
	Right = NULL;
}

/*CONSTRUCTOR for BinNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>
BinNodeT<T>::BinNodeT(const T& newData, BinNodeT<T>* newLeft, BinNodeT<T>* newRight)
{
	Element = newData;
	Left = newLeft;
	Right = newRight;
	
}


//////////////////////////////////////////////////////////////// isLeaf()
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
template <typename T>
bool BinNodeT<T>::isLeaf() const
{
	if((Left == NULL) && (Right == NULL))
	{
		return true;
	}
	else
		return false;
}

/////////////////////////////////////////////////////////
//                ****DECONSTRUCTOR****
//
//
template <typename T>
BinNodeT<T>::~BinNodeT()
{
	//Left = NULL;
	//Right = NULL;
	
}
#endif
