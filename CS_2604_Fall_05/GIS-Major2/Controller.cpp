#include<sstream>
#include<stdlib.h>

#include "Controller.h"



/////////////////////////////////////////////////////////
//                ****CONSTRUCTORS****
//
//
/*DEFAULT CONSTRUCTOR for FileManager class.

Parameters:	none
Pre:		none
Post:		none
*/
Controller::Controller()
{
	script = new FileManager("Script02.txt");
	record = new geoRecord();
	fids = new BST<geoRecord>();
	//cap = 10000;
	//recs = new geoRecord[cap];
	
}

Controller::Controller(string scriptFile)
{
	record = new geoRecord();
	fids = new BST<geoRecord>();
	//cap = 10000;
	//recs = new geoRecord[recV.size()];
	script = new FileManager(scriptFile);
	

}

//////////////////////////////////////////////////////////////// intialize()
// This fuction places the contents of organism and accession into
// the skiplist data structure by reading in the input file
//
// Parameters:	string file
//
// Pre:       none
//
// Post:      accession codes are inserted into the AVL tree and organism are inserted
//			  into the Hash Table
//
// Returns:	  none
//
// Called by: parseFuncts
// Calls: none
void Controller::intialize(string file)
{
	ifstream Log(file.c_str());
	
	string data;//string for character array
	string gisInfo;//string for capture of data line
	char dataIn[sizeof(gisInfo)];//character array for data elements of each line
	unsigned int read_offset;//variable for file offset
	
	//grabbing each line of the 
	read_offset = Log.tellg();
	record->setOffset(read_offset);
	cout << "offset:" << record->getOffset() << endl;
	getline(Log, gisInfo, '\n');
	
	
	int x = 1;
	while(!Log.eof())
	{
		//reading & setting the offset of the file
	
	if(read_offset == 0)
	{
		read_offset = Log.tellg();
	}
	else
	{
		read_offset = Log.tellg();
		record->setOffset(read_offset);
		cout << "offset: " << record->getOffset() << endl;
	}

		data = dataIn;
		
		//reading & setting file Id
		getline(Log, data, '|'); 
		record->setFid(data);
		cout<<"FID: "<< record->getFid() << endl;
		
		getline(Log, data, '|'); 
		record->setState(data);
		cout<<"State: "<< record->getState() << endl;
		
		getline(Log, data, '|'); 
		record->setName(data);
		cout<<"Feature name: "<< record->getName() << endl;
		
		
		getline(Log, data, '|');
		cout<<"Feature type: "<< data << endl;
		string feat_type = data;
		
		getline(Log, data, '|');
		record->setCounty(data);
		cout<<"County name: " << record->getCounty() << endl;
		
		
		getline(Log, data, '|');
		cout<<"State code: "<< data << endl;
		string state_code = data;
		
		getline(Log, data, '|');
		cout <<"County code: " << data << endl;
		string county_code = data;
		
		
		
		//reading & setting primary latitudes in degree, minutes, seconds
		getline(Log, data, '|');
		istringstream iss1, iss2, iss3, iss4, iss5, iss6;
		string lat_dir = data.substr(data.length()-1);
		
		string ydegrees = data.substr(0,2); //parsing degrees from coordinate at 0 position
		string yminutes = data.substr(2,2); // parsing minutes from coordinate at 2nd position
		string yseconds = data.substr(4,2); //parsing seconds from coordinate 4th position
		
		double ydeg, ymin, ysec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss1.str(ydegrees);
		iss1 >> ydeg;
		ydeg = ydeg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss2.str(yminutes);
		iss2 >> ymin;
		ymin = ymin*60;
		
		//converting string seconds to double
		iss3.str(yseconds);
		iss3 >> ysec;
				
		double ytotal = (ydeg+ymin+ysec);
		double latdms = atoi(data.c_str());
		record->setCoordy(latdms);
		cout<<"Primary latitude(DMS): "<< record->getCoordy() << endl;
		record->totalSecy(ytotal);
		cout <<"Total Seconds lat(dms):" << record->getTotaly() << endl;
		
		
		
		//reading & setting primary latitudes in degree, minutes, seconds
		getline(Log, data, '|');
		
		string long_dir = data.substr(data.length()-1);
		
		string xdegrees = data.substr(1,2); //parsing degrees from coordinate at 0 position
		string xminutes = data.substr(3,2); // parsing minutes from coordinate at 2nd position
		string xseconds = data.substr(5,2); //parsing seconds from coordinate 4th position
		
		double xdeg, xmin, xsec;//creating double variables for degrees, minutes & seconds
		
		//converting string degree to double and then converting to seconds
		iss4.str(xdegrees);
		iss4 >> xdeg;
		xdeg = xdeg*3600;
		
		//converting string minutes to double and then converting to seconds
		iss5.str(xminutes);
		iss5 >> xmin;
		ymin = xmin*60;
		
		//converting string seconds to double
		iss6.str(xseconds);
		iss6 >> xsec;
		
		double xtotal = (xdeg+xmin+xsec);
		double longdms = atoi(data.c_str());
		record->setCoordx(longdms);
		cout<<"Primary longitute(DMS): "<< record->getCoordx() << endl;
		record->totalSecx(xtotal);
		cout <<"Total Seconds long(dms):" << record->getTotalx() << endl;
		

		
		//reading & setting primary latitudes in decimal format
		getline(Log, data, '|');
		cout<<"Primary latitude(decimal format): "<< data << endl;
		string lat_dec = data;
		
		//reading & setting primary longitudes in decimal format
		getline(Log, data, '|');
		cout<<"Primary longitude(decimal format): "<< data << endl;
		string long_dec = data;
		
		//skipping pipe objects to obtain the cell of the geoRecord
		int i = 0;
		while(i<6)
		{
			i++;
			getline(Log, data, '|');
			
		}
		getline(Log, data, '|');
		
		//obtaining the cell information
		getline(Log, data, '\n');
		record->setCell(data);
		cout<<"Cell: "<< record->getCell() << endl;
		cout<<endl;
		
		recV.push_back( *record );
		
		//recs[x] = *record;
		
		fids->Insert(*record);
		x++;
	
	}
	
	int size = recV.size();
	recs = new geoRecord[recV.size()];
	geoRecord* recs[recV.size()];
	cout << "vector size:" << recV.size() << endl;
	for( int x = 0; x < recV.size(); x++ )
	{
		
		recs[x] = &recV[x];
	}
	
	quicksort(recs, 0, recV.size()-1);
	
	//fids->mapSortedListToBST(0, recV.size()-1 , recs, fids);
	
	Log.close();

}


