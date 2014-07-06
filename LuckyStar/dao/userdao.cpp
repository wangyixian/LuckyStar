#include "userdao.h"

#include <QMessageBox>
#include <QtSql>

#include <util/dbutil.h>

UserDao::UserDao()
{
}

QList<UserDto> UserDao::selectAll(int projectID)
{
    QList<UserDto> users;

    DBUtil dbUtil;
    dbUtil.Connect();

    QSqlQuery query;
    query.prepare("select * from User where ProjectID = :projectID");
    query.bindValue(":projectID", projectID);
    if(query.exec()){
        while(query.next()){
            UserDto user;
            int userID = query.value(0).toInt();
            int projectID = query.value(1).toInt();
            QString userNo = query.value(2).toString();
            QString userName = query.value(3).toString();
            QString userDepart = query.value(4).toString();
            QString userPhone = query.value(5).toString();
            QByteArray userPhoto = query.value(6).toByteArray();

            user.setUserID(userID);
            user.setProjectID(projectID);
            user.setUserNo(userNo);
            user.setUserName(userName);
            user.setUserDepart(userDepart);
            user.setUserPhone(userPhone);
            user.setUserPhoto(userPhoto);

            users.append(user);
        }
    } else {
        QMessageBox::warning(0, "", query.lastError().text());
    }

    dbUtil.Close();

    return users;
}

//Insert the new user and return the inserted object's ID
int UserDao::insert(UserDto dto)
{
    int userID = -1;

    DBUtil dbUtil;
    dbUtil.Connect();

    QSqlQuery query;
    query.prepare("insert into User(ProjectID, UserNo, UserName, UserDepart, UserPhone, UserPhoto)"
                  "values(:ProjectID,:UserNo,:UserName,:UserDepart,:UserPhone,:UserPhoto)");
    query.bindValue(":ProjectID", dto.getProjectID());
    query.bindValue(":UserNo", dto.getUserNo());
    query.bindValue(":UserName", dto.getUserName());
    query.bindValue(":UserDepart", dto.getUserDepart());
    query.bindValue(":UserPhone", dto.getUserPhone());
    query.bindValue(":UserPhoto", dto.getUserPhoto());
    if(query.exec()){
        userID = query.lastInsertId().toInt();
    } else {
        QMessageBox::warning(0, "", query.lastError().text());
    }

    dbUtil.Close();

    return userID;
}

//Update the new user and return the updated row count
bool UserDao::update(UserDto dto)
{
    bool result = false;

    DBUtil dbUtil;
    dbUtil.Connect();

    QSqlQuery query;
    query.prepare("update User set "
                  "UserNo = :UserNo, "
                  "UserName = :UserName, "
                  "UserDepart = :UserDepart, "
                  "UserPhone = :UserPhone, "
                  "UserPhoto = :UserPhoto, "
                  "where UserID = :UserID");
    query.bindValue(":UserNo", dto.getUserNo());
    query.bindValue(":UserName", dto.getUserName());
    query.bindValue(":UserDepart", dto.getUserDepart());
    query.bindValue(":UserPhone", dto.getUserPhone());
    query.bindValue(":UserPhoto", dto.getUserPhoto());
    query.bindValue(":UserID", dto.getUserID());
    if(query.exec()){
        result = true;
    } else {
        QMessageBox::warning(0, "", query.lastError().text());
    }

    dbUtil.Close();

    return result;
}
