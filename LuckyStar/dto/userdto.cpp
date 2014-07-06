#include "userdto.h"

UserDto::UserDto()
{
}

int UserDto::getUserID()
{
    return this->userID;
}

void UserDto::setUserID(int value)
{
    this->userID = value;
}

int UserDto::getProjectID()
{
    return this->projectID;
}

void UserDto::setProjectID(int value)
{
    this->projectID = value;
}

QString UserDto::getUserNo()
{
    return this->userNo;
}

void UserDto::setUserNo(QString value)
{
    this->userNo = value;
}

QString UserDto::getUserName()
{
    return this->userName;
}

void UserDto::setUserName(QString value)
{
    this->userName = value;
}

QString UserDto::getUserDepart()
{
    return this->userDepart;
}

void UserDto::setUserDepart(QString value)
{
    this->userDepart = value;
}

QString UserDto::getUserPhone()
{
    return this->userPhone;
}

void UserDto::setUserPhone(QString value)
{
    this->userPhone = value;
}

QByteArray UserDto::getUserPhoto()
{
    return this->userPhoto;
}

void UserDto::setUserPhoto(QByteArray value)
{
    this->userPhoto = value;
}
