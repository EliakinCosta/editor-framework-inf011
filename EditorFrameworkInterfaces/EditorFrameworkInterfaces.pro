#-------------------------------------------------
#
# Project created by QtCreator 2016-07-21T00:59:13
#
#-------------------------------------------------

QT       -= gui

TARGET = EditorFrameworkInterfaces
TEMPLATE = lib

DEFINES += EDITORFRAMEWORKINTERFACES_LIBRARY

SOURCES += icore.cpp

HEADERS += icore.h\
        editorframeworkinterfaces_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
