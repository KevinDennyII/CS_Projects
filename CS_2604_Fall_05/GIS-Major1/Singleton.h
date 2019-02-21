#ifndef SINGLETON_HH
#define SINGLETON_HH
#include<new>
#include<string>
#include<iostream>

using namespace std;

#include "prQuadNode.h"
#include "prQuadLeaf.h"
//template <typename T> class prQuadNode;
//template <typename T> class prQuadLeaf;

template <typename T> class Singleton: public prQuadNode<T>{
private:
	static Singleton<T>* pinstance;
	Singleton();
	prQuadLeaf<T>* temp;
public:
	bool isEmpty();
	bool isLeaf();
	void display(ostream& Out);
	bool remove();
	void clear();
	static Singleton<T>* instance();
	prQuadNode<T>* insert(double, double, double, double, T&);
	//~Singleton();

};

template <typename T>
Singleton<T>* Singleton<T>::pinstance=0;

/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for Singleton class.

Parameters:	none
Pre:		none
Post:		none
*/
template <typename T>
Singleton<T>::Singleton()
{
	
}

//////////////////////////////////////////////////////////////// instance()
// 
//
// Parameters: none
//
// Pre:       
//
// Post:      
//
// Returns:  
//
// Called by: none
// Calls:     none
template <typename T>
Singleton<T>* Singleton<T>::instance()
{
	if(pinstance == 0)
	{
		pinstance = new Singleton<T>;
		return pinstance;
	}
}

//////////////////////////////////////////////////////////////// insert()
// 
//
// Parameters: none
//
// Pre:       
//
// Post:      
//
// Returns:  
//
// Called by: none
// Calls:     none
template <typename T>
prQuadNode<T>* Singleton<T>::insert(double xpt1, double xpt2, double ypt1, double ypt2, T& data)
{
	cout<<"inside Singleton insert" << endl;
	temp = new prQuadLeaf<T>();
	temp->insert(xpt1, xpt2, ypt1, ypt2, data);
	return temp;
}

template <typename T>
void Singleton<T>::display(ostream& Out)
{
	Out << "I am a singleton node" << endl;
}

template <typename T>
bool Singleton<T>::isEmpty()
{
	return true;
}

template <typename T>
bool Singleton<T>::isLeaf()
{
	return true;
}

template <typename T>
bool Singleton<T>::remove()
{
	return true;
}

template <typename T>
void Singleton<T>::clear()
{
	
}
/////////////////////////////////////////////////////////
//                ****DECONSTRUCTORS****
//
//
/*template <typename T>
Singleton<T>::~Singleton()
{
	Singleton<T>* Singleton<T>::pinstance=NULL;
}*/
#endif