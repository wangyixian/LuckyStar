#include "projectdao.h"

#include <dto/projectdto.h>

ProjectDao::ProjectDao()
{
}

QList<BaseDto> ProjectDao::selectAll()
{
    QList<BaseDto> projects;

    QSqlDatabase db = this->connect();

    QSqlQuery query("", db);
    query.exec("SELECT * FROM Project");
    while(query.next())
    {
        ProjectDto project;
        int projectID = query.value(0).toInt();
        QString projectName = query.value(1).toString();
        QString mainTitle = query.value(2).toString();
        QString subTitle = query.value(3).toString();
        QString rollTitle = query.value(4).toString();
        QBitArray backgroundImage = query.value(5).toBitArray();

        project.setProjectID(projectID);
        project.setProjectName(projectName);
        project.setMainTitle(mainTitle);
        project.setSubTitle(subTitle);
        project.setRollTitle(rollTitle);
        project.setBackgroundImage(backgroundImage);

        projects.append(project);
    }

    db.close();

    return projects;
}
