#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
	BST<int> mytree, t2;
	cout<<"1st spot"<<endl;
	
	mytree.Insert(151);
	mytree.Insert(38);
	mytree.Insert(73);
	mytree.Insert(544);
	mytree.Insert(342);
	mytree.Insert(283);
	mytree.Insert(155);
	mytree.Insert(565);
	mytree.Insert(665);
	mytree.Insert(746);
	mytree.Insert(429);
	mytree.Insert(429);
	mytree.Insert(233);
	mytree.Insert(529);
	mytree.Insert(263);
	mytree.Insert(924);
	mytree.Insert(430);
	mytree.Insert(507);
	mytree.Insert(670);
	mytree.Insert(157);
	cout<<"2nd spot"<<endl;

	t2 = mytree;
	cout<<"3rd spot"<<endl;

	mytree.Display(cout);

	cout << "new tree" << endl;


	
	mytree.Delete(37);
	mytree.Delete(73);
	mytree.Delete(155);
	mytree.Delete(233);
	mytree.Delete(283);
	mytree.Delete(429);
	mytree.Delete(507);
	mytree.Delete(544);
	mytree.Delete(665);
	mytree.Delete(746);
	mytree.Delete(151);


	mytree.Display(cout);
//	mytree.Display(cout);
	return 0;
}
