#include "result_window.h"
#include "ui_result_window.h"
#include<QIcon>
#include"edit_edge.h"
#include "mainwindow.h"
#include<QString>
#include<string>
using namespace std;
Result_Window::Result_Window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result_Window)

{
    ui->setupUi(this);

    QSize iconSize(25, 25);
    ui->backtoolButton->setIcon(QIcon(":/back-button.png"));
    ui->backtoolButton->setIconSize(iconSize);
    ui->textEdit->clear();

}

void Result_Window::setGraphState(){

    if(graph->isComplete()==true){
        ui->label_2->setText("Complete");
    }
    else
        ui->label_2->setText("Not  Complete");

    if(graph->isConnected()==true){
        ui->label_3->setText("Connected");
    }
    else
        ui->label_3->setText("Not  Connected");


}
void Result_Window::setting_result() {

    if((ui->PriceResult->text()).toInt() > graph->road.begin()->first){
    for (auto it : graph->road) {

        QString priceText = ui->PriceResult->text();
        std::string price = priceText.toStdString();


        if(stoi(price)<it.first){
            continue;
        }

        for (auto i : it.second ) {


            QString qPath = QString::fromStdString("From " + i.startNode + " to " + i.endNode + ", taking a " + i.vehicle + " costs " + std::to_string((int)i.cost))+"  ";

            ui->textEdit->insertPlainText(qPath);

    }

    ui->textEdit->insertPlainText(QString::fromStdString(" Which will cost you totally " +to_string(it.first))+"  ");
    ui->textEdit->append(QString::fromStdString("\n"));

    }
    }
    else{
        ui->textEdit->insertPlainText("Low Price");
    }

    graph->road.clear();

}

void Result_Window::dijkestra(){

    QString priceText = ui->PriceResult->text();
    int number = priceText.toInt();
    if(number >= graph->dijkestraCost){

        QString qPath = QString::fromStdString(graph->dijkestraRoad);
    ui->textEdit->insertPlainText(qPath);

    QString costString = QString::number(graph->dijkestraCost);

    ui->textEdit->insertPlainText(" Which will cost you totally " + costString+"  "+"(This is The Shortest Path)");

    ui->textEdit->append(QString::fromStdString("\n"));

    graph->dijkestraRoad.clear();

    }else
        ui->textEdit->insertPlainText("Price Entered is too low");
}

Result_Window::~Result_Window()
{
    delete ui;
}


void Result_Window::on_backtoolButton_clicked()
{
    Result_Window::hide();
    MainWindow *mainWindow = new MainWindow();
    QIcon appIcon(":/home-page.png");
    mainWindow->setWindowIcon(appIcon);
   mainWindow->setWindowTitle("Welcome Page");
    mainWindow->setGeometry(270, 70, 1065, 250);
    mainWindow->show();
}
void Result_Window::on_next(QString from,QString to,QString price){
    ui->FromResult->setText(from);
    ui->ToResult->setText(to);
    ui->PriceResult->setText(price);
}

