#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<BaseDto> projects = projectDao.selectAll();

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(createNewProject()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Create the new project
void MainWindow::createNewProject()
{

    //this->ui->listViewProjects->setModel();
}
