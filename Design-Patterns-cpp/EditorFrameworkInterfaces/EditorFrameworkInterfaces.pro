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
    idocumentcontroller.cpp \
    ieditor.cpp \
    idocument.cpp \
    iabstractfactory.cpp \
<<<<<<< HEAD
    iprototype.cpp \
    icompressionalgorithm.cpp
=======
    iprototype.cpp
>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b

HEADERS += icore.h\
        editorframeworkinterfaces_global.h \
    iuicontroller.h \
    iplugincontroller.h \
    iplugin.h \
    idocumentcontroller.h \
    ieditor.h \
    idocument.h \
    iabstractfactory.h \
<<<<<<< HEAD
    iprototype.h \
    icompressionalgorithm.h
=======
    iprototype.h
>>>>>>> 6a42dc52edd8a45e028e1e0e99f251bd0576c65b

unix {
    target.path = /usr/lib
    INSTALLS += target
}
