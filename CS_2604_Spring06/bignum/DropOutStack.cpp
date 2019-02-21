// Programmer:  Kevin Denny
// Last Modified:  February 16, 2005
// Compiler:        Eclipse 3.0.1


#include "DropOutStack.h"

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//                     
//
/*DEFAULT CONSTRUCTOR for DropOutStack class.

Parameters: unsigned int capacity
Pre:        none
Post:       capacity int has been initialized
*/
DropOutStack::DropOutStack(unsigned int capacity)
{
    cap = capacity;
    top = 0;
    usage = 0;
    LastError = NO_ERROR;
    stk = new Item[cap];
}

/*ASSIGNMENT OPERATOR for DropOutStack class.

Parameters: const DropOutStack& rhs
Pre:    none
Post:  none 
*/ 
DropOutStack& DropOutStack::operator=(const DropOutStack& rhs)
{
    if ( this != &rhs) // check for self assignment.
    {
        cap = rhs.cap; // creating copies of each private variable.
        top = rhs.top;
        usage = rhs.usage;
        LastError = rhs.LastError;
        
        delete [] stk;
        stk = new Item[cap]; // creating a new array 
        for (unsigned int i=0; i < cap; i++) // copy array cells into your newly
            stk[i] = rhs.stk[i];           // created array
    }
    return( *this );   
}

/*COPY CONSTRUCTOR for DropOutStack class.

Parameters: const DropOutStack& source
Pre:        none
Post:       A deep copy of the array created.
*/
DropOutStack::DropOutStack(const DropOutStack& source)
{
   cap = source.cap; // creating copies of each private variable.
   top = source.top;
   usage = source.usage;
   LastError = source.LastError;
   
   stk = new Item[cap];
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

Parameters: const Item& elem
Pre:    none
Post:   none
*/
bool DropOutStack::push(const Item& elem)
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
     LastError = NO_ERROR; //setting state to no error.
    return true;
    }
     else
     {
            LastError = STACK_OVERFLOW; //error given when try to push onto a
     }                                  //when the capicity is zero.
        return false;  
} 

/*pop() - removes an element to from the bottom of a stack.

Parameters: Item& elem
Pre:    none
Post:   none
*/
bool DropOutStack::pop(Item& elem)
{
    if (isEmpty())   //checking for any empty stack
    {
        LastError = STACK_UNDERFLOW; // return a stack underflow 
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
          LastError = NO_ERROR;
         return true;

    }
    return false;
}

/*peek() - allows you to look at the top most element of a stack.

Parameters: none
Pre:    none
Post:   Top element in the stack
*/
Item* const DropOutStack::peek()const
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
void DropOutStack::clear()
{
  usage = 0;   // resetting the usage and top both to zero.
  top = 0;   
  LastError = NO_ERROR; // resetting error state to no error.
}

/*isEmpty() - checks for empty stack.
 
Parameters: none
Pre:    none
Post:   none
*/
bool DropOutStack::isEmpty()const
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

/*getError() - returns the error state of the stack.
 
Parameters: none
Pre:    none
Post:   none
*/
ErrorType DropOutStack::getError() const
{
    return LastError;
}
/*capacity() - reports the stack's capacity.

Parameter:  none
Pre:    non
Post:   Capacity of the array.
*/
unsigned int DropOutStack::capacity()const
{
    return cap; //returning the capaicty
}

/*size() - reports the current usage of the stack.

Parameter: none
Pre:    none
Post:   none
*/
unsigned int DropOutStack::size()const
{
    return usage; //returning usage which is the size
}

/*display() - displays the contents of the stack.

Parameter:  ostream& out
Pre:    none
Post:   none
*/
void DropOutStack::display(ostream& out)const
{
    unsigned int tempTop = top;
    unsigned int tempUsage = usage;
   out << "Capacity: " << cap << endl;
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
DropOutStack::~DropOutStack()
{    
   delete [] stk; // deleting the array
   stk = NULL;    // setting pointer to Null so that there is not dangling pointer.
}

//  On my honor:
//    
//    - I have not discussed the C++ language code in my program with
//   anyone other than my instructor or the teaching assistants 
//     assigned to this course.
//  
//    - I have not used C++ language code obtained from another student, 
//   or any other unauthorized source, either modified or unmodified.  
//    
//    - If any C++ language code or documentation used in my program 
//   was obtained from another source, such as a text book or course
//     notes, that has been clearly noted with a proper citation in
//    the comments of my program.
//   
//    - I have not designed this program in such a way as to defeat or
//      interfere with the normal operation of the Curator System.
//
//    - I have neither given nor received unauthorized aid in the
//   completion of this assignment.
//
//      Kevin Denny, kdenny2@vt.edu
