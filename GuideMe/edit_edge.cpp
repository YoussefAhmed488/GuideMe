#include "edit_edge.h"
#include "ui_edit_edge.h"
#include "result_window.h"
#include "mainwindow.h"
#include <sstream>
//using namespace std;

Edit_Edge::Edit_Edge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Edge)
{
    ui->setupUi(this);
    on_combobox();
    on_start();
    on_connect();
    ui->TocomboBox->setCurrentIndex(1);

}

void Edit_Edge::on_comboBox_currentIndexChanged()
{
    ui->TocomboBox->clear();
    on_ToCombobox();
}
void Edit_Edge::on_add()
{
    ui->AddWidget->show();
    Added = true;
}
void Edit_Edge::on_click1()
{
    ui->TrainWidget->hide();
    TrainVisibility = false;
    string from = ui->FromcomboBox->currentText().toStdString();

    string to = ui->TocomboBox->currentText().toStdString();

    string vehicle = ui->trainLabel->text().toStdString();

    graph->deleteEdge(from,to,vehicle);
}
void Edit_Edge::on_click2()
{
    ui->BusWidget->hide();
    BusVisibility = false;
    string from = ui->FromcomboBox->currentText().toStdString();

    string to = ui->TocomboBox->currentText().toStdString();

    string vehicle = ui->busLabel->text().toStdString();

    graph->deleteEdge(from,to,vehicle);

}
void Edit_Edge::on_click3()
{
    ui->MicrobusWidget->hide();
    MicrobusVisibility = false;
    string from = ui->FromcomboBox->currentText().toStdString();

    string to = ui->TocomboBox->currentText().toStdString();

    string vehicle = ui->microbusLabel->text().toStdString();

    graph->deleteEdge(from,to,vehicle);
}
void Edit_Edge::on_click4()
{
    ui->MetroWidget->hide();
    MetroVisibility = false;
    string from = ui->FromcomboBox->currentText().toStdString();

    string to = ui->TocomboBox->currentText().toStdString();

   string vehicle = ui->metroLabel->text().toStdString();

    graph->deleteEdge(from,to,vehicle);
}
void Edit_Edge::on_click5()
{
    ui->UberWidget->hide();
    UberVisibility = false;
    string from = ui->FromcomboBox->currentText().toStdString();

    string to = ui->TocomboBox->currentText().toStdString();

    string vehicle = ui->uberLabel->text().toStdString();

    graph->deleteEdge(from,to,vehicle);
}

void Edit_Edge::on_submit()
{
    ui->FromcomboBox->setCurrentIndex(0);
    on_start();
    on_ToCombobox();
    ui->AddText->clear();
    ui->AddcomboBox->setCurrentIndex(0);
    Added = false;
}

void Edit_Edge::on_update()
{
    if (Added && !(ui->AddText->text().isEmpty())) {
        if (ui->AddcomboBox->currentText() == "Train") {
            ui->TrainWidget->show();

            ui->TrainText->setText(ui->AddText->text());


            string to = ui->FromcomboBox->currentText().toStdString();

            string from = ui->TocomboBox->currentText().toStdString();

            string vehicle = ui->AddcomboBox->currentText().toStdString();

            string price = ui->AddText->text().toStdString();

            int pr;
            std::stringstream(price) >> pr;
            if(TrainVisibility){
            graph->updateEdgeCost(from,to,vehicle,pr);
            }
            else{
            graph->addEdge(from,to,vehicle,pr);
            }
            TrainVisibility = true;
        }
        else if (ui->AddcomboBox->currentText() == "Bus") {
            ui->BusWidget->show();

            ui->BusText->setText(ui->AddText->text());


            string to = ui->FromcomboBox->currentText().toStdString();

            string from = ui->TocomboBox->currentText().toStdString();

            string vehicle = ui->AddcomboBox->currentText().toStdString();

            string price = ui->AddText->text().toStdString();

            int pr;
            std::stringstream(price) >> pr;

            if(BusVisibility){
                graph->updateEdgeCost(from,to,vehicle,pr);
            }
            else{
                graph->addEdge(from,to,vehicle,pr);
            }
            BusVisibility = true;


        }
        else if (ui->AddcomboBox->currentText() == "Microbus") {
            ui->MicrobusWidget->show();

            ui->MicrobusText->setText(ui->AddText->text());
            string to = ui->FromcomboBox->currentText().toStdString();

            string from = ui->TocomboBox->currentText().toStdString();

            string vehicle = ui->AddcomboBox->currentText().toStdString();

            string price = ui->AddText->text().toStdString();

            int pr;
            std::stringstream(price) >> pr;

            if(MicrobusVisibility){
                graph->updateEdgeCost(from,to,vehicle,pr);
            }
            else{
                graph->addEdge(from,to,vehicle,pr);
            }
            MicrobusVisibility = true;


        }
        else if (ui->AddcomboBox->currentText() == "Metro") {
            ui->MetroWidget->show();

            ui->MetroText->setText(ui->AddText->text());
            string to = ui->FromcomboBox->currentText().toStdString();

            string from = ui->TocomboBox->currentText().toStdString();

            string vehicle = ui->AddcomboBox->currentText().toStdString();

            string price = ui->AddText->text().toStdString();

            int pr;
            std::stringstream(price) >> pr;

            if(MetroVisibility){
                graph->updateEdgeCost(from,to,vehicle,pr);

            }
            else{
                graph->addEdge(from,to,vehicle,pr);
            }
            MetroVisibility = true;


        }
        else {
            ui->UberWidget->show();

            ui->UberText->setText(ui->AddText->text());

            string to = ui->FromcomboBox->currentText().toStdString();

            string from = ui->TocomboBox->currentText().toStdString();

            string vehicle = ui->AddcomboBox->currentText().toStdString();

            string price = ui->AddText->text().toStdString();

            int pr;
            std::stringstream(price) >> pr;

            if(UberVisibility){
                graph->updateEdgeCost(from,to,vehicle,pr);
            }
            else{
                graph->addEdge(from,to,vehicle,pr);
            }
            UberVisibility = true;


        }
        Added=false;
    }
    else if(!(ui->newNodeText->text().isEmpty())){
        graph->adj[ui->newNodeText->text().toStdString()];
        ui->FromcomboBox->clear();
         QStringList listCountries;
        listCountries.clear();
        for(auto node: graph->adj){
            listCountries.append(QString::fromStdString(node.first));
        }
          ui->FromcomboBox->addItems(listCountries);
        ui->TocomboBox->clear();

          listCountriesTo.clear();
          for(auto node: graph->adj){
              listCountriesTo.append(QString::fromStdString(node.first));
          }
        listCountriesTo.removeOne(ui->FromcomboBox->currentText());
        ui->TocomboBox->addItems(listCountriesTo);
        ui->newNodeText->clear();
    }


}

