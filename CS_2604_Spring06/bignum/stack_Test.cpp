#include <iostream>

#include "DropOutStack.cpp"

int main(){

	DropOutStack stack; //= new DropOutStackT<int>(100);
	
	stack.push(5);
	stack.push(4);
	
	int* test = stack.peek();
	
	cout << *test << endl;
	cout << stack << endl;
  
return 0;
}



