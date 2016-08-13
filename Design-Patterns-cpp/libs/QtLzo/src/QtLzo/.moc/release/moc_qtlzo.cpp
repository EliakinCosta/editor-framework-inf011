/****************************************************************************
** Meta object code from reading C++ file 'qtlzo.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../include/QtLzo/qtlzo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtlzo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ScriptableLzo_t {
    QByteArrayData data[8];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScriptableLzo_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScriptableLzo_t qt_meta_stringdata_ScriptableLzo = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ScriptableLzo"
QT_MOC_LITERAL(1, 14, 5), // "ToLzo"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "file"
QT_MOC_LITERAL(4, 26, 3), // "lzo"
QT_MOC_LITERAL(5, 30, 5), // "level"
QT_MOC_LITERAL(6, 36, 6), // "method"
QT_MOC_LITERAL(7, 43, 6) // "ToFile"

    },
    "ScriptableLzo\0ToLzo\0\0file\0lzo\0level\0"
    "method\0ToFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScriptableLzo[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    4,   34,    2, 0x0a /* Public */,
       1,    3,   43,    2, 0x2a /* Public | MethodCloned */,
       1,    2,   50,    2, 0x2a /* Public | MethodCloned */,
       7,    2,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Bool, QMetaType::QString, QMetaType::QString,    4,    3,

       0        // eod
};

void ScriptableLzo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScriptableLzo *_t = static_cast<ScriptableLzo *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->ToLzo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->ToLzo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->ToLzo((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->ToFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject ScriptableLzo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ScriptableLzo.data,
      qt_meta_data_ScriptableLzo,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ScriptableLzo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScriptableLzo::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ScriptableLzo.stringdata0))
        return static_cast<void*>(const_cast< ScriptableLzo*>(this));
    if (!strcmp(_clname, "QScriptable"))
        return static_cast< QScriptable*>(const_cast< ScriptableLzo*>(this));
    if (!strcmp(_clname, "QtLzo"))
        return static_cast< QtLzo*>(const_cast< ScriptableLzo*>(this));
    return QObject::qt_metacast(_clname);
}

int ScriptableLzo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
