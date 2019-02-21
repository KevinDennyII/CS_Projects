#ifndef PRQUADLEAF_HH
#define PRQUADLEAF_HH

using namespace std;

#include "prQuadInternal.h"
#include "prQuadNode.h"
//template <typename T> class prQuadNode;
template <typename T> class prQuadInternal;


template <typename T> class prQuadLeaf: public prQuadNode<T>{ 
private:
	T Element;
	bool flag;
	prQuadInternal<T>* temp;
public: 

	bool isEmpty();
	bool isLeaf();
	void display(ostream& Out);
	bool remove();
	void clear();
	
	prQuadLeaf(); 
	prQuadNode<T>* insert(double, double, double, double, T&); 
	~prQuadLeaf();
	
};

template <typename T>
prQuadLeaf<T>::prQuadLeaf()
{
	flag = false; //flag for to determin if leaf has been set already
	//Element = Elem;
}

template <typename T>
prQuadNode<T>* prQuadLeaf<T>::insert(double xpt1, double xpt2, double ypt1, double ypt2, T& Elem)
{
	cout<< "in prQuadLeaf insert" << endl;
	if(flag == false)
	{
		cout << "flag is false" << endl;
		Element = Elem;
		cout << "Element for false:	" << Element.getFid() << endl;
		flag = true;// leaf is now set
		return this;
	}
	else
	{
		cout << "flag is true" << endl;
		temp = new prQuadInternal<T>();  // creating new internal node
		temp->insert(xpt1, xpt2, ypt1, ypt2, Element); // inserting data into new internal node
		temp->insert(xpt1, xpt2, ypt1, ypt2, Elem);
		return temp;
	}
}

template <typename T>
void prQuadLeaf<T>::display(ostream& Out)
{
	Out << "prQuadLeaf:	"<< Element << endl;
}

template <typename T>
bool prQuadLeaf<T>::isEmpty()
{
	return true;
}

template <typename T>
bool prQuadLeaf<T>::isLeaf()
{
	return true;
}

template <typename T>
bool prQuadLeaf<T>::remove()
{
	return true;
}

template <typename T>
void prQuadLeaf<T>::clear()
{
	
}
#endif

