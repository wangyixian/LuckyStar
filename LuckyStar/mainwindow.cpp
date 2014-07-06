#include "dialogawardlist.h"
#include "dialognamelist.h"
#include "dialogwinningview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include <common/constants.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->isDirty = false;

    //Get project table's all records
    this->projectDtos = this->projectDao.selectAll();

//    this->projectTable.setTable("Project");
//    this->projectTable.select();
//    this->ui->listViewProjects->setModel(this->projectTable);
//    this->ui->listViewProjects->show();

    foreach (ProjectDto projectDto, this->projectDtos) {
        this->ui->listProjects->addItem(projectDto.getProjectName());
    }

    //Set the event when item select change
    connect(this->ui->listProjects, SIGNAL(itemSelectionChanged()), this, SLOT(selectProjectItemChanged()));
    //Set the event when the name list open button clicked
    connect(this->ui->btnNameList, SIGNAL(clicked()), this, SLOT(openNameListDialog()));
    //Set the event when the image edit button clicked
    connect(this->ui->btnEditImage, SIGNAL(clicked()), this, SLOT(selectImage()));

    //Set the events when project info editing finished
    connect(this->ui->lineEditProjectName, SIGNAL(editingFinished()), this, SLOT(editProjectName()));
    connect(this->ui->lineEditProjectMainTitle, SIGNAL(editingFinished()), this, SLOT(editMainTitle()));
    connect(this->ui->lineEditProjectSubTitle, SIGNAL(editingFinished()), this, SLOT(editSubTitle()));
    connect(this->ui->lineEditProjectRollTitle, SIGNAL(editingFinished()), this, SLOT(editRollText()));

    //Set the defualt select item
    this->ui->listProjects->setCurrentRow(0);

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(createNewProject()));
}

MainWindow::~MainWindow()
{
    if(this->isDirty){
        QMessageBox box;
        box.setWindowTitle(Constants::MESSAGE_TITLE);
        box.setIcon(QMessageBox::Question);
        box.setText(QObject::tr("数据未保存，是否保存以后退出？"));
        box.setStandardButtons(QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel);
        switch (box.exec()) {
        case QMessageBox::Yes:
            this->saveProjects();
            break;
        case QMessageBox::Cancel:
            return;
            break;
        default:
            break;
        }
    }
    delete ui;
}

//Create the new project
void MainWindow::createNewProject()
{
    //Collect the prefix name projects
    QList<QString> projectNames;
    foreach(ProjectDto projectDto, this->projectDtos) {
        if(projectDto.getProjectName().startsWith(ProjectDto::DEFAULT_PREFIX_PROJECT_NAME)){
           projectNames.push_back(projectDto.getProjectName());
       }
    }

    //Get the new project name
    int i = 0;
    QString projectPrefixName = ProjectDto::DEFAULT_PREFIX_PROJECT_NAME;
    QString newProjectName;
    do{
        i++;
        newProjectName = projectPrefixName + QString::number(i);
    }
    while(projectNames.contains(newProjectName));

    //Create the new project
    ProjectDto newProject;
    newProject.setProjectName(newProjectName);
    newProject.setMainTitle(newProjectName + ProjectDto::DEFAULT_SUFFIX_MAIN_TITLE);
    newProject.setSubTitle(newProjectName + ProjectDto::DEFAULT_SUFFIX_SUB_TITLE);
    newProject.setRollTitle(newProjectName + ProjectDto::DEFAULT_SUFFIX_ROLL_TITLE);
    newProject.setBackgroundImage(this->readFile(tr(":/new/DefaultPhoto/images/ProjectBackground.jpg")));

    //Insert the new project into the database and the list wiget of projects
    //Then select it.
    int newProjectID = this->projectDao.insert(newProject);
    if(newProjectID > 0){
        newProject.setProjectID(newProjectID);
        this->projectDtos.push_back(newProject);
        this->ui->listProjects->addItem(newProject.getProjectName());
        this->ui->listProjects->setCurrentRow(this->ui->listProjects->count() - 1);
    }
}

