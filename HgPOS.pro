#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T02:49:14
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HgPOS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    dialogstock.cpp

HEADERS  += mainwindow.h \
    database.h \
    produit.h \
    dialogstock.h

FORMS    += mainwindow.ui \
    dialogstock.ui

DISTFILES += \
    README.md

RESOURCES += \
    rsrc.qrc

RC_FILE = hg.rc
