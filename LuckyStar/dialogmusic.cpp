#include "dialogmusic.h"
#include "ui_dialogmusic.h"

DialogMusic::DialogMusic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMusic)
{
    ui->setupUi(this);
}

DialogMusic::~DialogMusic()
{
    delete ui;
}
