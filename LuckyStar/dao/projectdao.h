#include "basedao.h"

#include <dto/projectdto.h>

#ifndef PROJECTDAO_H
#define PROJECTDAO_H

class ProjectDao : public BaseDao
{
public:
    ProjectDao();

public:

    QList<ProjectDto> selectAll();

    //Insert the new project and return the inserted object's ID
    int insert(ProjectDto dto);
};

#endif // PROJECTDAO_H
