#include <iostream>
#include "DListT.h"	
int main(){ 
int i;

        DListT<int> mylist, list2;
        DListT<int>::const_iterator pos;
        for(i=0; i<20;i++)
		{
			mylist.Insert(mylist.end(), i);

		}
		
		pos = mylist.begin();
		cout<<*pos<<endl;
		pos++;
		cout<<*pos<<endl;
		pos++;
		cout<<*pos<<endl;

        mylist.Display(cout);
		/*pos = mylist.end();
        mylist.Find(3);
        cout << "deletion test" << endl << endl;

        mylist = mylist;
        list2 = mylist;
        list2.Display(cout);

        for(pos = list2.begin(); pos != list2.end(); pos++)
			cout << *pos << ' ';*/
}
