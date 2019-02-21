#ifndef PRQUADTREE_HH
#define PRQUADTREE_HH
#include<new>
#include<string>
#include<sstream>
#include<iostream>

using namespace std;

#include "prQuadNode.h"
#include "Singleton.h"

template <typename T> class prQuadTree{ 
public: 
	prQuadTree(string xMinimum, string xMaximum, 
			string yMinimum, string yMaximum); 
	double conSecs(string plotter);
	bool Insert(T& Elem); 
	bool Delete(const T& Elem); 
	T* const Find(const T& Elem); 
	const T* const Find(const T& Elem) const; 
	void Display(std::ostream& Out) const; 
	void Clear(); 
	~prQuadTree(); 
private: 
	prQuadNode<T>* Root;
	string xMin, xMax, yMin, yMax; 
	double minx, maxx, maxy, miny;
	
};

template <typename T> 
prQuadTree<T>::prQuadTree(string xMinimum, string xMaximum, string yMinimum, string yMaximum)
{
	minx = 0.0;
	maxx = 0.0;
	maxy = 0.0;
	miny = 0.0;
	Root = Singleton<T>::instance(); // setting root to instance of a singleton
	xMin = xMinimum;
	xMax = xMaximum;
	yMin = yMinimum;
	yMax = yMaximum;
	
	cout << " inside Prquadtree insert "<<endl;
	minx = conSecs(xMin);
	cout << minx << endl;
	miny = conSecs(yMin);
	cout << miny << endl;
	maxx = conSecs(xMax);
	cout << maxx << endl;
	maxy = conSecs(yMax);
	cout << maxy << endl;
}

template <typename T>
double prQuadTree<T>::conSecs(string plotter)
{

	string direction = plotter.substr(plotter.length()-1);//storing direction for comparison

	//double coord;// variable double for coordinate
	
	//converting a string to a double
	istringstream iss1a, iss1b, iss1c, iss2a, iss2b, iss2c, iss3a, iss3b, iss3c, iss4a, iss4b, iss4c;
	//iss.str(plotter);
	//iss >> coord;
	
	//checking for north latitude coordinate
	if(direction == "N")
	{
		
		string degrees = plotter.substr(0,2); //parsing degrees from coordinate at 0 position
		string minutes = plotter.substr(2,2); // parsing minutes from coordinate at 2nd position
		string seconds = plotter.substr(4,2); //parsing seconds from coordinate 4th position
		cout << "Consecs N:" << "	degrees:"<<degrees<< "	minutes:"<<minutes<<"	seconds:"<<seconds<<endl;
		
		double deg, min, sec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss1a.str(degrees);
		iss1a >> deg;
		deg = deg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss1b.str(minutes);
		iss1b >> min;
		min = min*60;
		
		//converting string seconds to double
		iss1c.str(seconds);
		iss1c >> sec;
		
		double total = deg+min+sec;
		return (total);
	}
	
	//checking for south latitude coordinates
	else if(direction == "S")
	{
		string degrees = plotter.substr(0,2); //parsing degrees from coordinate at 0 position
		string minutes = plotter.substr(2,2); // parsing minutes from coordinate at 2nd position
		string seconds = plotter.substr(4,2); //parsing seconds from coordinate 4th position
		
		double deg, min, sec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss2a.str(degrees);
		iss2a >> deg;
		deg = deg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss2b.str(minutes);
		iss2b >> min;
		min = min*60;
		
		//converting string seconds to double
		iss2c.str(seconds);
		iss2c >> sec;
		
		double total = (deg+min+sec)*(-1);
		return (total);

	}
	
	//checking for west longitude coordinates
	else if(direction == "W")
	{
		string degrees = plotter.substr(1,2); //parsing degrees from coordinate at 0 position
		string minutes = plotter.substr(3,2); // parsing minutes from coordinate at 2nd position
		string seconds = plotter.substr(5,2); //parsing seconds from coordinate 4th position
		cout << "Consecs W:" << "	degrees:"<<degrees<< "	minutes:"<<minutes<<"	seconds:"<<seconds<<endl;
		double deg, min, sec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss3a.str(degrees);
		iss3a >> deg;
		deg = deg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss3b.str(minutes);
		iss3b >> min;
		min = min*60.0;
		
		//converting string seconds to double
		iss3c.str(seconds);
		iss3c >> sec;
		cout<< " W conversion:	" << "deg:"<<deg<<"	min:"<<min<<"	sec:"<<sec<< endl;
		
		double total = deg+min+sec;
		return (total);

	}
	
	else
	{	
		string degrees = plotter.substr(1,2); //parsing degrees from coordinate at 0 position
		string minutes = plotter.substr(3,2); // parsing minutes from coordinate at 2nd position
		string seconds = plotter.substr(5,2); //parsing seconds from coordinate 4th position
		
		double deg, min, sec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss4a.str(degrees);
		iss4a >> deg;
		deg = deg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss4b.str(minutes);
		iss4b >> min;
		min = min*60;
		
		//converting string seconds to double
		iss4c.str(seconds);
		iss4c >> sec;
		
		double total = (deg+min+sec)*(-1);
		return (total);
		}

}

template <typename T>
bool prQuadTree<T>::Insert(T& data)
{
	
	
	Root = Root->insert(minx, maxx, miny, maxy, data); //inserting data into a node
	return true;
}

template <typename T>
bool prQuadTree<T>::Delete(const T& data)
{
	return true;
}

template <typename T>
T* const prQuadTree<T>::Find(const T& data)
{
	return data;
}

template <typename T>
const T* const prQuadTree<T>::Find(const T& data) const
{
	return data;
}

template <typename T>
void prQuadTree<T>::Display(std::ostream& Out) const
{
	Root->display(Out);
}

template <typename T>
prQuadTree<T>::~prQuadTree()
{

}
#endif