void MainWindow::selectProjectItemChanged()
{
    //Get the project dto
    ProjectDto projectDto = this->getSelected();

    //Set project information into the line edit
    this->ui->lineEditProjectName->setText(projectDto.getProjectName());
    this->ui->lineEditProjectMainTitle->setText(projectDto.getMainTitle());
    this->ui->lineEditProjectSubTitle->setText(projectDto.getSubTitle());
    this->ui->lineEditProjectRollTitle->setText(projectDto.getRollTitle());

    //Get the background image
    this->drawImage(projectDto.getBackgroundImage());
}

//Open the name list dialog
void MainWindow::openNameListDialog()
{
    ProjectDto projectDto = this->getSelected();
    DialogNameList *dialog = new DialogNameList(this, projectDto.getProjectID());
    dialog->exec();
}

//Open the award list dialog
void MainWindow::openAwardListDialog()
{
    DialogAwardList *dialog = new DialogAwardList();
    dialog->exec();
}

//Open the win list dialog
void MainWindow::openWinListDialog()
{
    DialogWinningView *dialog = new DialogWinningView();
    dialog->exec();
}

//Save the project information
void MainWindow::saveProjects()
{
    this->isDirty = false;
}

//Select the image
void MainWindow::selectImage()
{
    QString fileName = QFileDialog::getOpenFileName(
                this, tr("open file"), QDir::currentPath(),"ImageFiles(*.jpg *.bmp *.png *.gif)");
    if(!fileName.isNull()){
        QByteArray fileData = this->readFile(fileName);
        if(fileData.length() <= 0){
            QMessageBox::warning(this, "", QObject::tr(""));
        }

        //Get the selected project row index
        int rowIndex = this->ui->listProjects->currentRow();
        //Get the project dto and update the list of projectDtos
        ProjectDto projectDto = this->projectDtos[rowIndex];

        projectDto.setBackgroundImage(fileData);
        this->projectDtos[rowIndex] = projectDto;

        this->drawImage(projectDto.getBackgroundImage());

        this->isDirty = true;
    }
}

void MainWindow::editProjectName()
{
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto and update the list of projectDtos
    ProjectDto projectDto = this->projectDtos[rowIndex];

    projectDto.setProjectName(this->ui->lineEditProjectName->text());
    this->projectDtos[rowIndex] = projectDto;

    this->isDirty = true;
}

void MainWindow::editMainTitle()
{
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto and update the list of projectDtos
    ProjectDto projectDto = this->projectDtos[rowIndex];

    projectDto.setMainTitle(this->ui->lineEditProjectMainTitle->text());
    this->projectDtos[rowIndex] = projectDto;

    this->isDirty = true;
}

void MainWindow::editSubTitle()
{
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto and update the list of projectDtos
    ProjectDto projectDto = this->projectDtos[rowIndex];

    projectDto.setSubTitle(this->ui->lineEditProjectSubTitle->text());
    this->projectDtos[rowIndex] = projectDto;

    this->isDirty = true;
}

void MainWindow::editRollText()
{
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto and update the list of projectDtos
    ProjectDto projectDto = this->projectDtos[rowIndex];

    projectDto.setRollTitle(this->ui->lineEditProjectRollTitle->text());
    this->projectDtos[rowIndex] = projectDto;

    this->isDirty = true;
}

//Start the bingo active
void MainWindow::startBingo()
{

}

void MainWindow::drawImage(QByteArray imageData)
{
    //Get the background image
    QPixmap image;
    image.loadFromData(imageData);
    //Resize the image as height of LabelImage
    image = image.scaledToHeight(55);
    //Show the image on the label image
    this->ui->labelImage->setPixmap(image);
}

QByteArray MainWindow::readFile(QString path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    return file.readAll();
}

ProjectDto MainWindow::getSelected()
{
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto and update the list of projectDtos
    ProjectDto projectDto = this->projectDtos[rowIndex];

    return projectDto;
}
