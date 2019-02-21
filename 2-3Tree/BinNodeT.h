#ifndef	BinNodeT_H
#define	BinNodeT_H
#include <new>

template <typename T, int m> class BinNodeT{
private:
	T d;
	int keyCount;		//total number of keys
	T* keys;			//pointer to an array of data types for [(m/2)+1] size;	(possibly use a wrapper class)
	int number;			//number of keys for node
	BinNodeT* bptrs[m];	// array of BNode pointers
	bool leaf;	
	friend TTtreeT<T, m>;		
	
public:
	//insert, remove, find, clear one node type
	bool isLeaf();
	BinNodeT():
	BinNodeT(const T&);
}

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for BinNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T, int m>
BinNodeT<T, m>::BinNodeT()
{
	//setting array of node pointers to NULL, for initialization
	int i = 0;
	for(i; i < m; i++)
	{
		bptrs[i] = NULL; // setting pointer to NULL
	}
}

/*CONSTRUCTOR for BinNodeT class.

Parameters:	const T& data
Pre:		none
Post:		none
*/
template <typename T, int m>
BinNodeT<T,m>::BinNodeT(const T& data)
{
	d = data;//setting data
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
template <typename T, int m>
bool BinNodeT<T,m>::isLeaf()
{
	int i = 0;
	
	//checks for non-NULL pointers to see if the arrays pointers all point to no data
	//if atleast one pointer points to some data then the Node holding that pointer is
	//not a leaf
	for( i; i < m; i++)
	{
		if(bptrs[i] =! NULL)
		{
			return false;
		}
		else 
			return true;
	}
}
#endif