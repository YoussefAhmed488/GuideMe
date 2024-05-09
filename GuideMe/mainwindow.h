#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"graph.h"

#include <QMainWindow>

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

    Graph graph = Graph();

    ~MainWindow();

private slots:


    void on_pushButton_clicked();

  //  void on_StartCombo_currentTextChanged(const QString &arg1);


    void on_BfsRB_clicked();

    void on_DfsRB_clicked();

    void on_StartCombo_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
