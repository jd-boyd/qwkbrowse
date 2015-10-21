#-------------------------------------------------
#
# Project created by QtCreator 2015-10-16T02:52:29
#
#-------------------------------------------------

QT       += core gui widgets webkitwidgets

TARGET = qwkbrowse
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++14

SOURCES += main.cpp\
        mainwindow.cpp \
    webpage.cpp

HEADERS  += mainwindow.h \
    webpage.h

FORMS    += mainwindow.ui
