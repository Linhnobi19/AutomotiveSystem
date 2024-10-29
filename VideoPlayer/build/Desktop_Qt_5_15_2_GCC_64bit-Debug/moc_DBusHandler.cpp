/****************************************************************************
** Meta object code from reading C++ file 'DBusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DBusHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBusHandler_t {
    QByteArrayData data[16];
    char stringdata0[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBusHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBusHandler_t qt_meta_stringdata_DBusHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DBusHandler"
QT_MOC_LITERAL(1, 12, 9), // "APP_VIDEO"
QT_MOC_LITERAL(2, 22, 24), // "com.FinalMock.Dbus.Video"
QT_MOC_LITERAL(3, 47, 12), // "notifySignal"
QT_MOC_LITERAL(4, 60, 0), // ""
QT_MOC_LITERAL(5, 61, 14), // "onDataReceived"
QT_MOC_LITERAL(6, 76, 3), // "msg"
QT_MOC_LITERAL(7, 80, 15), // "messageReceived"
QT_MOC_LITERAL(8, 96, 10), // "showingApp"
QT_MOC_LITERAL(9, 107, 4), // "temp"
QT_MOC_LITERAL(10, 112, 4), // "quit"
QT_MOC_LITERAL(11, 117, 14), // "requestToPause"
QT_MOC_LITERAL(12, 132, 8), // "sendData"
QT_MOC_LITERAL(13, 141, 13), // "reSetListener"
QT_MOC_LITERAL(14, 155, 9), // "hideVideo"
QT_MOC_LITERAL(15, 165, 16) // "convertVideoName"

    },
    "DBusHandler\0APP_VIDEO\0com.FinalMock.Dbus.Video\0"
    "notifySignal\0\0onDataReceived\0msg\0"
    "messageReceived\0showingApp\0temp\0quit\0"
    "requestToPause\0sendData\0reSetListener\0"
    "hideVideo\0convertVideoName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      10,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   66,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   67,    4, 0x0a /* Public */,
       7,    1,   70,    4, 0x0a /* Public */,
       8,    1,   73,    4, 0x0a /* Public */,
      10,    0,   76,    4, 0x0a /* Public */,
      11,    0,   77,    4, 0x0a /* Public */,
      12,    1,   78,    4, 0x0a /* Public */,
      13,    0,   81,    4, 0x0a /* Public */,
      14,    0,   82,    4, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      15,    1,   83,    4, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void DBusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notifySignal(); break;
        case 1: _t->onDataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->showingApp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->quit(); break;
        case 5: _t->requestToPause(); break;
        case 6: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->reSetListener(); break;
        case 8: _t->hideVideo(); break;
        case 9: _t->convertVideoName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DBusHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBusHandler::notifySignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBusHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
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
    if (!strcmp(_clname, "IFSettingAppListener"))
        return static_cast< IFSettingAppListener*>(this);
    if (!strcmp(_clname, "IFHomeInterfaces"))
        return static_cast< IFHomeInterfaces*>(this);
    if (!strcmp(_clname, "IFMediaInterface"))
        return static_cast< IFMediaInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int DBusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void DBusHandler::notifySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
