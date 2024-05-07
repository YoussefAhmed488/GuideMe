#ifndef EDIT_EDGE_H
#define EDIT_EDGE_H

#include <QDialog>

namespace Ui {
class Edit_Edge;
}

class Edit_Edge : public QDialog
{
    Q_OBJECT

public:
    explicit Edit_Edge(QWidget *parent = nullptr);
    ~Edit_Edge();
    void on_connect();
    void on_start();
    void on_combobox();
    void on_load();
private slots:
    void on_comboBox_currentIndexChanged();
    void on_add();
    void on_click1();
    void on_click2();
    void on_click3();
    void on_click4();
    void on_click5();
    void on_submit();
    void on_update();
    void on_next();
    void on_toolButton_clicked();

private:
    Ui::Edit_Edge *ui;
    void on_ToCombobox();
    bool Added = false;
    bool TrainVisibility = false;
    bool BusVisibility = false;
    bool MicrobusVisibility = false;
    bool MetroVisibility = false;
    bool UberVisibility = false;
};

#endif // EDIT_EDGE_H
