#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include<QIcon>
#include<QString>
#include<iostream>
#include"result_window.h"
#include<string>
#include"graph.h"
#include"edit_edge.h"
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
    ui->radioButton->setStyleSheet("background-color: rgba(255, 255, 255, 0);");

    //ComboBox Adjustments
    ui->BfsRB->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->DfsRB->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
    ui->statusbar->setStyleSheet("background-color: rgba(255, 255, 255, 0);");
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

    string start = ui->StartCombo->currentText().toStdString();
    string dest = ui->DestinationCombo->currentText().toStdString();

    if(ui->priceEdit->toPlainText().isEmpty()){
        ui->statusbar->showMessage("PLEASE ENTER PRICE");
    }
    else if (!ui->BfsRB->isChecked() && !ui->DfsRB->isChecked() && !ui->radioButton->isChecked()){
        ui->statusbar->showMessage("PLEASE SELECT ALGORITHM");
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

        // sort(road.begin(),road.end());

        r.setting_result();

        r.setWindowTitle("Result");
        r.setModal(true);
        r.exec();
    }
    //the rest of the save and the opening of the second window

}



void MainWindow::on_BfsRB_clicked()
{

}

void MainWindow::on_DfsRB_clicked()
{

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
