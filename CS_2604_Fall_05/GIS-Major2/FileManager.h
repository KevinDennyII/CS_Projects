#ifndef FILEMANAGER_HH
#define FILEMANAGER_HH

#include<fstream>
#include<string>
#include<iostream>

using namespace std;

class FileManager{

private:
   ifstream Log;
   string scriptholder;

public:
    bool CommandArg(string& command, string& item1, string& item2, string& item3, string& item4, string item5);

        FileManager(string scriptFile);

    FileManager();
        ~FileManager();
};



#endif
