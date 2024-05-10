#ifndef RESULT_WINDOW_H
#define RESULT_WINDOW_H

#include <QDialog>
#include <QString>
#include<string>
using namespace std;
namespace Ui {
class Result_Window;
}

class Result_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Window(QWidget *parent = nullptr);

    ~Result_Window();

    void on_next(QString from,QString to,QString price);

    void path_show(vector<pair<int,string>> p);

private slots:
    void on_toolButton_clicked();

    void on_backtoolButton_clicked();

private:
    Ui::Result_Window *ui;
};





#endif // RESULT_WINDOW_H
