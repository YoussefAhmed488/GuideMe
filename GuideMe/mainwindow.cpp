#include "mainwindow.h"
//#include "file_mangment.h"
#include "file_mangment.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Read_clicked()
{
    File_Mangment file;
    ui->textEdit->setText(file.read());
}


void MainWindow::on_pushButton_Write_clicked()
{
    QFile file("Test.txt");
    if(file.open(QIODevice::Truncate | QIODevice::ReadWrite))
    {
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
    }
    file.close();
}

