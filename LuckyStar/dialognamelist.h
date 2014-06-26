#ifndef DIALOGNAMELIST_H
#define DIALOGNAMELIST_H

#include <QDialog>

namespace Ui {
class DialogNameList;
}

class DialogNameList : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNameList(QWidget *parent = 0);
    ~DialogNameList();

private:
    Ui::DialogNameList *ui;
};

#endif // DIALOGNAMELIST_H
