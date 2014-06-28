#include "projectdao.h"

#include <dto/projectdto.h>

#include <QMessageBox>

#include <util/dbutil.h>

ProjectDao::ProjectDao()
{
}

QList<ProjectDto> ProjectDao::selectAll()
{
    QList<ProjectDto> projects;

    DBUtil dbUtil;
    dbUtil.Connect();

    QSqlQuery query;
    query.exec("select * from Project");
    while(query.next())
    {
        ProjectDto project;
        int projectID = query.value(0).toInt();
        QString projectName = query.value(1).toString();
        QString mainTitle = query.value(2).toString();
        QString subTitle = query.value(3).toString();
        QString rollTitle = query.value(4).toString();
        QByteArray backgroundImage = query.value(5).toByteArray();

        project.setProjectID(projectID);
        project.setProjectName(projectName);
        project.setMainTitle(mainTitle);
        project.setSubTitle(subTitle);
        project.setRollTitle(rollTitle);
        project.setBackgroundImage(backgroundImage);

        projects.append(project);
    }

    dbUtil.Close();

    return projects;
}
