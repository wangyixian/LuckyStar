#ifndef DIALOGAWARDMODE_H
#define DIALOGAWARDMODE_H

#include <QDialog>

namespace Ui {
class DialogAwardMode;
}

class DialogAwardMode : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAwardMode(QWidget *parent = 0);
    ~DialogAwardMode();

private:
    Ui::DialogAwardMode *ui;
};

#endif // DIALOGAWARDMODE_H