/*Helper Function
*
*
*
*
*
*
*/
void Controller::quicksort(geoRecord** a, int lo, int hi)
{
	//  lo is the lower index, hi is the upper index
	//  of the region of array a that is to be sorted
	cout << "in quick sort, record is: " << a[lo]->getFid() << endl;
    int i=lo, j=hi;
	geoRecord* h;
    geoRecord* x = (a[(lo+hi)/2]);

    //  partition
    do
    {
        while (a[i]->getFid()<a[(lo+hi)/2]->getFid()) i++; 
        while (a[j]->getFid()>a[(lo+hi)/2]->getFid()) j--;
        if (i<=j)
        {
            h=a[i]; a[i]=a[j]; a[j]=h;
            i++; j--;
        }
    } while (i<=j);
	
    //  recursion
    if (lo<j) quicksort(a, lo, j);
    if (i<hi) quicksort(a, i, hi);
}

//////////////////////////////////////////////////////////////// parseFuncts()
// This is my parser for each of the commands in a given script file
//
// Parameters:	ofstream& log
//
// Pre:       none
//
// Post:      input file initalized
//
// Returns:   none
//
// Called by: main()
// Calls: none
void Controller::parseFuncts(ofstream& log, string file)
{

	int counter = 1;
	//ifstream reader;
	//reader.open(file.c_str());
	string command, item1, item2, item3, item4;
	//intialize(file);
	string Line = "--------------------------------------------------------------";

	log << Line << endl;

	script->CommandArg(command, item1, item2, item3, item4, file); 
	// read in first command
	
	// while input does not equal "quit", read in the commands and call the
	// correspoding functions
	while ( command != "quit" )
	{
		if( command == "world" )
		{
			log << "Command\t  " << counter << ":\t" << command;
			log << '\t' << item1 << endl;
		
			log << Line << endl;
		}
		else if( command == "what_is_at" )
		{
			log << "Command\t  " << counter << ":\t" << command;
			log << '\t' << item1 << endl;
			
			log << Line << endl;
		}
		else if (command == "what_is")
		{
			log << "Command\t  " << counter << ":\t" << command;
			log << '\t' << item1 << endl;
			whatIs(item1, log);
			log << Line << endl;
		}
		else if( command == "what_is_within" )
		{
			log << "Command\t  " << counter << ":\t" << command;
			log << '\t' << item1 << endl;
			log << endl;
			log << Line << endl;
		}
		else if( command == "debug" )
		{
			log << "Command\t  " << counter << ":\t" << command;
			if(item1 == "FID")
			{
				log << '\t' << item1 << endl;
				debug_fid(log);
				log << endl;
			}
			else if(item1 == "location")
			{
				log << '\t' << item1 << endl;
				
				log << endl;
			} 
			
			log << Line << endl;
		}

		else
		{
			log << "Unknown Command Man!" << endl << Line << endl;
			counter--;
		}
		
		script->CommandArg(command, item1, item2, item3, item4, file);
		counter++;
	}
	log << "Command\t  " << counter << ":\t" << command;
	log << endl; 
	log << "Exiting program!" << endl;
	log << Line << endl;
	return;
}


