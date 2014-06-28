#include <QSqlDatabase>
#include <QString>

#ifndef DBUTIL_H
#define DBUTIL_H

class DBUtil
{
public:
    DBUtil();

private:
    QSqlDatabase db;

public:
    //Create the connect of SQLITE
    bool Connect();

    //Close the connect
    void Close();

    //Create the database's tables
    bool CreateTables();

    //The database name
    static const QString DB_NAME;
};

#endif // DBUTIL_H
