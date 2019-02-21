#ifndef	BNODET_H
#define	BNODET_H

#include <algorithm>
#include <new>

using namespace std;

#include "BTreeT.h"
template <typename T, int m> class BTreeT;

template <typename T, int m> class BNodeT{
private:
	int tally;
	int keyCount;		//total number of keys
	T* keys;			//pointer to an array of data types for [(m/2)+1] size;	(possibly use a wrapper class)
	int number;			//number of keys for node
	BNodeT* bptrs[m];	// array of BNode pointers
	bool leaf;	
	friend class BTreeT<T,m>;		
	
public:
	//insert, remove, find, clear one node type
	bool insert(const T&);
	bool isFull();
	bool isLeaf();
	BNodeT();
	BNodeT(const T&);
};

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for BNodeT class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T, int m>
BNodeT<T,m>::BNodeT()
{
	tally = 0;
	//setting array of node pointers to NULL, for initialization
	int i = 0;
	for(i; i < m; i++)
		bptrs[i] = NULL; // setting pointer to NULL
		
	for(int x = 0; x <(m-1); x++)
		keys[x]=0;
	
	keys = new T[m-1]; // array of keys
}

/*CONSTRUCTOR for BNodeT class.

Parameters:	const T& data
Pre:		none
Post:		none
*/
template <typename T, int m>
BNodeT<T,m>::BNodeT(const T& data)
{	
	tally = 0;
	//setting array of node pointers to NULL, for initialization
	int i = 0;
	for(i; i < m; i++)
		bptrs[i] = NULL; // setting pointer to NULL
	
	keys = new T[m-1]; // array of keys
	
	for(int x = 0; x <(m-1); x++)
		keys[x]=0;
	
	keys[0] = data;//setting data
	tally++;
}

//////////////////////////////////////////////////////////////// insert()
// 
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
bool BNodeT<T,m>::insert(const T& data)
{
		cout << "inside node insert" << endl;

		keys[tally] = data;
		cout << keys[tally] <<" << data being inserted in node insert" << endl;
		sort(keys, keys+tally);
		tally++;
		return true;
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
bool BNodeT<T,m>::isLeaf()
{
	int i = 0;
	
	//checks for non-NULL pointers to see if the arrays pointers all point to no data
	//if atleast one pointer points to some data then the Node holding that pointer is
	//not a leaf
	for( i; i < m; i++)
	{
		if(bptrs[i] != NULL)
		{
			return false;
		}
		else 
			return true;
	}
}

//////////////////////////////////////////////////////////////// isFull()
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
bool BNodeT<T,m>::isFull()
{	
	bool flag;
	//going through the arrays of pointers then through each pointers array of elments
	//to see if they are not empty

			for(int x = 0; x < (m-1); x++)
			{
				if(keys[x] == 0)
				{
					cout << " found empty element in is full.....return false" << endl;
					flag = false;
				}
				else 
					flag = true;
			}
	return flag;
}
#endif