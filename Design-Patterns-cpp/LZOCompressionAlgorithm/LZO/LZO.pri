INCLUDEPATH += $${PWD}

HEADERS     += $${PWD}/qtlzo.h

SOURCES     += $${PWD}/qtlzo.cpp
SOURCES     += $${PWD}/ScriptableLzo.cpp

unix: LIBS += -L$$PWD/lib/ -llzo2

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
