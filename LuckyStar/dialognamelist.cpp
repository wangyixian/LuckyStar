#include "dialognamelist.h"
#include "ui_dialognamelist.h"

DialogNameList::DialogNameList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNameList)
{
    ui->setupUi(this);
}

DialogNameList::~DialogNameList()
{
    delete ui;
}
