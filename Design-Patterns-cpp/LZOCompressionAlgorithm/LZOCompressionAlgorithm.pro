#-------------------------------------------------
#
# Project created by QtCreator 2016-08-08T18:20:27
#
#-------------------------------------------------

QT       -= gui
QT += script
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LZOCompressionAlgorithm
TEMPLATE = lib

CONFIG += plugin
DESTDIR = ../plugins

DEFINES += LZOCOMPRESSIONALGORITHM_LIBRARY

SOURCES += lzocompressionalgorithm.cpp

HEADERS += lzocompressionalgorithm.h\
        lzocompressionalgorithm_global.h
DISTFILES += LZOCompressionAlgorithm.json
unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop_Qt_5_7_0_MinGW_32bit-Debug/release/ -lEditorFrameworkInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug/ -lEditorFrameworkInterfaces
else:unix: LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop_Qt_5_7_0_MinGW_32bit-Debug/ -lEditorFrameworkInterfaces

INCLUDEPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug
DEPENDPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop_Qt_5_7_0_MinGW_32bit-Debug/debug

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../plugins/ -lQt5Lzo
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../plugins/ -lQt5Lzod
else:unix: LIBS += -L$$PWD/../plugins/ -lQt5Lzo

INCLUDEPATH += $$PWD/../plugins
DEPENDPATH += $$PWD/../plugins
