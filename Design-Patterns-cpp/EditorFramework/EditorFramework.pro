#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T12:41:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EditorFramework
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    documentcontroller.cpp \
    uicontroller.cpp \
    core.cpp \
    plugincontroller.cpp

HEADERS  += mainwindow.h \
    documentcontroller.h \
    uicontroller.h \
    core.h \
    plugincontroller.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/release/ -lEditorFrameworkInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug/ -lEditorFrameworkInterfaces
else:unix: LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/ -lEditorFrameworkInterfaces

INCLUDEPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug
DEPENDPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug
