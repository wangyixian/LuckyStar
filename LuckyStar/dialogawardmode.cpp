#include "dialogawardmode.h"
#include "ui_dialogawardmode.h"

DialogAwardMode::DialogAwardMode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAwardMode)
{
    ui->setupUi(this);
}

DialogAwardMode::~DialogAwardMode()
{
    delete ui;
}
