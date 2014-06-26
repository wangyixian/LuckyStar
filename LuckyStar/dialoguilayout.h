#ifndef DIALOGUILAYOUT_H
#define DIALOGUILAYOUT_H

#include <QDialog>

namespace Ui {
class DialogUILayout;
}

class DialogUILayout : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUILayout(QWidget *parent = 0);
    ~DialogUILayout();

private:
    Ui::DialogUILayout *ui;
};

#endif // DIALOGUILAYOUT_H
