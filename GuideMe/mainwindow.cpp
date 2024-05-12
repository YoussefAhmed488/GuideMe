#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QIcon>
#include<QString>
#include"result_window.h"
#include<string>
#include"graph.h"
#include"edit_edge.h"
#include<QFontDatabase>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    //GUI Adjustments
    QPixmap pic1(":/png-clipart-travel-agent-american-express-global-business-travel-united-states-travel-agency-blue-text-removebg-preview.png");
    int Wpic1 = ui->pic_label->width();
    int hpic1 =  ui->pic_label->height();
    ui->pic_label->setPixmap(pic1.scaled(Wpic1,hpic1,Qt::KeepAspectRatio));

    QIcon icon(":/edit_icon_2.png"); // Provide the path to your icon file
    ui->editButton->setIcon(icon);
    QSize iconSize(25, 25);
    ui->editButton->setIconSize(iconSize);

    QStringList listGovernments;
    listGovernments.clear();
    for(auto node: graph->adj){
        listGovernments.append(QString::fromStdString(node.first));
    }
    listGovernments.removeOne(ui->StartCombo->currentText());
    ui->StartCombo->clear();
    ui->StartCombo->addItems(listGovernments);



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    bool bfs = ui->BfsRB->isChecked();
    bool dfs = ui->DfsRB->isChecked();
    bool dij = ui->radioButton->isChecked();
    int algo=0;
    bool falsePrice=false;

    QString text = ui->priceEdit->toPlainText();

    for (int i = 0; i < text.size(); ++i) {

        QChar currentChar = text.at(i); // Get the character at index i

        if (currentChar.isDigit()) {
            falsePrice=false;
        } else {

            falsePrice=true;
            break;

        }
    }

    string start = ui->StartCombo->currentText().toStdString();
    string dest = ui->DestinationCombo->currentText().toStdString();

    if(ui->priceEdit->toPlainText().isEmpty()){
        ui->statusbar->showMessage("PLEASE ENTER PRICE");
    }
    else if (!bfs && !dfs && !dij){
        ui->statusbar->showMessage("PLEASE SELECT ALGORITHM");
    }else if(falsePrice==true){

        ui->statusbar->showMessage("Please Enter a Valid Price");

    }else if(text.length() > 8 ){

        ui->statusbar->showMessage("Too Large, Please Enter a Valid Price");

    }

    else{

        if(bfs){
            algo = 1;
            graph->getAllPaths(start,dest,algo);

        }
        else if(dfs){
            algo = 2;
            graph->getAllPaths(start,dest,algo);

        }else{

            algo = 3;
            graph->getAllPaths(start,dest,algo);

        }

        MainWindow::hide();
        Result_Window r;

        r.on_next(ui->StartCombo->currentText(),ui->DestinationCombo->currentText(),ui->priceEdit->toPlainText());

        if(ui->radioButton->isChecked()){
            r.dijkestra();
        }else{
        r.setting_result();
        }
        r.setGraphState();
        r.setWindowTitle("Result Page");
        QIcon appIcon(":/search-results.png");
        r.setWindowIcon(appIcon);
        r.setModal(true);
        r.exec();
    }
    //the rest of the save and the opening of the second window

}

void MainWindow::on_StartCombo_currentIndexChanged(int index)
{
    QStringList listGovernments;
    listGovernments.clear();
    for(auto node: graph->adj){
        listGovernments.append(QString::fromStdString(node.first));
    }
    listGovernments.removeOne(ui->StartCombo->currentText());
    ui->DestinationCombo->clear();
    ui->DestinationCombo->addItems(listGovernments);

}


void MainWindow::on_editButton_clicked()
{
    MainWindow::hide();
    QIcon appIcon(":/edit_icon_2.png");
    Edit_Edge e;
    e.setWindowTitle("Edit Edges");
    e.setWindowIcon(appIcon);
    e.setModal(true);
    e.exec();
}
