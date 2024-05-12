#include "filereader.h"
#include "mainwindow.h"
#include <QApplication>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QCoreApplication>
#include <QString>
#include <QDebug>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile stylesheetFile(":/Darkeum.qss");
    stylesheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(stylesheetFile.readAll());
    a.setStyleSheet(styleSheet);

    FileReader f;
    f.readFile();
    MainWindow w;
    w.setWindowTitle("Welcome Page");
    QIcon appIcon(":/home-page.png");
    w.setWindowIcon(appIcon);
    w.setGeometry(270, 70, 1065, 250);
    w.show();

    return a.exec();
}










