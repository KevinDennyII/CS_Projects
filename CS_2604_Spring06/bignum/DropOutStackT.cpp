/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//                     
//
/*DEFAULT CONSTRUCTOR for DropOutStackT class.

Parameters: unsigned int capacity
Pre:        none
Post:       capacity int has been initialized
*/
template <typename T>
DropOutStackT<T>::DropOutStackT(unsigned int capacity)
{
    cap = capacity;
    top = 0;
    usage = 0;
    stk = new T[cap];
}

/*ASSIGNMENT OPERATOR for DropOutStackT class.

Parameters: const DropOutStackT<T>& rhs
Pre:    none
Post:  none 
*/
template <typename T>  
DropOutStackT<T>& DropOutStackT<T>::operator=(const DropOutStackT<T>& rhs)
{
    if ( this != &rhs) // check for self assignment.
    {
        cap = rhs.cap; // creating copies of each private variable.
        top = rhs.top;
        usage = rhs.usage;
        
        delete [] stk;
        stk = new T[cap]; // creating a new array 
        for (unsigned int i=0; i < cap; i++) // copy array cells into your newly
            stk[i] = rhs.stk[i];           // created array
    }
    return( *this );   
}

/*COPY CONSTRUCTOR for DropOutStackT class.

Parameters: const DropOutStackT<T>& source
Pre:        none
Post:       A deep copy of the array created.
*/
template <typename T> 
DropOutStackT<T>::DropOutStackT(const DropOutStackT<T>& source)
{
   cap = source.cap; // creating copies of each private variable.
   top = source.top;
   usage = source.usage;
   
   stk = new T[cap];
   for (unsigned int i=0; i < cap; i++)// copy array cells
        stk[i] = source.stk[i];      // addresses of data in old array to new 
                                       // array created.
}

/////////////////////////////////////////////////////////
//                  **FUNCTIONS**
//
//
//
/*push() - adds an element to the top of a stack.

Parameters: const T& elem
Pre:    none
Post:   none
*/
template <typename T> 
bool DropOutStackT<T>::push(const T& elem)
{
    if ( cap > 0) // check for emptiness of the stack.
    {
       stk[top] = elem; // 
       if((top + 1) == cap)  // when the stack top has reached its limit
            top = 0;
       else
            top++;          // move top to the next open spot.
       if (usage < cap)
           usage++;
    return true;
    }
     else
     {
            throw overflow_error("STACK_OVERFLOW"); //error given when try to push onto a
     }                                  //when the capicity is zero.
        return false;  
} 

/*pop() - removes an element to from the bottom of a stack.

Parameters: T& elem
Pre:    none
Post:   none
*/
template <typename T> 
bool DropOutStackT<T>::pop(T& elem)
{
    if (isEmpty())   //checking for any empty stack
    {
        throw underflow_error("STACK_UNDERFLOW"); // return a stack underflow 
    }                               //  error
    else
    {
        if (top == 0)
     {
         top = cap-1; // acting as cirular memory for when top is zero 
        }
     else 
         top--;
            elem = stk[top];  //finding the top element and aftering popping.
         usage--;
         return true;

    }
    return false;
}

/*peek() - allows you to look at the top most element of a stack.

Parameters: none
Pre:    none
Post:   Top element in the stack
*/
template <typename T> 
T* const DropOutStackT<T>::peek()const
{
    int tempTop = top;
    if(isEmpty())     //if there nothing to look at return 0
    {   
        return NULL;
    }
    else 
    {
       if(tempTop == 0)   // acting as circular memory for when top is zero
        tempTop = cap -1;
       else
       tempTop--;          // else just decrementing top
        
        return &stk[tempTop];   // else return the address of the top
    }                     // most element in the stack
    
}

/*clear() - resets stack to empty state.

Parameters: none
Pre:    none
Post:   Stack cleared.
*/
template <typename T> 
void DropOutStackT<T>::clear()
{
  usage = 0;   // resetting the usage and top both to zero.
  top = 0;   
}

/*isEmpty() - checks for empty stack.
 
Parameters: none
Pre:    none
Post:   none
*/
template <typename T> 
bool DropOutStackT<T>::isEmpty()const
{
    if (usage > 0) // if the usage is zero, then the stack is 
    {               // is empty and the boolean will return true.
        return false;
    }
    else
    {
        return true;
    }
}

/*capacity() - reports the stack's capacity.

Parameter:  none
Pre:    non
Post:   Capacity of the array.
*/
template <typename T> 
unsigned int DropOutStackT<T>::capacity()const
{
    return cap; //returning the capaicty
}

/*size() - reports the current usage of the stack.

Parameter: none
Pre:    none
Post:   none
*/
template <typename T> 
unsigned int DropOutStackT<T>::size()const
{
    return usage; //returning usage which is the size
}

/*display() - displays the contents of the stack.

Parameter:  ostream& out
Pre:    none
Post:   none
*/
template <typename T> 
ostream& operator<<(ostream& out, const DropOutStackT<T>& source)
{
    unsigned int tempTop = DropOutStackT<T>::top;
    unsigned int tempUsage = DropOutStackT<T>::usage;
	unsigned int cap = DropOutStackT<T>::cap;
	
    out << "Capacity: " << cap << endl;
    if ( DropOutStackT<T>::isEmpty())   //prints a message if stack is empty
    {
        out<<"No items to be displayed" <<
         " because stack is empty."<<endl;
    }
    else
    {
       while(tempUsage>0) // checking for usage 
       {                  
         if(tempTop!=0) 
               tempTop--; // decrementing if top is not zero
         else
          {
             tempTop = cap-1; // acting as cirular memory for when top is zero
         }
         //going through the array and printing out the elements
           out << tempTop << ": " << DropOutStackT<T>::stk[tempTop] << endl;
           tempUsage--;
       }
    }
}

/*display() - displays the contents of the stack.

Parameter:  ostream& out
Pre:    none
Post:   none
*/
template <typename T>
void DropOutStackT<T>::Display(ostream& out){

	unsigned int tempTop = top;
    unsigned int tempUsage = usage;
	unsigned int cap = cap;
	
    out << "Capacity: " << cap+1 << endl;
    if ( isEmpty())   //prints a message if stack is empty
    {
        out<<"No items to be displayed" <<
         " because stack is empty."<<endl;
    }
    else
    {
       while(tempUsage>0) // checking for usage 
       {                  
         if(tempTop!=0) 
               tempTop--; // decrementing if top is not zero
         else
          {
             tempTop = cap-1; // acting as cirular memory for when top is zero
         }
         //going through the array and printing out the elements
           out << tempTop << ": " << stk[tempTop] << endl;
           tempUsage--;
       }
    }


}
/*DEFAULT DECONSTRUCTOR 
 
Parameters: none
Pre:        none
Post:       DropOutStack object has been destroyed.
*/
template <typename T> 
DropOutStackT<T>::~DropOutStackT()
{    
   delete [] stk; // deleting the array
   stk = NULL;    // setting pointer to Null so that there is not dangling pointer.
}

