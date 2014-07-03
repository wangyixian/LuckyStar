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
    while(query.next()){
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

int ProjectDao::insert(ProjectDto dto)
{
    int projectID = -1;

    DBUtil dbUtil;
    dbUtil.Connect();

    QSqlQuery query;
    query.prepare("insert into Project(ProjectName, MainTitle, SubTitle, RollTitle, BackgroundImage)"
                  "values(:ProjectName,:MainTitle,:SubTitle,:RollTitle,:BackgroundImage)");
    query.bindValue(":ProjectName", dto.getProjectName());
    query.bindValue(":MainTitle", dto.getMainTitle());
    query.bindValue(":SubTitle", dto.getSubTitle());
    query.bindValue(":RollTitle", dto.getRollTitle());
    query.bindValue(":BackgroundImage", dto.getBackgroundImage());
    if(query.exec()){
        projectID = query.lastInsertId().toInt();
    } else {
        QMessageBox::warning(0, "", query.lastError().text());
    }

    dbUtil.Close();

    return projectID;
}
