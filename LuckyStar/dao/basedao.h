#include <QtSql>

#include <dto/basedto.h>

#ifndef BASEDAO_H
#define BASEDAO_H

class BaseDao
{
public:
    BaseDao();

protected:
    QSqlDatabase connect();

public:
    virtual QList<BaseDto> selectAll();
};

#endif // BASEDAO_H
