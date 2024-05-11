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
    //ui->toolButton->setIcon(QIcon(":/edit_icon_2.png"));
    QSize iconSize(25, 25); // Adjust the size as needed
    //ui->toolButton->setIconSize(iconSize);
    ui->backtoolButton->setIcon(QIcon(":/back-button.png"));
    ui->backtoolButton->setIconSize(iconSize);
    ui->textEdit->clear();


}

void Result_Window::setGraphState(){

    if(graph->isComplete()==true){
        ui->label_2->setText("Graph is Complete");
    }
    else
        ui->label_2->setText("Graph is not Complete");

    if(graph->isConnected()==true){
        ui->label_3->setText("Graph is Connected");
    }
    else
        ui->label_3->setText("Graph is not Connected");


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


void Result_Window::on_toolButton_clicked()
{
    Result_Window::hide();
    QIcon appIcon(":/edit_icon_2.png");
    Edit_Edge e;
    e.setWindowTitle("Edit Edges");
    e.setWindowIcon(appIcon);
    e.setModal(true);
    e.exec();
}


void Result_Window::on_backtoolButton_clicked()
{
    Result_Window::hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setGeometry(600, 250, 0, 0);
    mainWindow->show();
}
void Result_Window::on_next(QString from,QString to,QString price){
    ui->FromResult->setText(from);
    ui->ToResult->setText(to);
    ui->PriceResult->setText(price);
}

