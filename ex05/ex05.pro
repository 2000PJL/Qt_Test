#-------------------------------------------------
#
# Project created by QtCreator 2022-04-21T15:01:11
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex05
TEMPLATE = app


SOURCES += main.cpp\
        ex05.cpp \
    keypushbutton.cpp \
    keyboardwidget.cpp

HEADERS  += ex05.h \
    keyboardwidget.h \
    keypushbutton.h

FORMS    += ex05.ui \
    keyboardwidget.ui
