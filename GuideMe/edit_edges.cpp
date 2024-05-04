#include "edit_edges.h"
#include "ui_edit_edges.h"

Edit_Edges::Edit_Edges(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Edit_Edges)
{
    ui->setupUi(this);
}

Edit_Edges::~Edit_Edges()
{
    delete ui;
}
