#ifndef RESULT_WINDOW_H
#define RESULT_WINDOW_H

#include <QDialog>
#include <QString>
#include<string>
#include"graph.h"

using namespace std;
namespace Ui {
class Result_Window;
}

class Result_Window : public QDialog
{
    Q_OBJECT

public:
    explicit Result_Window(QWidget *parent = nullptr);

    Graph* graph = Graph::getInstance();
    void setGraphState();
    void on_next(QString from,QString to,QString price);
    void dijkestra();
    void setting_result();

    ~Result_Window();
private slots:
    void on_toolButton_clicked();

    void on_backtoolButton_clicked();

private:
    Ui::Result_Window *ui;
};





#endif // RESULT_WINDOW_H
