#ifndef DIALOGWINNINGVIEW_H
#define DIALOGWINNINGVIEW_H

#include <QDialog>

namespace Ui {
class DialogWinningView;
}

class DialogWinningView : public QDialog
{
    Q_OBJECT

public:
    explicit DialogWinningView(QWidget *parent = 0);
    ~DialogWinningView();

private:
    Ui::DialogWinningView *ui;
};

#endif // DIALOGWINNINGVIEW_H
