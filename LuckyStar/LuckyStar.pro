#-------------------------------------------------
#
# Project created by QtCreator 2014-06-05T22:53:55
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LuckyStar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialognamelist.cpp \
    dialogawardlist.cpp \
    dialogwinningview.cpp \
    dialoguilayout.cpp \
    dialogmusic.cpp \
    dialogkeyboard.cpp \
    dialogawardmode.cpp \
    dto/basedto.cpp \
    dao/basedao.cpp \
    dto/projectdto.cpp \
    dao/projectdao.cpp \
    util/dbutil.cpp \
    common/constants.cpp \
    dto/userdto.cpp \
    dao/userdao.cpp

HEADERS  += mainwindow.h \
    dialognamelist.h \
    dialogawardlist.h \
    dialogwinningview.h \
    dialoguilayout.h \
    dialogmusic.h \
    dialogkeyboard.h \
    dialogawardmode.h \
    dto/basedto.h \
    dao/basedao.h \
    dto/projectdto.h \
    dao/projectdao.h \
    util/dbutil.h \
    common/constants.h \
    dto/userdto.h \
    dao/userdao.h

FORMS    += mainwindow.ui \
    dialognamelist.ui \
    dialogawardlist.ui \
    dialogwinningview.ui \
    dialoguilayout.ui \
    dialogmusic.ui \
    dialogkeyboard.ui \
    dialogawardmode.ui

RESOURCES += \
    application.qrc

OTHER_FILES += \
    data/ddl.txt
