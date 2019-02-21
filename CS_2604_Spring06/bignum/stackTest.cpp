#include <iostream>

#include "DropOutStackT.h"

int main(){

	DropOutStackT<int>* stack = new DropOutStackT<int>(100);
	
	stack->push(5);
	stack->push(4);
	//stack->push('+');
	int* test = stack->peek();
	
	cout << *test << endl;
	stack->Display(cout);
  
return 0;
}

