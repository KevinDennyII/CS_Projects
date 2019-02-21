using namespace std;

#include "DListT.h"

int main(){
	DListT<int>* num1 = new DListT<int>();
	DListT<int>* num2 = new DListT<int>();
	DListT<int>* result = new DListT<int>();
	
	
	//create the number 1087
	num1->Insert(num1->end(), 1);
	num1->Insert(num1->end(), 0);
	num1->Insert(num1->end(), 0);
	num1->Insert(num1->end(), 0);
	
	num1->Display(cout);
	
	cout << endl;  
	
	//create the number 999
	//num2->Insert(num2->end(), 9);
	num2->Insert(num2->end(), 0);
	//num2->Insert(num2->end(), 1);
	
	num2->Display(cout);
 
	result->addList(*num1, *num2, *result, 0);
	cout << "Final result of addition: " << endl;
	result->Display(cout);
	cout << endl;
	
	cout << "we are now multiplying....." << endl;
	
	DListT<int>* num3 = new DListT<int>();
	DListT<int>* num4 = new DListT<int>();
	DListT<int>* result2 = new DListT<int>();

	//create the number 1000
	num3->Insert(num3->end(), 7);
	num3->Insert(num3->end(), 8);
	num3->Insert(num3->end(), 4);
	num3->Insert(num3->end(), 3);
	
	//create the number 21
	num4->Insert(num4->end(), 4);
	num4->Insert(num4->end(), 8);
	num4->Insert(num4->end(), 9);
	num4->Insert(num4->end(), 1);
	
	result2->multList(*num3, *num4, *result2, 0);
	
	cout << "Final result of multiplication: " << endl;
	result2->Display(cout);
	cout << endl;
	
	cout << "we are now multiplying exponentially....." << endl;
	DListT<int>* num5 = new DListT<int>();
	DListT<int>* result3 = new DListT<int>();
	
	num5->Insert(num5->end(), 2);
	int m = 2;
	
	result3->exponList(*num5, *result3, 0, m);
	
	cout << "Final result of multiplication exponentially: " << endl;
	result3->Display(cout);
	


	return 0;
}

