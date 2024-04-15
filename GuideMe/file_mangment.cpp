#include "file_mangment.h"
#include <string>

using namespace std;

vector<string> File_Mangment::data_file;

File_Mangment::File_Mangment() {}

void File_Mangment::write()
{
    QFile file("Test.txt");
    string s;
    if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        s = "I am Nigga Man";
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
    QFile file("TransportationMap.txt");
    QTextStream stream(&file);
    QString file_data,s;
    if(file.open(QIODevice::ReadOnly))
    {
        s = stream.readLine();
        int loop_size = s.toInt();
        data_file.resize(loop_size);
        for (int i = 0; i < loop_size; ++i) {
            s = stream.readLine()+'\n';
            file_data += s;
            data_file[i] = s.toStdString();
        }
    }
    return file_data;
}
