#include "edit_edge.h"
#include "ui_edit_edge.h"
#include "result_window.h"

//using namespace std;

Edit_Edge::Edit_Edge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit_Edge)
{
    ui->setupUi(this);
    on_combobox();
    on_start();
    on_connect();

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
}
void Edit_Edge::on_click2()
{
    ui->BusWidget->hide();
    BusVisibility = false;
}
void Edit_Edge::on_click3()
{
    ui->MicrobusWidget->hide();
    MicrobusVisibility = false;
}
void Edit_Edge::on_click4()
{
    ui->MetroWidget->hide();
    MetroVisibility = false;
}
void Edit_Edge::on_click5()
{
    ui->UberWidget->hide();
    UberVisibility = false;
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
            TrainVisibility = true;
            ui->TrainText->setText(ui->AddText->text());


            QString to = ui->FromcomboBox->currentText();
            std::string t = to.toStdString();
            QString from = ui->TocomboBox->currentText();
            std::string f= to.toStdString();
            QString vehicle = ui->AddcomboBox->currentText();
            std::string v= to.toStdString();
            QString price = ui->AddText->text();
            std::string p= to.toStdString();
            int pr;
            std::stringstream(p) >> pr;
            cout<<t<<"  "<<f<<endl<<v<<pr<<endl;
            cout<<graph->adj[f].size()<<endl;
            graph->addEdge(f,t,v,pr);
            cout<<graph->adj[f].size()<<endl;

        }
        else if (ui->AddcomboBox->currentText() == "Bus") {
            ui->BusWidget->show();
            BusVisibility = true;
            ui->BusText->setText(ui->AddText->text());


            QString to = ui->FromcomboBox->currentText();
            std::string t = to.toStdString();
            QString from = ui->TocomboBox->currentText();
            std::string f= to.toStdString();
            QString vehicle = ui->AddcomboBox->currentText();
            std::string v= to.toStdString();
            QString price = ui->AddText->text();
            std::string p= to.toStdString();
            int pr;
            std::stringstream(p) >> pr;
            graph->addEdge(f,t,v,pr);

        }
        else if (ui->AddcomboBox->currentText() == "Microbus") {
            ui->MicrobusWidget->show();
            MicrobusVisibility = true;
            ui->MicrobusText->setText(ui->AddText->text());
            QString to = ui->FromcomboBox->currentText();
            std::string t = to.toStdString();
            QString from = ui->TocomboBox->currentText();
            std::string f= to.toStdString();
            QString vehicle = ui->AddcomboBox->currentText();
            std::string v= to.toStdString();
            QString price = ui->AddText->text();
            std::string p= to.toStdString();
            int pr;
            std::stringstream(p) >> pr;
            graph->addEdge(f,t,v,pr);

        }
        else if (ui->AddcomboBox->currentText() == "Metro") {
            ui->MetroWidget->show();
            MetroVisibility = true;
            ui->MetroText->setText(ui->AddText->text());
            QString to = ui->FromcomboBox->currentText();
            std::string t = to.toStdString();
            QString from = ui->TocomboBox->currentText();
            std::string f= to.toStdString();
            QString vehicle = ui->AddcomboBox->currentText();
            std::string v= to.toStdString();
            QString price = ui->AddText->text();
            std::string p= to.toStdString();
            int pr;
            std::stringstream(p) >> pr;
            graph->addEdge(f,t,v,pr);

        }
        else {
            ui->UberWidget->show();
            UberVisibility = true;
            ui->UberText->setText(ui->AddText->text());

            QString to = ui->FromcomboBox->currentText();
            std::string t = to.toStdString();
            QString from = ui->TocomboBox->currentText();
            std::string f= to.toStdString();
            QString vehicle = ui->AddcomboBox->currentText();
            std::string v= to.toStdString();
            QString price = ui->AddText->text();
            std::string p= to.toStdString();
            int pr;
            std::stringstream(p) >> pr;
            graph->addEdge(f,t,v,pr);

        }
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
    connect(ui->SubmitButton, SIGNAL(clicked()), this, SLOT(on_submit()));
    connect(ui->NextButton, SIGNAL(clicked()), this, SLOT(on_next()));
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
    listCountries << "Cairo" << "Giza" << "Asyut" << "Dahab" << "BeniSuef";
    listTransportaion << "Train" << "Bus" << "Microbus" << "Metro" << "Uber";
    ui->FromcomboBox->addItems(listCountries);
    ui->AddcomboBox->addItems(listTransportaion);
    on_ToCombobox();
}
void Edit_Edge::on_ToCombobox()
{
    QStringList listCountriesTo;
    listCountriesTo << "Cairo" << "Giza" << "Asyut" << "Dahab" << "BeniSuef";
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
    Edit_Edge::close();
    Result_Window r;
    r.setWindowTitle("Result");
    r.setModal(true);
    r.exec();
}


void Edit_Edge::on_TocomboBox_currentIndexChanged(int index)
{

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

