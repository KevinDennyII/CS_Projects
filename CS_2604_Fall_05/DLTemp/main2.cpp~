#include <iostream>
#include "DListT.h"

int main()
{
	int i;
	DListT<int> mylist, list2;
	DListT<int>::iterator pos2;
//	DListT<int>::const_iterator pos2;

	for (i = 0; i < 40; i++)
		mylist.Insert(mylist.end(), i);

	cout << "inserted sh**" << endl;
	pos2 = mylist.begin();
	cout<<"*";
	while( pos2 != mylist.end()) {
		cout << *pos2 << endl;
		pos2++;
		cout <<"*";
	}
	
	cout << "deletion" << endl;

	pos2 = mylist.begin();
	pos2++;
	pos2++;
	mylist.Delete(pos2);
	pos2 = mylist.end();
	pos2--;
	mylist.Delete(pos2);
	mylist.Delete(mylist.begin());
	mylist.Display(cout);
	cout << *mylist.Find(3);
	cout << *mylist.Find(99999);
	
	cout << "dem some" << endl;	
	return 1;	
}
