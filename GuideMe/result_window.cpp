#include "result_window.h"
#include "ui_result_window.h"
#include<QIcon>
#include"edit_edge.h"
#include "mainwindow.h"
#include<QString>
Result_Window::Result_Window(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Result_Window)
{
    ui->setupUi(this);
    ui->toolButton->setIcon(QIcon(":/edit_icon_2.png"));
    QSize iconSize(25, 25); // Adjust the size as needed
    ui->toolButton->setIconSize(iconSize);
    ui->backtoolButton->setIcon(QIcon(":/back-button.png"));
    ui->backtoolButton->setIconSize(iconSize);

}


Result_Window::~Result_Window()
{
    delete ui;
}

void Result_Window::on_toolButton_clicked()
{
    Result_Window::close();
    QIcon appIcon(":/edit_icon_2.png");
    Edit_Edge e;
    e.setWindowTitle("Update Edges");
    e.setWindowIcon(appIcon);
    e.setModal(true);
    e.exec();
}


void Result_Window::on_backtoolButton_clicked()
{
    Result_Window::close();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->setGeometry(600, 250, 0, 0);
    mainWindow->show();
}
void Result_Window::on_next(QString from,QString to,QString price){
    ui->FromResult->setText(from);
    ui->ToResult->setText(to);
    ui->PriceResult->setText(price);
}

