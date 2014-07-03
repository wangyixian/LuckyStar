#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    //Set the defualt select item
    this->ui->listProjects->setCurrentRow(0);

    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(createNewProject()));
}

MainWindow::~MainWindow()
{
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
    QFile file(QObject::tr(":/new/DefaultPhoto/images/ProjectBackground.jpg"));
    file.open(QIODevice::ReadOnly);
    newProject.setBackgroundImage(file.readAll());

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
    //Get the selected project row index
    int rowIndex = this->ui->listProjects->currentRow();

    //Get the project dto
    ProjectDto projectDto = this->projectDtos[rowIndex];

    //Set project information into the line edit
    this->ui->lineEditProjectName->setText(projectDto.getProjectName());
    this->ui->lineEditProjectMainTitle->setText(projectDto.getMainTitle());
    this->ui->lineEditProjectSubTitle->setText(projectDto.getSubTitle());
    this->ui->lineEditProjectRollTitle->setText(projectDto.getRollTitle());

    //Get the background image
    QPixmap image;
    image.loadFromData(projectDto.getBackgroundImage());
    //Resize the image as height of LabelImage
    image = image.scaledToHeight(55);
    //Show the image on the label image
    this->ui->labelImage->setPixmap(image);
}
