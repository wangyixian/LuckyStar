#include "dialogawardlist.h"
#include "ui_dialogawardlist.h"

DialogAwardList::DialogAwardList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAwardList)
{
    ui->setupUi(this);
}

DialogAwardList::~DialogAwardList()
{
    delete ui;
}
