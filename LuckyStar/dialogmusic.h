#ifndef DIALOGMUSIC_H
#define DIALOGMUSIC_H

#include <QDialog>

namespace Ui {
class DialogMusic;
}

class DialogMusic : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMusic(QWidget *parent = 0);
    ~DialogMusic();

private:
    Ui::DialogMusic *ui;
};

#endif // DIALOGMUSIC_H
