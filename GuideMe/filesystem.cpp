#include "filesystem.h"
#include <fstream>
#include <iostream>
#include <string>

FileSystem *FileSystem::instance = 0;

FileSystem::FileSystem()
{
}

FileSystem *FileSystem::getInstance()
{
    if (instance == 0)
        instance = new FileSystem;
    return instance;
}

void FileSystem::deserialize(const string &filename)
{
    FileSystem obj;
    ifstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr
            << "Error: Failed to open file for reading."
            << endl;
        //return obj;
        return;
    }
    file.read(reinterpret_cast<char *>(&obj),
              sizeof(obj));
    file.close();
    cout << "Object deserialized successfully." << endl;
    instance = &obj;
}

void FileSystem::serialize(const string &filename)
{
    ofstream file(filename, ios::binary);
    if (!file.is_open())
    {
        cerr
            << "Error: Failed to open file for writing."
            << endl;
        return;
    }
    file.write(reinterpret_cast<const char *>(this),
               sizeof(*this));
    file.close();   
    cout << "Object serialized successfully." << endl;
}

void FileSystem::callOnExit()
{
    serialize("data.bin");
}











