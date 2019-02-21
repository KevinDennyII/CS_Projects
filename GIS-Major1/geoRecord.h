/*
 *  geoRecord.h
 *  GIS-PRQuad
 *
 *  Created by Kevin  Denny on 10/12/05.
 *
 */
#ifndef GEORECORD_HH
#define GEORECORD_HH

#include<fstream>
#include<iostream>
#include<string>
#include<new>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class geoRecord{

private: 
	unsigned int offset; //variable for offset of file
	string fid; //variable for FID
	int fileid;
	string name; // variable for name
	string state; // variable for state
	string cell; // variable for cell
	string county;//
	double xcoord_dms; //variable for x-coordinates in degrees, 
	double ycoord_dms; //variable for y-coordinates
	double totalx;
	double totaly;
	
public:
	void setOffset(unsigned int); // setting offset of file
	int getOffset(); //function that returns offset
	
	void setFid(string); //settiing fid of each record
	string getFid()const; //fuction that returns string version of fid
	int intFid();
	
	void setName(string);//sets name 
	string getName()const;
	
	void setState(string);//set state
	string getState()const;
	
	void setCounty(string);//set county
	string getCounty()const;
	
	void setCell(string);// set cell
	string getCell()const;
	
	void setCoordx(double); //setting x coordinate variables
	void setCoordy(double);
	double getCoordx(); //function that returns x-coordinate
	double getCoordy(); //function that return y-coordinate
	void totalSecx(double); //converting x coordinate to seconds
	void totalSecy(double); //converting y coordinate to seconds
	double getTotalx();
	double getTotaly();
	
	
	friend ostream& operator<<(ostream&, geoRecord*); //overloading of extraction operator
	friend ostream& operator<<(ostream&, geoRecord); //overloading of extraction operator
	bool operator>(const geoRecord& rhs)const;
	bool operator<(const geoRecord& rhs)const;
	bool operator==(geoRecord& rhs);
	
	geoRecord();
	~geoRecord();
	
};
#endif

