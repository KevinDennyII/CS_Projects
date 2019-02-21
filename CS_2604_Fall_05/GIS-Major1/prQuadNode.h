#ifndef PRQUADNODE_HH
#define PRQUADNODE_HH

template <typename T> class prQuadNode{
private:
	//prQuadNode<T>* NE, *SE, *NW, *SW;
public:
	virtual bool isEmpty() = 0; // pure virtual function for determing if node is empty
	virtual bool isLeaf() = 0; // pure virtual function for determining a leaf node
	virtual prQuadNode<T>* insert(double, double, double, double, T&) = 0; // pure virtual function for inserting and creating new node
	virtual void display(ostream&) = 0; //pure virtual function for displaying node information
	virtual bool remove() = 0; // pure virtual function for deleting a node
	virtual void clear() = 0;  // pure virtual for clearing away a node
};
#endif