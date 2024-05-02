#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QIcon>
#include<QString>
#include<iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    //GUI Adjustments
    ui->label->setStyleSheet("font-family: 'Segoe UI', 'Roboto', sans-serif; font-size: 16px; color: #333;");
    QPixmap pic1("D:/FCIS/Sophomore/Second Semester/Data Structure/New folder/GuideMe/png-clipart-travel-agent-american-express-global-business-travel-united-states-travel-agency-blue-text-removebg-preview.png");
    int Wpic1 = ui->pic_label->width();
    int hpic1 =  ui->pic_label->height();
    ui->pic_label->setPixmap(pic1.scaled(Wpic1,hpic1,Qt::KeepAspectRatio));
    ui->label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->pic_label->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_2->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->label_3->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->AlgoLabel->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->TextWelcome->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //ComboBox Adjustments
    ui->BfsRB->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->DfsRB->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->statusbar->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->StartCombo->addItem("    ");
    ui->StartCombo->addItem(QIcon(":/rec/Beni_Suef_Governorate_New_Flag.svg.png"),"Beni Suif");
    ui->StartCombo->addItem(QIcon(":/rec/cairo-logo-2692B970B3-seeklogo.com.png"),"Cairo");
    ui->StartCombo->addItem(QIcon(":/rec/download.jpeg"),"Dahab");
    ui->StartCombo->addItem(QIcon(":/rec/Flag_of_Asyut_Governorate.png"),"Asyut");
    ui->StartCombo->addItem(QIcon(":/rec/f96c49d4-4142-43d4-9f26-075f3fda536c-transformed.png"),"Giza");
    ui->DestinationCombo->addItem("    ");
    ui->DestinationCombo->addItem(QIcon(":/rec/Beni_Suef_Governorate_New_Flag.svg.png"),"Beni Suif");
    ui->DestinationCombo->addItem(QIcon(":/rec/cairo-logo-2692B970B3-seeklogo.com.png"),"Cairo");
    ui->DestinationCombo->addItem(QIcon(":/rec/download.jpeg"),"Dahab");
    ui->DestinationCombo->addItem(QIcon(":/rec/Flag_of_Asyut_Governorate.png"),"Asyut");
    ui->DestinationCombo->addItem(QIcon(":/rec/f96c49d4-4142-43d4-9f26-075f3fda536c-transformed.png"),"Giza");




}

MainWindow::~MainWindow()
{
    delete ui;
}



float MainWindow::on_priceEdit_copyAvailable(bool b)
{

    QString priceString = ui->priceEdit->toPlainText();

     float price = priceString.toInt();

    return price;
}




void MainWindow::on_pushButton_clicked()
{
    bool b = true;

    on_priceEdit_copyAvailable(b);

    QString startLocation = on_StartCombo_activated(ui->StartCombo->currentIndex());
    QString destinationLocation = on_DestinationCombo_activated(ui->DestinationCombo->currentIndex());
    if(startLocation == destinationLocation){
        ui->statusbar->showMessage("PLEASE CHOOSE DIFFERENT START AND DESTINATION");
    }
    //the rest of the save and the opening of the second window

}


QString MainWindow::on_StartCombo_activated(int index)
{
    if(index==0){

        ui->statusbar->clearMessage();
        ui->statusbar->showMessage("Please choose a Starting Point");

        return 0;
    }
    else{

        ui->statusbar->clearMessage();
        QString text = ui->StartCombo->itemText(index);
        return text;

    }

}

QString MainWindow::on_DestinationCombo_activated(int index)
{
    if(index==0){

        ui->statusbar->clearMessage();
        ui->statusbar->showMessage("Please choose a Destination");

        return 0;


    }
    else{

        ui->statusbar->clearMessage();
        QString text = ui->StartCombo->itemText(index);
        return text;

    }
}


void MainWindow::on_BfsRB_clicked()
{

}


void MainWindow::on_DfsRB_clicked()
{

}

