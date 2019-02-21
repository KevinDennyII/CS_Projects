/// Project Minor 1 for CS 2604 Fall 2005
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
class iterator {
   private:
      DNodeT<T>* Position;	// pointer to DList node
      iterator(DNodeT<T>* P) { // make an iterator from a node ptr
         Position = P;
      }

   public:  
/////////////////Constructor///////////////////
//
//
//
iterator()
{ 
	Position = NULL; 
}
///////////////ASSIGNMENT OPERATORS////////////
//
//
/*operator++()
Parameters:	none
Pre:		none
Post:		none
*/    
iterator operator++() 
{
	// step to next data node, if any, or to trailing sentinel
	if ( (Position != NULL))
	{
		Position = Position->Next;
	} 
	return (*this);         
}

/*operator++()
Parameters:	int Dummy
Pre:		none
Post:		none
*/  
iterator operator++(int Dummy) 
{
	
	// step to next data node, if any, or to trailing sentinel
	iterator Now(Position);
	if ( (Position != NULL))
	{
		Position = Position->Next;
	}
	return (Now);
        
}

/*operator--()
Parameters:	none
Pre:		none
Post:		none
*/ 
iterator operator--() 
{
	// step to previous data node, if any, or to leading sentinel
	if ( (Position != NULL))
	{
		Position = Position->Prev;
	}	
	return (*this);
         
}

/*operator--()
Parameters:	int Dummy
Pre:		none
Post:		none
*/    
iterator operator--(int Dummy) 
{
	// step to previous data node, if any, or to leading sentinel
	iterator Now(Position);
	if ( (Position != NULL))
	{
		Position = Position->Prev;
	}		
	return (Now);
         
}

/*operator==()
Parameters:	const iterator& RHS
Pre:		none
Post:		none
*/ 
bool operator==(const iterator& RHS) const 
{
	// iterators are equal iff they have the same target
	return (Position == RHS.Position );
         
 }

/*operator!=()
Parameters:	const iterator& RHS
Pre:		none
Post:		none
*/  
bool operator!=(const iterator& RHS) const 
{
	// complement of operator==()
	return (Position != RHS.Position );
         
}

/*operator*()
Parameters:	none	
Pre:		none
Post:		none
*/     
T& operator*() throw( range_error ) 
{
         // return reference to data in iterator's target,
         // throw exception if no target or target is not a data no	
	if (Position == NULL)
	{
		throw (range_error("dereferenced bad iterator"));
	}
	return (Position->Element);
}
	
	friend class const_iterator;
	friend class Javert;
	friend class DListT<T>;     // let DListTcreate useful iterators
};



