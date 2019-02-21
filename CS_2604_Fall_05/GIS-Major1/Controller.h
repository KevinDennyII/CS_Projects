#ifndef CONTROLLER_HH
#define CONTROLLER_HH
#include<fstream>
#include<iostream>
#include<string>
#include<new>
#include <vector>

using namespace std;

#include "FileManager.h"
#include "geoRecord.h"
#include "BST.h"

//class FileManager:
class geoRecord; 

class Controller{

private:
    FileManager *script;  // pointer to filemanager
    ifstream scripter; // output for log
	geoRecord *record; // pointer to geoRecord
	geoRecord *recs; // vector of geoRecord's
	BST<geoRecord>* fids;
	vector<geoRecord> recV;
	unsigned int cap;
	void quicksort(geoRecord** a, int lo, int hi);

protected:
		void dblSize();

public:
	void intialize(string file);
	void parseFuncts(ofstream& log, string file);
    void world(string file, ofstream& Out); // function for world command
	void geoCoord(string file, ofstream& Out); // function for what_is_at command, no radius specified
	void whatIs(string file, ostream& Out); // function for what_is command
	void radius(string& options, ostream& Out); // function for what_is_at command with radius specified
	void debug_location(string& options, ostream& Out ); // function for debug command
	void debug_fid(ostream& Out ); // function for debug command
	
	Controller(string scriptFile);
	Controller();
	~Controller();
};
#endif