void Edit_Edge::on_connect()
{
    connect(ui->FromcomboBox, SIGNAL(activated(int)), this, SLOT(on_comboBox_currentIndexChanged()));
    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(on_add()));
    connect(ui->TrainX, SIGNAL(clicked()), this, SLOT(on_click1()));
    connect(ui->BusX, SIGNAL(clicked()), this, SLOT(on_click2()));
    connect(ui->MicrobusX, SIGNAL(clicked()), this, SLOT(on_click3()));
    connect(ui->MetroX, SIGNAL(clicked()), this, SLOT(on_click4()));
    connect(ui->UberX, SIGNAL(clicked()), this, SLOT(on_click5()));
    connect(ui->UpdateButton, SIGNAL(clicked()), this, SLOT(on_update()));

}

void Edit_Edge::on_start()
{
    ui->AddWidget->hide();
    ui->TrainWidget->hide();
    ui->BusWidget->hide();
    ui->MicrobusWidget->hide();
    ui->MetroWidget->hide();
    ui->UberWidget->hide();
    ui->toolButton->setIcon(QIcon(":/back-button.png"));
    QSize iconSize(25, 25); // Adjust the size as needed
    ui->toolButton->setIconSize(iconSize);
    on_load();
}

void Edit_Edge::on_combobox()
{
    QStringList listCountries;
    QStringList listTransportaion;
    listCountries.clear();
    for(auto node: graph->adj){
        listCountries.append(QString::fromStdString(node.first));
    }
    listTransportaion << "Train" << "Bus" << "Microbus" << "Metro" << "Uber";
    ui->FromcomboBox->addItems(listCountries);
    ui->AddcomboBox->addItems(listTransportaion);
    on_ToCombobox();

}
void Edit_Edge::on_ToCombobox()
{
    listCountriesTo.clear();
    for(auto node: graph->adj){
        listCountriesTo.append(QString::fromStdString(node.first));
    }
    listCountriesTo.removeOne(ui->FromcomboBox->currentText());
    ui->TocomboBox->clear();
    ui->TocomboBox->addItems(listCountriesTo);
}

void Edit_Edge::on_load()
{

}

void Edit_Edge::on_next()
{
}

void Edit_Edge::on_toolButton_clicked()
{
    Edit_Edge::hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}


void Edit_Edge::on_TocomboBox_currentIndexChanged(int index)
{
    string from = ui->FromcomboBox->currentText().toStdString();
    string to = ui->TocomboBox->currentText().toStdString();
    on_start();
    ui->TrainText->clear();
    ui->BusText->clear();
    ui->MicrobusText->clear();
    ui->MetroText->clear();
    ui->UberText->clear();
    for(auto e: graph->adj[from]){
        if(e.endNode==to){
            if (e.vehicle == "Train") {
                ui->TrainWidget->show();
                TrainVisibility = true;
                ui->TrainText->setText(QString::number(e.cost));
            }
            else if (e.vehicle == "Bus") {
                ui->BusWidget->show();
                BusVisibility = true;
                ui->BusText->setText(QString::number(e.cost));
            }
            else if (e.vehicle == "Microbus") {
                ui->MicrobusWidget->show();
                MicrobusVisibility = true;
                ui->MicrobusText->setText(QString::number(e.cost));

            }
            else if (e.vehicle == "Metro") {
                ui->MetroWidget->show();
                MetroVisibility = true;
                ui->MetroText->setText(QString::number(e.cost));
            }
            else {
                ui->UberWidget->show();
                UberVisibility = true;
                ui->UberText->setText(QString::number(e.cost));
            }
        }
    }
}

Edit_Edge::~Edit_Edge()
{
    delete ui;
}
///////////////////////////////////////////////////
void Edit_Edge::on_FromcomboBox_activated(int index)
{

}


void Edit_Edge::on_AddButton_clicked()
{
    ui->AddWidget->show();
    Added = true;
}

