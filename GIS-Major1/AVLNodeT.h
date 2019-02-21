#ifndef AVLNODET_HH
#define AVLNODET_HH

using namespace std;
enum BFactor {LEFTHI, RIGHTHI, EQUALHT, DBLRIGHTHI, DBLLEFTHI, BALUNKNOWN};
template <typename T> class AVLNodeT {
public:
	T Element;
	AVLNodeT<T>* Left;
	AVLNodeT<T>* Right;
	BFactor Balance;
	AVLNodeT();
	AVLNodeT(const T& Elem, AVLNodeT<T>* L = NULL, AVLNodeT<T>* R = NULL);
	BFactor adjustBalance(BFactor Grew);
	bool isLeaf() const;

};

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for AVLNodeT class.

Parameters:	none
Pre:		none
Post:		variables initialized 
*/
template <typename T>
AVLNodeT<T>::AVLNodeT()
{
	Balance = EQUALHT;
	Left = Right =  NULL;
}

/*CONSTRUCTOR for AVLNodeT class.

Parameters:	const T& Elem, AVLNodeT<T>* L, AVLNodeT<T>* R ,
	AVLNodeT<T>* P 
Pre:		none
Post:		none
*/
template <typename T>
AVLNodeT<T>::AVLNodeT(const T& Elem, AVLNodeT<T>* L, AVLNodeT<T>* R)
{
		Balance = EQUALHT;
		Element = Elem;
		Left = L;
		Right = R;
}

/////////////////////////////////////////////////////////////// adjustBalance()
// <Brief description of what the function does.>
//
// Parameters:	BFactor Grew)
//
// Pre: 	grew is to be set
//
// Post:	grew is set to new balance 
//
// Returns:   	enumerated type of balance factor
//
// Called by: 	none
// Calls:     	none
template <typename T>
BFactor AVLNodeT<T>::adjustBalance(BFactor Grew)
{
	// if the balance factor is right side is higher level
	if(Grew == RIGHTHI)
	{
		// return bfactor of righthi if unknown
		if(Balance == BALUNKNOWN)
		{
			Balance = RIGHTHI;
			return Balance;
		}
		// return bfactor of equalhi if previous balance was lefthi
		else if (Balance == LEFTHI)
		{
			Balance = EQUALHT;
			return Balance; 
		}
		// return bfactor of doublrighthi if previous was righthi
		else if (Balance == RIGHTHI)
		{
			Balance = DBLRIGHTHI;
			return Balance;
		}
		
		// when balance is equalhieight return righthi
		else
			Balance = RIGHTHI; 
			return Balance;
		
	}
	
	// if the balance factor is left side is higher level
	else
	{
		
		// return bfactor of lefthi if unknown
		if(Balance == BALUNKNOWN)
		{
			Balance = LEFTHI;
			return Balance;
		}
		// return bfactor of doubllefthi if previous was leftthi
		else if(Balance == LEFTHI)
		{
			Balance = DBLLEFTHI;
			return Balance;
		}
		// return bfactor of equalhi if previous balance was righthi
		else if(Balance == RIGHTHI)
		{
			Balance = EQUALHT;
			return Balance;
		}
		// when balance is equalhieight return lefthi
		else 
			Balance = LEFTHI;
			return Balance;
	}
	return Balance;
		
}

/////////////////////////////////////////////////////////////// isLeaf()
// This function determines if a node is a leaf of the avl tree
//
// Parameters:	none
//
// Pre:			checks for right and left child to be NULL
//
// Post:		true if node is a left, false if not
//
// Returns:  	boolean
//
// Called by: 	none
// Calls:    	none
template <typename T>
bool AVLNodeT<T>::isLeaf() const
{
	if (Left==NULL && Right==NULL)
		return true;

	else
		return false;
}
#endif