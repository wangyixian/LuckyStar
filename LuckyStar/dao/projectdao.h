#include "basedao.h"

#ifndef PROJECTDAO_H
#define PROJECTDAO_H

class ProjectDao : public BaseDao
{
public:
    ProjectDao();

public:
    virtual QList<BaseDto> selectAll();
};

#endif // PROJECTDAO_H
