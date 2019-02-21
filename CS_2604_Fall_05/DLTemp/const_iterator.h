// Project Minor 1 for CS 2604 Fall 05
//
// Programmer:  Kevin Denny
// OS:          Mac OS X Tiger
// System:      
// Compiler:    
// Last Modified: August 30, 2005
//
// Purpose:
// The purpose of this program is to implement a doubly linked list using iterators
// and constant iterators to traverse through the list and carry out task.

class const_iterator {
   private:
     DNodeT<T>* Position;
      const_iterator(DNodeT<T>* P) {
         Position = P;
      }

   public:
/*const_iterator()  
Parameters:	none
Pre:		none
Post:		none
*/      
const_iterator()
{ 
	Position = NULL; 
}

/*operator++()
Parameters:	none
Pre:		none
Post:		none
*/   
const_iterator operator++() 
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
const_iterator operator++(int Dummy) 
{
	// step to next data node, if any, or to trailing sentinel
	const_iterator Now(Position);
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
const_iterator operator--() 
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
const_iterator operator--(int Dummy) 
{
	// step to previous data node, if any, or to leading sentinel
	const_iterator Now(Position);
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
bool operator==(const const_iterator& RHS) const 
{
	// iterators are equal iff they have the same target
	return (Position == RHS.Position );
         
 }

/*operator==()
Parameters:	const iterator& RHS
Pre:		none
Post:		none
*/
bool operator!=(const const_iterator& RHS) const 
{
	// complement of operator==()
	return(Position != RHS.Position);
	/*if(Position != RHS.Position)
	{
		return true;
	}
	else
		return false;*/
         
}

/*operator*()  
Parameters:	none
Pre:		none
Post:		none
*/  
const T& operator*() throw( range_error ) 
{
	// return reference to data in iterator's target,
        // throw exception if no target or target is not a dat
	if (Position == NULL)
	{
		throw range_error("dereferenced bad iterator");
	}
	else
		return (Position->Element);
}

/*const_iterator()  
Parameters:	const iterator& It
Pre:		none
Post:		none
*/
const_iterator(const const_iterator& It) 
{
         Position = It.Position;
}

/*operator=()  
Parameters:	const iterator& It
Pre:		none
Post:		none
*/
const_iterator& operator=(const const_iterator& It) 
{
	Position = It.Position;
	return (*this);
}
	friend class DListT<T>;
	friend class Javert;
	friend class iterator;
};
