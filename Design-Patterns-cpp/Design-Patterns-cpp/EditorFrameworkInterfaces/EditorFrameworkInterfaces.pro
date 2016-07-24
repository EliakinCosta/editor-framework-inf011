#-------------------------------------------------
#
# Project created by QtCreator 2016-07-22T12:09:29
#
#-------------------------------------------------

QT       -= gui

TARGET = EditorFrameworkInterfaces
TEMPLATE = lib

DEFINES += EDITORFRAMEWORKINTERFACES_LIBRARY

SOURCES += icore.cpp \
    iuicontroller.cpp \
    iplugincontroller.cpp \
    iplugin.cpp \
    idocumentcontroller.cpp

HEADERS += icore.h\
        editorframeworkinterfaces_global.h \
    iuicontroller.h \
    iplugincontroller.h \
    iplugin.h \
    idocumentcontroller.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
