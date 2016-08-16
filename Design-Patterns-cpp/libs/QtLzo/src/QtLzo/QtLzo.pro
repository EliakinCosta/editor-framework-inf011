TARGET       = QtLzo
QT           = core
QT          += script

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/QtLzo

HEADERS     += $${PWD}/../../include/QtLzo/QtLzo
HEADERS     += $${PWD}/../../include/QtLzo/qtlzo.h

SOURCES     += $${PWD}/qtlzo.cpp
SOURCES     += $${PWD}/ScriptableLzo.cpp

include ($${PWD}/../../doc/Qt/Qt.pri)

unix {

CONFIG(debug, debug|release) {
    LIBS += -L"$$_PRO_FILE_PWD_/libs/" -lliblzo2
}

}
