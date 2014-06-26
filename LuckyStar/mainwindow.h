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
    ProjectDao projectDao;

private slots:
    //名单设置按钮的单击信号槽
    //void btnNameListClicked(int projectID);

    //奖项设置按钮的单击信号槽
    //void btnAwardListClicked(int projectID);

    //中奖名单按钮的单击信号槽
    //void btnWinningListClicked(int projectID);

    //Create the new project
    void createNewProject();

//    //Select all projects
//    void selectAllProjects();

//    //Delete selected projects
//    void deleteProjects();
};

#endif // MAINWINDOW_H
