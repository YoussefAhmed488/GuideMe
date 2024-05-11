#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"graph.h"

#include <QMainWindow>
#include "filereader.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    Graph* graph = Graph::getInstance();

    FileReader filesave;

    map<int,vector<Edge>> road;

    ~MainWindow();

private slots:

    // Instance of the Graph class
    void on_pushButton_clicked();

    //  void on_StartCombo_currentTextChanged(const QString &arg1);




    void on_BfsRB_clicked();

    void on_DfsRB_clicked();

    void on_StartCombo_currentIndexChanged(int index);

    void on_editButton_clicked();
    void closeEvent(QCloseEvent *event) override {
        // Call your function here
        filesave.savefile();
        qDebug()<<"closed";
        QMainWindow::closeEvent(event);
    }
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
