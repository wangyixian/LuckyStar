#include "dbutil.h"

#include <QFile>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QTextStream>
#include <QtSql>

DBUtil::DBUtil()
{
}

const QString DBUtil::DB_NAME = "data.dat";

bool DBUtil::Connect()
{
    //Create the dirver of SQLITE
    this->db = QSqlDatabase::addDatabase ("QSQLITE");
    db.setDatabaseName (DBUtil::DB_NAME);
    if(!db.open ())
    {
        QMessageBox::warning (0, QObject::tr("Database error"), db.lastError().text());
        return false;
    }
    return true;
}

void DBUtil::Close()
{
    if(this->db.isOpen())
    {
        this->db.close();
    }
}

bool DBUtil::CreateTables()
{
    QSqlQuery query;
    query.exec("DROP TABLE Project");

    QString sql ="CREATE TABLE Project ("
            "[ProjectID] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY ON CONFLICT FAIL AUTOINCREMENT,"
            "[ProjectName] VARCHAR(64) NOT NULL,"
            "[MainTitle] VARCHAR(256) NOT NULL,"
            "[SubTitle] VARCHAR(256),"
            "[RollTitle] VARCHAR(1024),"
            "[BackgroundImage] BLOB);";
    if(!query.exec(sql))
    {
        return false;
    }
    return true;
}
