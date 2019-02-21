#include "FileManager.h" 

 ///////////////////////////////////////////////////////// 
 //                ****CONSTRUCTORS**** 
 // 
 // 
 /*DEFAULT CONSTRUCTOR for FileManager class.

Parameters:	none
Pre:		none
Post:		none
*/ 
FileManager::FileManager()
{

}

 /*CONSTRUCTOR for FileManager class.

Parameters:	none
Pre:		none
Post:		none
*/ 
FileManager::FileManager(string LogFile)
{
	 Log.open(LogFile.c_str()); 
	 scriptholder = LogFile; 
}

 //////////////////////////////////////////////////////////////// setAccession() 
 //  
 // 
 // Parameters:	string Code 
 // 
 // Pre:       none 
 // 
 // Post:       
 // 
 // Returns:   pointer to accesion index 
 // 
 // Called by:  
 // Calls: none 
 bool  FileManager::CommandArg(string& command, string& item1, string& item2, string& item3, string& item4, string scriptholder)
{
	char test  = Log.peek();
	Log.clear();
	string trash;
	
	 while (test ==  ';' )
	{
		getline(Log, trash);
		test = Log.peek();
		Log.clear();
	}

		getline(Log, command,  '\t' );
    
     if  (command ==  "world" )
    {
       getline(Log, item1,  '\n' );
    }
	 if  (command ==  "what_is_at" )
    {
       getline(Log, item1,  '\n' );
	   
    }
    	 if  (command ==  "what_is" )
    {
        getline(Log, item1,  '\n' );
    }  
	 if  (command ==  "what_is_within" )
    {
        getline(Log, item1,  '\n' );
    }  
     if (command ==  "debug"  )
    {
    	getline(Log, item1,  '\n' );
    }
	 if (command ==  "quit" )
    {
		 
    }

    if(!Log)
        return false;
     else  
        return true;
}

///////////////////////////////////////////////////////// 
//                ****DECONSTRUCTOR****
//                     
//
FileManager::~FileManager()
{
     Log.close();    
}
