#ifndef DIALOGNAMELIST_H
#define DIALOGNAMELIST_H

#include <QDialog>

#include <dao/userdao.h>

namespace Ui {
class DialogNameList;
}

class DialogNameList : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNameList(QWidget *parent = 0, int projectID = 0);
    ~DialogNameList();

private:
    Ui::DialogNameList *ui;

    UserDao userDao;

    QList<UserDto> userDtos;

    int projectID;
};

#endif // DIALOGNAMELIST_H
