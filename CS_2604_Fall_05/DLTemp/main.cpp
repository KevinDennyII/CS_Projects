//  --- Title -------------------------------------------------------------------------------------
//
//  Minor Project 1 for CS 2604 Summer II 2005: Doubly-linked List Template
//  Class: main
//
//  --- Information -------------------------------------------------------------------------------
//
//  Programmer:			Michael S. Potter
//  OS:					Mac OS X Server (10.4 - Build 8A428)
//  System:				1.5GHz G4 Altivec PowerPC Processor, 1.25GB PC2700 DDR SDRAM
//  Compiler:			Xcode 2.1 (IDE), GCC 4.0 (Compiler)
//  Last modified:		July 13, 2005
//
//  --- Purpose -----------------------------------------------------------------------------------
//
//  The purpose of this class is to test the operations and stability of an instance of the DListT
//  template. No guarantee, however, can be made as to the accuracy or correctness of this class'
//  tests. Use at your own risk.
//
//  -----------------------------------------------------------------------------------------------

#include "DListT.h" 	// Includes the custom "DListT.h" header file.

int main ( int argc, char * const argv[] )		// Begins the main function.
{
	DListT<int> LinkedList;
	
	// Begin testing LinkedList.
	
	try
	{
		LinkedList.Insert( LinkedList.end(), 4 );
		cout << "Insert 4 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 4 could not be appended to the list." << endl;
	}
	cout<<"first insert worked, trying second\n";
	try
	{	
		LinkedList.Insert( LinkedList.end(), 5 );
		cout << "Insert 5 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 5 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 6 );
		cout << "Insert 6 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 6 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 7 );
		cout << "Insert 7 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 7 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 8 );
	
		cout << "Insert 8 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 8 could not be appended to the list." << endl;
	}
	
	try
	{			
		LinkedList.Insert( LinkedList.end(), 10 );
		cout << "Insert 10 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 10 could not be appended to the list." << endl;
	}
	
	try
	{
		cout<<"List is attempting to be printed"<<endl;
		LinkedList.Display(cout);
		//LinkedList.Insert( LinkedList.Find( 10 ), 9 );
		cout << "Insert 9 before 10: Neither 'Head' not 'Tail' should have changed after this "
			<< "operation." << endl;	
	}
	catch( range_error e )
	{
		cout << "Failure: 9 could not be inserted before 10 in the list" << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.begin(), 3 );
		cout << "Insert 3 at Beginning: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 3 could not be prepended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.Find( 3 ), 2 );
		cout << "Insert 2 before 3: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 2 could not be inserted before 3 in the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.begin(), 1 );
		cout << "Insert 1 at Beginning: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 1 could not be prepended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Clear();
		cout << "Clear: 'Head' and 'Tail' should have been changed to NULL after this operation." 
			<< endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The list could not be cleared." << endl;
	}
	
	bool clear = LinkedList.isEmpty();
	
	if( clear )
	{
		cout << "Clear Successful: isEmpty() returned true." << endl;
	}
	else
	{
		cout << "Clear Unsuccessful: isEmpty() returned false." << endl;
	}
	
	try
	{
		LinkedList.Insert( LinkedList.end(), 4 );
		cout << "Insert 4 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 4 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 5 );
		cout << "Insert 5 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 5 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 6 );
		cout << "Insert 6 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 6 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 7 );
		cout << "Insert 7 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 7 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 8 );
		cout << "Insert 8 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 8 could not be appended to the list." << endl;
	}
	
	try
	{			
		LinkedList.Insert( LinkedList.end(), 10 );
		cout << "Insert 10 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 10 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.Find( 10 ), 9 );
		cout << "Insert 9 before 10: Neither 'Head' not 'Tail' should have changed after this "
			<< "operation." << endl;	
	}
	catch( range_error e )
	{
		cout << "Failure: 9 could not be inserted before 10 in the list" << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.begin(), 3 );
		cout << "Insert 3 at Beginning: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 3 could not be prepended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.Find( 3 ), 2 );
		cout << "Insert 2 before 3: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 2 could not be inserted before 3 in the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.begin(), 1 );
		cout << "Insert 1 at Beginning: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 1 could not be prepended to the list." << endl;
	}
			
	try
	{	
		LinkedList.Delete( LinkedList.Find( 5 ) );
		cout << "Delete 5: Neither 'Head' nor 'Tail' should have changed after this operation." 
			<< endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 5 could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( --LinkedList.end() );
		cout << "Delete Last: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The last element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( LinkedList.begin() );
		cout << "Delete First: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The first element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( LinkedList.begin() );
		cout << "Delete First: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The first element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( LinkedList.begin() );
		cout << "Delete First: 'Head' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The first element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( --LinkedList.end() );
		cout << "Delete Last: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The last element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( --LinkedList.end() );
		cout << "Delete Last: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The last element could not be deleted from the list." << endl;
	}
	
	try
	{	
		LinkedList.Delete( ----LinkedList.end() );
		cout << "Delete Second to Last: 'Tail' should not have changed after this operation." 
			<< endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The second to last element could not be deleted from the list." << endl;
	}
	
	cout << endl << "Your output should resemble the following:" << endl << endl;
	cout << "Displaying the contents of the doubly-linked list:" << endl;
	cout << "Element 1: 4" << endl << "Element 2: 7" << endl << endl;
	
	cout << "Here is your output:" << endl << endl;
	
	try
	{	
		LinkedList.Display( cout );
		cout << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The list could not be displayed." << endl << endl;;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 8 );
		cout << "Insert 8 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 8 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 9 );
		cout << "Insert 9 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 9 could not be appended to the list." << endl;
	}
	
	try
	{	
		LinkedList.Insert( LinkedList.end(), 10 );
		cout << "Insert 10 at End: 'Tail' should have changed after this operation." << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: 10 could not be appended to the list." << endl;
	}
	
	//DListT<int> LLCopyEquals = LinkedList;
	
	cout << endl << "Your copy (via =) should resemble the following:" << endl << endl;
	cout << "Displaying the contents of the doubly-linked list:" << endl;
	cout << "Element 1: 4" << endl << "Element 2: 7" << endl << "Element 3: 8" << endl;
	cout << "Element 4: 9" << endl << "Element 5: 10" << endl << endl;
	
	cout << "Here is your output:" << endl << endl;
	
	try
	{	
		//LLCopyEquals.Display( cout );
		cout << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The list could not be displayed." << endl << endl;
	}
	
	//DListT<int> LLCopyConstructor = DListT<int>( LinkedList );
	
	cout << "Your copy (via copy constructor) should resemble the following:" << endl;
	cout << endl << "Displaying the contents of the doubly-linked list:" << endl;
	cout << "Element 1: 4" << endl << "Element 2: 7" << endl << "Element 3: 8" << endl;
	cout << "Element 4: 9" << endl << "Element 5: 10" << endl << endl;
	
	cout << "Here is your output:" << endl << endl;
	
	try
	{	
		//LLCopyConstructor.Display( cout );
		cout << endl;
	}
	catch( range_error e )
	{
		cout << "Failure: The list could not be displayed." << endl << endl;;
	}
	
	cout << "Done! While the results of this test cannot be guaranteed 100% accurate, " << endl;
	cout << "it certainly does a good check of things." << endl;
	
    return 0;
}
