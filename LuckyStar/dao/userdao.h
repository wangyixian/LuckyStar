#include "basedao.h"

#include <dto/userdto.h>

#ifndef USERDAO_H
#define USERDAO_H

class UserDao : public BaseDao
{
public:
    UserDao();

public:

    QList<UserDto> selectAll(int projectID);

    //Insert the new user and return the inserted object's ID
    int insert(UserDto dto);

    //Update the new user and return the updated row count
    bool update(UserDto dto);
};

#endif // USERDAO_H
