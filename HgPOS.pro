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
    dialogstock.cpp \
    dialogcaisse.cpp \
    dialoginscription.cpp \
    dialogreservation.cpp \
    hgexporter.cpp

HEADERS  += mainwindow.h \
    database.h \
    produit.h \
    dialogstock.h \
    struct.h \
    dialogcaisse.h \
    dialoginscription.h \
    dialogreservation.h \
    hgexporter.h

FORMS    += mainwindow.ui \
    dialogstock.ui \
    dialogcaisse.ui \
    dialoginscription.ui \
    dialogreservation.ui

DISTFILES += \
    README.md

RESOURCES += \
    rsrc.qrc

RC_FILE = hg.rc
