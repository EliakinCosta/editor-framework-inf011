#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T18:20:27
#
#-------------------------------------------------

QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DeflateCompressionAlgorithm
TEMPLATE = lib

CONFIG += plugin
DESTDIR = ../plugins

DEFINES += LZOCOMPRESSIONALGORITHM_LIBRARY

SOURCES += lzocompressionalgorithm.cpp

HEADERS += lzocompressionalgorithm.h\
        lzocompressionalgorithm_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/release/ -lEditorFrameworkInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug/ -lEditorFrameworkInterfaces
else:unix: LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/ -lEditorFrameworkInterfaces

INCLUDEPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug
DEPENDPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug
