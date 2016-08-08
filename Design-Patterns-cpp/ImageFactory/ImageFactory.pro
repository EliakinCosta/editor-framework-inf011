#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T13:25:54
#
#-------------------------------------------------

QT       -=  gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageFactory
TEMPLATE = lib
CONFIG += plugin
DEFINES += IMAGEFACTORY_LIBRARY
DESTDIR = ../plugins

SOURCES += imagefactory.cpp \
    imageeditor.cpp \
    imagedocument.cpp

HEADERS += imagefactory.h \
    imageeditor.h \
    imagedocument.h \
    imagefactory_global.h
DISTFILES += ImageFactory.json

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/release/ -lEditorFrameworkInterfaces
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug/ -lEditorFrameworkInterfaces
else:unix: LIBS += -L$$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/ -lEditorFrameworkInterfaces

INCLUDEPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug
DEPENDPATH += $$PWD/../build-EditorFrameworkInterfaces-Desktop-Debug/debug
