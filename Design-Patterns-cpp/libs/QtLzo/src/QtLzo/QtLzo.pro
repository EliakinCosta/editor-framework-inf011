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

win32 {

CONFIG(debug, debug|release) {
LIBS        += -llzo2d
} else {
LIBS        += -llzo2
}

}

macx {

CONFIG(debug, debug|release) {
LIBS        += -lliblzo2d
} else {
LIBS        += -lliblzo2
}

}

unix {

CONFIG(debug, debug|release) {
LIBS        += -lliblzo2d
} else {
LIBS        += -lliblzo2
}

}
