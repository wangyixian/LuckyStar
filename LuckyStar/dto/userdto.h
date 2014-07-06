#include "basedto.h"
#include <QBitArray>
#ifndef USERDTO_H
#define USERDTO_H

class UserDto : public BaseDto
{
public:
    UserDto();

private:
    int userID;

    int projectID;

    QString userNo;

    QString userName;

    QString userDepart;

    QString userPhone;

    QByteArray userPhoto;

public:
    int getUserID();
    void setUserID(int value);

    int getProjectID();
    void setProjectID(int value);

    QString getUserNo();
    void setUserNo(QString value);

    QString getUserName();
    void setUserName(QString value);

    QString getUserDepart();
    void setUserDepart(QString value);

    QString getUserPhone();
    void setUserPhone(QString value);

    QByteArray getUserPhoto();
    void setUserPhoto(QByteArray value);
};

#endif // USERDTO_H
