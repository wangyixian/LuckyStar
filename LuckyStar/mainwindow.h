#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <dao/projectdao.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    bool isDirty;

    //The DAO of project
    ProjectDao projectDao;

    //The list of project DTO
    QList<ProjectDto> projectDtos;

    //Draw the image on the image lable
    void drawImage(QByteArray imageData);

    //Reat the file and return the byte array
    QByteArray readFile(QString path);

    //Get the selected project
    ProjectDto getSelected();

private slots:
    //Create the new project
    void createNewProject();

    //Select project item changed
    void selectProjectItemChanged();

    //Open the name list dialog
    void openNameListDialog();

    //Open the award list dialog
    void openAwardListDialog();

    //Open the win list dialog
    void openWinListDialog();

    //Save the project information
    void saveProjects();

    //Select the image
    void selectImage();

    //Edit the project name
    void editProjectName();

    //Edit the main title
    void editMainTitle();

    //Edit the sub title
    void editSubTitle();

    //Edit the roll text
    void editRollText();

    //Start the bingo active
    void startBingo();

//    //Select all projects
//    void selectAllProjects();

//    //Delete selected projects
//    void deleteProjects();
};

#endif // MAINWINDOW_H
