#ifndef DIALOGAWARDLIST_H
#define DIALOGAWARDLIST_H

#include <QDialog>

namespace Ui {
class DialogAwardList;
}

class DialogAwardList : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAwardList(QWidget *parent = 0);
    ~DialogAwardList();

private:
    Ui::DialogAwardList *ui;
};

#endif // DIALOGAWARDLIST_H
