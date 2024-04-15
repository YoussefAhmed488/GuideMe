#include "file_mangment.h"
using namespace std;

File_Mangment::File_Mangment() {}

void File_Mangment::write()
{
    QFile file("Test.txt");
    string s;
    if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        s = "I am Nigga A";
        QTextStream stream(&file);
        for(int i =0 ;i<s.size();i++)
        {
            stream << s[i];
        }
    }
    file.close();
    return;
}
QString File_Mangment::read()
{
    QFile file("Test.txt");
    QTextStream stream(&file);
    QString file_data;
    if(file.open(QIODevice::ReadOnly))
    {
        while(stream.atEnd() == false)
        {
            file_data += stream.readLine() + "\n";
        }
    }
    return file_data;
}
