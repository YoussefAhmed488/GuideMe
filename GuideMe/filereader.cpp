#include "filereader.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

FileReader::FileReader()
{

}

void FileReader::readFile(string fileName)
{
    ifstream file(fileName);
    string content;
    //file.open(fileName);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            content += line + "\n";
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file"; // Error if unable to open file
        return;
    }

    cout << "Content of the file:\n" << content << endl; // Output the content
}




















