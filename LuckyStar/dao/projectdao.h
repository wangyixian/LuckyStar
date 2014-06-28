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
};

#endif // PROJECTDAO_H
