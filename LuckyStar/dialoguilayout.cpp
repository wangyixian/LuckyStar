#include "dialoguilayout.h"
#include "ui_dialoguilayout.h"

DialogUILayout::DialogUILayout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUILayout)
{
    ui->setupUi(this);
}

DialogUILayout::~DialogUILayout()
{
    delete ui;
}
