#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T16:11:09
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioManageClient
TEMPLATE = app

INCLUDEPATH += /usr/local/include/CommonAPI-3.1 \
               /usr/local/include/audiomanager/Generic

SOURCES += main.cpp\
        mainwindow.cpp \
        CommandInterfaceProxy.cpp \
    CommandInterface.cpp

HEADERS  += mainwindow.h \
    CommandInterface.h \
    CommandInterfaceProxy.h

FORMS    += mainwindow.ui

LIBS    += -lCommonAPI

DISTFILES += \
    CommandInterface.xml
