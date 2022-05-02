#-------------------------------------------------
#
# Project created by QtCreator 2022-04-21T15:01:11
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex06
TEMPLATE = app


SOURCES += main.cpp\
        ex06.cpp \
    keypushbutton.cpp \
    keyboardwidget.cpp

HEADERS  += ex06.h \
    keyboardwidget.h \
    keypushbutton.h

FORMS    += ex06.ui \
    keyboardwidget.ui
