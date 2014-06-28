#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QSpinBox>
#include <util/dbutil.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // View the QT support databases
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << drivers;

    //If the database of LuckStar did not exist,
    //create it.
    bool isExit = QFile::exists("data.dat");
    if(!isExit)
    {
        DBUtil dbUtil;
        if(!dbUtil.Connect())
        {
            return -1;
        }
        if(!dbUtil.CreateTables())
        {
            return -1;
        }
        dbUtil.Close();
    }

    MainWindow *w = new MainWindow();
    w->show();
//    //学习测试用代码
//    QLabel *label = new QLabel("<h2><i>Hello</i> <font color=red>QT!</font></h2>");
//    label->show();

//    //学习测试用代码
//    QPushButton *button = new QPushButton("Quit");
//    QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
//    button->show();

//    //学习测试用代码
//    QWidget *window = new QWidget();
//    window->setWindowTitle("Enter your age");

//    QSpinBox *spinBox = new QSpinBox();
//    QSlider *slider = new QSlider(Qt::Horizontal);
//    spinBox->setRange(0,130);
//    slider->setRange(0,130);

//    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
//    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
//    spinBox->setValue(35);

//    QHBoxLayout *layout = new QHBoxLayout();
//    layout->addWidget(spinBox);
//    layout->addWidget(slider);
//    window->setLayout(layout);
//    window->show();

    return a.exec();
}