//////////////////////////////////////////////////////////////// world()
// This function specifies the coordinates space to be modeled
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      
//
// Returns:   none
//
// Called by: none
// Calls: none
void Controller::world(string file, ofstream& Out)
{
	
}

//////////////////////////////////////////////////////////////// geoCoord()
// This function logs all the date fields, properly labeled in every GIS record that matches a given coordinate
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      
//
// Returns:   none
//
// Called by: none
// Calls: none
void Controller::geoCoord(string file, ofstream& Out)
{	
	
}

//////////////////////////////////////////////////////////////// whatIs()
// This function logs all the date fields in teh unique GIS record that matches the given
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      
//
// Returns:   none
//
// Called by: main()
// Calls: none
void Controller::whatIs(string fileId, ostream& Out)
{
	//dummy record for searching for specicifed fileid
	geoRecord* dummy = new geoRecord();
	dummy->setFid(fileId);
	
	//for record found
	record = fids->Find(*dummy);
	
	if(record != NULL )
	{
		Out << endl;
		//displaying elements of record found
		Out << "FID:" << '\t' << record->getFid() << endl; 
		Out << "Name:" << '\t' << record->getName() << endl;       
		Out << "State:" << '\t' << record->getState() << endl;      
		Out << "County:" << '\t' << record->getCounty() << endl;      
		Out << "Longitude:" << '\t' << record->getCoordx()<<"W"<<endl; 
		Out << "Latitude:" << '\t' << record->getCoordy()<<"N"<< endl;   
		Out << "Src Long:" << '\t' << endl;   
		Out << "Src Lat:"  << '\t' << endl;  
		Out << "Elevation:" << '\t' << endl;   
		Out << "Cell:" << '\t' << record->getCell() << endl; 
	
		Out << endl;
		Out << endl;
	}
	else
	{
		Out << endl;
		Out << " Oh no!  Can not find File ID!" << endl;
		Out << endl;
	}

}

//////////////////////////////////////////////////////////////// radius()
// This function logs all the date fields, properly labeled in every GIS record whose location lies within a 
// circle
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      debug command executed
//
// Returns:   none
//
// Called by: main()
// Calls: none
void Controller::radius(string& options, ostream& Out )
{
	

}

//////////////////////////////////////////////////////////////// debug()
// This function executes when the debug command is read in from the
// scrip file
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      debug command executed
//
// Returns:   none
//
// Called by: main()
// Calls: none
void Controller::debug_location(string& options, ostream& Out )
{
	

}

//////////////////////////////////////////////////////////////// debug()
// This function executes when the debug command is read in from the
// scrip file
//
// Parameters:	ofstream& Out
//
// Pre:       none
//
// Post:      debug command executed
//
// Returns:   none
//
// Called by: main()
// Calls: none
void Controller::debug_fid(ostream& Out )
{
	fids->Display(Out);
}

//////////////////////////////////////////////////////////////// dblSize()
// This function increases the size of the array as it reaches its capacity
//
// Parameters:  none
//
// Pre:       none
//
// Post:
//
// Returns:
//
// Called by:
// Calls: none
void Controller::dblSize()
{
                // initializing new double-sized array
   // geoRecord* newArray = new geoRecord[cap*2];

  /*  for(unsigned int i = 0; i < cap; i++)
    {
        // setting original array pointer to new array pointer
        newArray[i] = accPtrs[i];
        accPtrs[i] = NULL;
    } */

  /*  cap = cap*2;
    delete [] accPtrs;
    accPtrs = newArray;//reassigning new resized array */
}

/////////////////////////////////////////////////////////
//                ****DECONSTRUCTORS****
//
//
Controller::~Controller()
{
	scripter.close();
}
