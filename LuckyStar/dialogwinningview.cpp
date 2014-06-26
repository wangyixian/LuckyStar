#include "dialogwinningview.h"
#include "ui_dialogwinningview.h"

DialogWinningView::DialogWinningView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogWinningView)
{
    ui->setupUi(this);
}

DialogWinningView::~DialogWinningView()
{
    delete ui;
}
