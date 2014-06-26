#include "dialogkeyboard.h"
#include "ui_dialogkeyboard.h"

DialogKeyboard::DialogKeyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogKeyboard)
{
    ui->setupUi(this);
}

DialogKeyboard::~DialogKeyboard()
{
    delete ui;
}
