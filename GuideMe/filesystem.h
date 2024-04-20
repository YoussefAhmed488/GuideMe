#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <fstream>
#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QObject>
#include <QDebug>

using namespace std;

class FileSystem : QObject
{
    Q_OBJECT

public slots:
    static void callOnExit();

private:
    FileSystem();
    static FileSystem* instance;
public:
    static FileSystem* getInstance();
    static void deserialize(const string& filename);
    static void serialize(const string& filename);
    // void serialize(const string& filename)
    // {
    //     ofstream file(filename, ios::binary);
    //     if (!file.is_open()) {
    //         cerr
    //             << "Error: Failed to open file for writing."
    //             << endl;
    //         return;
    //     }
    //     file.write(reinterpret_cast<const char*>(this),
    //                sizeof(*this));
    //     file.close();
    //     cout << "Object serialized successfully." << endl;
    // }

};

#endif // FILESYSTEM_H
