#include "basedao.h"

BaseDao::BaseDao()
{
}

QSqlDatabase BaseDao::connect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if(!db.open())
    {
        QString error = db.lastError().text();
    }
    return db;
}

QList<BaseDto> BaseDao::selectAll()
{
    QList<BaseDto> list;
    return list;
}
