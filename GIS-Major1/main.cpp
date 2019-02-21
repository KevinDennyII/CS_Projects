#include<iostream>
#include<fstream>
#include<ios>
#include<string>
#include<iomanip>
#include<stdexcept>
        
using namespace std;
     
#include "Controller.h"
#include "BST.h"
#include "geoRecord.h"                                                           
#include "prQuadTree.h"

int main(int argc, char** arg){

	geoRecord* record;
	
	ofstream logger;

	logger.open("Log.txt");
	logger << "Programmer:    Kevin Denny" << endl;
	logger << "GIS Major Project 1" << endl;
	logger << endl;

	logger << "\tdB File: \t" << "MontgomeryCounty.txt"<< endl;
	logger << "\tscript File: \t" << "Script01.txt"<< endl;
	logger << "\tlog File: \t" <<"Log.txt"<< endl;
	   
	/*prQuadTree<geoRecord>* tree; 
	tree = new prQuadTree<geoRecord>("0810000W", "0790000W", "343000N", "363000N");
	tree->Insert(*record);*/     
	       
	Controller* con;
	con = new Controller("Script02.txt");
	con->intialize("MontgomeryCounty.txt");
	con->parseFuncts(logger,"Script02.txt");


	logger.close();
	return 0;
}
