#include <iostream>
#include <iomanip>
#include <new>
#include <stdexcept>
#include <list>
//#include "LinkedList.cpp"
using namespace std;

list<int> SymmetricDifference(const list<int>& L1, const list<int>& L2);
void Split(list<int>& frontHalf, list<int>& backHalf);

int main()
{
	
		
	list<int> L1;
	L1.insert(L1.end(), 4);
	L1.insert(L1.end(), 17);
	L1.insert(L1.end(), 3);
	L1.insert(L1.end(), 2);
	L1.insert(L1.end(), 5);

	list<int> L2;
	L2.insert(L2.end(), 3);
	L2.insert(L2.end(), 1);
	L2.insert(L2.end(), 4);
	L2.insert(L2.end(), 2);

	list<int> L3 = SymmetricDifference(L1, L2);
	
	for(list<int>::const_iterator Pos = L3.begin(); Pos != L3.end(); Pos++)
	{
		
		cout<<*Pos<<endl;
	}
	return 0;
}