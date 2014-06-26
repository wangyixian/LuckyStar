#ifndef DIALOGKEYBOARD_H
#define DIALOGKEYBOARD_H

#include <QDialog>

namespace Ui {
class DialogKeyboard;
}

class DialogKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit DialogKeyboard(QWidget *parent = 0);
    ~DialogKeyboard();

private:
    Ui::DialogKeyboard *ui;
};

#endif // DIALOGKEYBOARD_H
