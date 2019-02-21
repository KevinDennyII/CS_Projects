#ifndef PRQUADINTERNAL_HH
#define PRQUADINTERNAL_HH

using namespace std;

#include "prQuadLeaf.h"
#include "prQuadNode.h"
template <typename T> class Singleton;
template <typename T> class prQuadLeaf;


template <typename T> class prQuadInternal:  public prQuadNode<T>{
private:
	prQuadNode<T>* NE, *SE, *NW, *SW, found; // internal node pointers

public:
	bool isEmpty();
	bool isLeaf();
	bool remove();
	void clear();
	prQuadNode<T>* insert(double, double, double, double, T&);
	prQuadNode<T>* find(double, double, double, double, T&);
	void display(ostream&);
	prQuadInternal();
	~prQuadInternal();
	

};

template <typename T>
prQuadInternal<T>::prQuadInternal()
{
	NE = Singleton<T>::instance();
	NW = Singleton<T>::instance();
	SE = Singleton<T>::instance();
	SW = Singleton<T>::instance();
}

template <typename T>
prQuadNode<T>* prQuadInternal<T>::insert(double xpt1, double xpt2, double ypt1, double ypt2, T& data)
{
	double xmid, ymid;	//point of origin within world
	
	xmid = (xpt1 + xpt2)/2;	//calculated midpoint of x
	ymid = (ypt1 + ypt2)/2;	// calculated midpoint of y
	cout << "in Internal retrieving data's coordinates:	"  << data.getTotaly() << "  " << data.getTotalx() << endl;
	cout << "x1:" << xpt1 << " " << "x2:" << xpt2 << " " << "y1:" << ypt1 << " " << "y2:" << ypt2 << endl;
	
	cout << "in prQuadInternal insert" << endl;
	//creating new leaf node in bottom left quadrant
	if((data.getTotalx() > xpt1) && (data.getTotaly() > ypt1) && (data.getTotalx() < xmid) && (data.getTotaly() < ymid))
	{
		cout << "in SW node " << endl;
		//SW = new prQuadLeaf<T>();
		SW = SW->insert(xpt1, xmid, ypt1, ymid, data);//inserting node into quadrant
		return this;
	}
	//creating new leaf node in upper left quadrant
	if ((data.getTotalx() > xpt1) && (data.getTotaly() < ypt2) && (data.getTotaly() > ymid) && (data.getTotalx() < xmid))
	{
		cout << "in NW node " << endl;
		//NW = new prQuadLeaf<T>();
		NW = NW->insert(xpt1, xmid, ymid, ypt2, data); 
		return this;
	}
	//creating new leaf node in botton right quadrant
	if ((data.getTotalx() < xpt2) && (data.getTotaly() > ypt1) && (data.getTotalx() > xmid) && (data.getTotaly() < ymid))
	{
		cout << "in SE node " << endl;
		//SE = new prQuadLeaf<T>();
		SE = SE->insert(xmid, xpt2, ypt1, ymid, data);
		return this;
	}
	//creating new leaf node in upper right quadrant
	if((data.getTotalx() < xpt2) && (data.getTotaly() < ypt2) && (data.getTotalx() > xmid) && (data.getTotaly() > ymid))
	{
		cout << "in NE node " << endl;
		//NE = new prQuadLeaf<T>();
		NE = NE->insert(xmid, xpt2, ymid, ypt1, data);
		return this;
	}
	//else
	//cout << "failed insertion." << endl;
}

template <typename T>
prQuadNode<T>* prQuadInternal<T>::find(double xpt1, double xpt2, double ypt1, double ypt2, T& data)
{
	double xmid, ymid;	//point of origin within world
	
	xmid = (xpt1 + xpt2)/2;	//calculated midpoint of x
	ymid = (ypt1 + ypt2)/2;	// calculated midpoint of y
	cout << "in Internal retrieving data's coordinates:	"  << data.getTotaly() << "  " << data.getTotalx() << endl;
	cout << "x1:" << xpt1 << " " << "x2:" << xpt2 << " " << "y1:" << ypt1 << " " << "y2:" << ypt2 << endl;
	
	cout << "in prQuadInternal insert" << endl;
	//creating new leaf node in bottom left quadrant
	if((data.getTotalx() > xpt1) && (data.getTotaly() > ypt1) && (data.getTotalx() < xmid) && (data.getTotaly() < ymid))
	{
		return SW;
	}
	//creating new leaf node in upper left quadrant
	if ((data.getTotalx() > xpt1) && (data.getTotaly() < ypt2) && (data.getTotaly() > ymid) && (data.getTotalx() < xmid))
	{
		return NW;
	}
	//creating new leaf node in botton right quadrant
	if ((data.getTotalx() < xpt2) && (data.getTotaly() > ypt1) && (data.getTotalx() > xmid) && (data.getTotaly() < ymid))
	{
		return SE;
	}
	//creating new leaf node in upper right quadrant
	if((data.getTotalx() < xpt2) && (data.getTotaly() < ypt2) && (data.getTotalx() > xmid) && (data.getTotaly() > ymid))
	{
		return NE;
	}
	
}


template<typename T>
void prQuadInternal<T>::display(ostream& Out)
{
	Out << "prQuadInternal NE:  " << endl;
	NE->display(cout);
	Out << "prQuadInternal NW:  "<< endl;
	NW->display(Out);
	Out << "prQcoadInternal SW:  "<< endl;
	SW->display(Out);
	Out << "prQuadInternal SE:  " << endl;
	SE->display(Out);
}

template <typename T>
bool prQuadInternal<T>::isEmpty()
{
	return true;
}

template <typename T>
bool prQuadInternal<T>::isLeaf()
{
	return true;
}

template <typename T>
bool prQuadInternal<T>::remove()
{
	return true;
}

template <typename T>
void prQuadInternal<T>::clear()
{
	
}

template <typename T>
prQuadInternal<T>::~prQuadInternal()
{
	
}
#endif
