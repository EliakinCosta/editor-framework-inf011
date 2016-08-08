#-------------------------------------------------
#
# Project created by QtCreator 2016-07-25T11:49:56
#
#-------------------------------------------------
QT       -=  gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TextFactory
TEMPLATE = lib
CONFIG += plugin
DESTDIR = ../plugins
DEFINES += TEXTFACTORY_LIBRARY

SOURCES += textfactory.cpp \
    texteditor.cpp \
    textdocument.cpp

HEADERS += textfactory.h\
        textfactory_global.h \
    texteditor.h \
    textdocument.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

DISTFILES += TextFactory.json

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/release/ -lEditorFrameworkInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug/ -lEditorFrameworkInterfaces
else:unix: LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/ -lEditorFrameworkInterfaces

INCLUDEPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug
DEPENDPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug
