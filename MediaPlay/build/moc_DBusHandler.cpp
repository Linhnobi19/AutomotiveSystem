/****************************************************************************
** Meta object code from reading C++ file 'DBusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../DBusHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBusHandler_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBusHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBusHandler_t qt_meta_stringdata_DBusHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DBusHandler"
QT_MOC_LITERAL(1, 12, 9), // "APP_MUSIC"
QT_MOC_LITERAL(2, 22, 25), // "com.fpt.MusicAppInterface"
QT_MOC_LITERAL(3, 48, 15), // "messageReceived"
QT_MOC_LITERAL(4, 64, 0), // ""
QT_MOC_LITERAL(5, 65, 3), // "msg"
QT_MOC_LITERAL(6, 69, 10), // "showingApp"
QT_MOC_LITERAL(7, 80, 10), // "returnHome"
QT_MOC_LITERAL(8, 91, 12), // "convertMusic"
QT_MOC_LITERAL(9, 104, 5), // "title"
QT_MOC_LITERAL(10, 110, 6), // "artist"
QT_MOC_LITERAL(11, 117, 9) // "imagePath"

    },
    "DBusHandler\0APP_MUSIC\0com.fpt.MusicAppInterface\0"
    "messageReceived\0\0msg\0showingApp\0"
    "returnHome\0convertMusic\0title\0artist\0"
    "imagePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags
       3,    1,   36,    4, 0x0a /* Public */,
       6,    0,   39,    4, 0x0a /* Public */,
       7,    0,   40,    4, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
       8,    3,   41,    4, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,   11,

       0        // eod
};

void DBusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->messageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->showingApp(); break;
        case 2: _t->returnHome(); break;
        case 3: _t->convertMusic((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBusHandler::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_DBusHandler.data,
    qt_meta_data_DBusHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DBusHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBusHandler.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IFHomeInterfaces"))
        return static_cast< IFHomeInterfaces*>(this);
    return QObject::qt_metacast(_clname);
}

int DBusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
