#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    ~MainWindow();

private slots:


    float on_priceEdit_copyAvailable(bool b);


    void on_pushButton_clicked();

  //  void on_StartCombo_currentTextChanged(const QString &arg1);


    void on_BfsRB_clicked();

    void on_DfsRB_clicked();

    void on_StartCombo_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
