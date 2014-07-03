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
    QString sql;

    //Create the table of Project
    query.exec("DROP TABLE Project");
    sql ="CREATE TABLE Project ("
            "[ProjectID] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY ON CONFLICT FAIL AUTOINCREMENT, "
            "[ProjectName] VARCHAR(64) NOT NULL, "
            "[MainTitle] VARCHAR(256) NOT NULL, "
            "[SubTitle] VARCHAR(256) NOT NULL, "
            "[RollTitle] VARCHAR(1024) NOT NULL,"
            "[BackgroundImage] BLOB NOT NULL);";
    if(!query.exec(sql))
    {
        return false;
    }

    //Create the table of User
    query.exec("DROP TABLE User");
    sql = "CREATE TABLE User ("
            "[UserID] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY ON CONFLICT FAIL AUTOINCREMENT,"
            "[ProjectID] INTEGER NOT NULL,"
            "[UserNo] VARCHAR(128) NOT NULL,"
            "[UserName] VARCHAR(256) NOT NULL,"
            "[UserDepart] VARCHAR(256) NOT NULL,"
            "[UserPhone] VARCHAR(128) NOT NULL,"
            "[UserPhoto] BLOB NOT NULL);";
    if(!query.exec(sql))
    {
        return false;
    }

    //Create the table of Award
    query.exec("DROP TABLE Award");
    sql="CREATE TABLE Award ("
            "[AwardID] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY ON CONFLICT FAIL AUTOINCREMENT,"
            "[ProjectID] INTEGER NOT NULL,"
            "[AwardItemName] VARCHAR(256) NOT NULL,"
            "[AwardProductName] VARCHAR(256) NOT NULL,"
            "[AwardSum] INTEGER NOT NULL,"
            "[AwardTimes] INTEGER NOT NULL,"
            "[AwardPriority] INTEGER NOT NULL,"
            "[AwardPhoto] BLOB NOT NULL);";
    if(!query.exec(sql))
    {
        return false;
    }

    //Create the table of Bingo
    query.exec("DROP TABLE Bingo");
    sql="CREATE TABLE Bingo ("
            "[BingoID] INTEGER NOT NULL ON CONFLICT FAIL PRIMARY KEY ON CONFLICT FAIL AUTOINCREMENT, "
            "[ProjectID] INTEGER NOT NULL, "
            "[UserID] INTEGER NOT NULL,"
            "[AwardID] INTEGER NOT NULL);";
    if(!query.exec(sql))
    {
        return false;
    }

    return true;
}
