//  Programmer:			Kevin Denny
//  OS:					Mac OS X 
//  System:				1.5GHz G4
//  Compiler:			Xcode 2.1 
//  Last modified:		January 30, 2005

// On my honor:
//
// - I have not used C++ language code obtained from another student,
// or any other unauthorized source, either modified or unmodified.
//
// - All C++ language code and documentation used in my program
// is either my original work, or was derived, by me, from the source
// code published in the textbook for this course.
//
// - I have not discussed coding details about this project with anyone
// other than my instructor, ACM/UPE tutors or the GTAs assigned to this
// course. I understand that I may discuss the concepts of this program
// with other students, and that another student may help me debug my
// program so long as neither of us writes anything during the discussion
// or modifies any computer file during the discussion. I have violated
// neither the spirit nor letter of this restriction.
//
//    Kevin Denny, kdenny2

#include<iostream>
#include<fstream>
#include<ios>
#include<string>
#include<iomanip>
#include<stdexcept>
#include<sstream>

using namespace std;

#include "DListT.h"
#include "DropOutStackT.h"


DListT<int>* digits(string& con)
{	
	bool flag =true;
	DListT<int>* tester = new DListT<int>();
	
	for(int i = 0; con.c_str()[i] != '\0'; i++)
	{
		char num[2];
		num[0] = con.c_str()[i];
		num[1] = '\0';
		int dom = atoi(num);
		
		if(dom != 0 || flag != false)
		{
			flag = false;
			tester->Insert(tester->end(), dom);
			//tester.Display(cout);
		}
		
	}
	return tester;
}

int main (int argc, char * const argv[]) {
	
/*	DListT<int>* num1 = new DListT<int>();
	DListT<int>* num2 = new DListT<int>();
	DListT<int>* result1 = new DListT<int>();
	DListT<int>* result2 = new DListT<int>();
	
	num1->Insert(num1->end(), 7);
	num1->Insert(num1->end(), 8);
	num1->Insert(num1->end(), 4);
	num1->Insert(num1->end(), 3);
	
	num2->Insert(num2->end(), 4);
	num2->Insert(num2->end(), 8);
	num2->Insert(num2->end(), 9);
	num2->Insert(num2->end(), 1);

	DropOutStackT<DListT<int>*> stackptr(100);
	
	cout <<"pushing lists onto stack" << endl;
	stackptr.push(num1);
	stackptr.push(num2);
	//stackptr.Display(cout);
	stackptr.pop(num1);
	stackptr.pop(num2);
	
	/*result1->addList(*num1,*num2, *result1, 0);
	result1->Display(cout);
	stackptr.push(result1);*/
	
	/*result2->multList(*num1,*num2, *result2, 0);
	result2->Display(cout);
	stackptr.push(result2);
	DListT<int>* temp = *stackptr.peek();
	temp->Display(cout);*/
	
/*	cout << "we are now multiplying exponentially....." << endl;
	DListT<int>* num5 = new DListT<int>();
	DListT<int>* result3 = new DListT<int>();
	num5->Insert(num5->end(), 2);
	int m = 2;
	result3->expon(*num5, *result3, 0, m);
	cout << "Final result of multiplication exponentially: " << endl;
	result3->Display(cout);*/
	
	DropOutStackT<DListT<int>*> stack(100);
	
	cout <<"Starting reading of file...." << endl;
	string breakup;
	while(!cin.eof())
	{
		stringstream line;
		getline(cin, breakup, '\n');
		//cout <<"reading of file: " << breakup << endl;
		line << breakup;
		while(!line.fail())
		{
			DListT<int>* tester = new DListT<int>();
			DListT<int>* temp;//= new DListT<int>();
			
			string test;
			line >> test;
		//	cout << "token is : " << test << endl;
			if(test == "+")
			{
				DListT<int>* popper1;
				DListT<int>* popper2;
				DListT<int>* result = new DListT<int>();
				stack.pop(popper1);
				stack.pop(popper2);
				
				result->addList(*popper1, *popper2, *result, 0);
				stack.push(result);
				cout << "result of additon is : " << endl;
				(*stack.peek())->Display(cout);
				
			}
			else if(test == "*")
			{
				DListT<int>* popper1;
				DListT<int>* popper2;
				DListT<int>* result = new DListT<int>();
				stack.pop(popper1);
				stack.pop(popper2);
				
				result->multList(*popper1, *popper2, *result, 0);
				stack.push(result);
				cout << "result of multiplication is : " << endl;
				(*stack.peek())->Display(cout);
			}
			else if(test == "^")
			{
				DListT<int>* popper1;
				DListT<int>* popper2;
				DListT<int>* result = new DListT<int>();
				stack.pop(popper1);
				stack.pop(popper2);
				
				result->expon(*popper1, *result, 0, *(popper2->begin()));
				stack.push(result);
				cout << "result of exponential is : " << endl;
				(*stack.peek())->Display(cout);
			}

			else
			{
				tester = digits(test);
				tester->Display(cout);
				stack.push(tester); 
				temp = *stack.peek();
				temp->Display(cout);
			}
			
		}
	
		
	}  
	//else if(cin.fail())
	//{
	////	cout << "Invalid entry!" << endl;
	//}
	
   
	return 0;
}
