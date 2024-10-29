/****************************************************************************
** Meta object code from reading C++ file 'DBusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../VideoPlayer/DBusHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
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
    QByteArrayData data[22];
    char stringdata0[237];
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
QT_MOC_LITERAL(5, 61, 7), // "quitApp"
QT_MOC_LITERAL(6, 69, 10), // "returnHome"
QT_MOC_LITERAL(7, 80, 10), // "callMethod"
QT_MOC_LITERAL(8, 91, 10), // "methodName"
QT_MOC_LITERAL(9, 102, 4), // "args"
QT_MOC_LITERAL(10, 107, 8), // "pauseAll"
QT_MOC_LITERAL(11, 116, 14), // "onDataReceived"
QT_MOC_LITERAL(12, 131, 3), // "msg"
QT_MOC_LITERAL(13, 135, 15), // "messageReceived"
QT_MOC_LITERAL(14, 151, 10), // "showingApp"
QT_MOC_LITERAL(15, 162, 4), // "temp"
QT_MOC_LITERAL(16, 167, 4), // "quit"
QT_MOC_LITERAL(17, 172, 14), // "requestToPause"
QT_MOC_LITERAL(18, 187, 8), // "sendData"
QT_MOC_LITERAL(19, 196, 13), // "reSetListener"
QT_MOC_LITERAL(20, 210, 9), // "hideVideo"
QT_MOC_LITERAL(21, 220, 16) // "convertVideoName"

    },
    "DBusHandler\0APP_VIDEO\0com.FinalMock.Dbus.Video\0"
    "notifySignal\0\0quitApp\0returnHome\0"
    "callMethod\0methodName\0args\0pauseAll\0"
    "onDataReceived\0msg\0messageReceived\0"
    "showingApp\0temp\0quit\0requestToPause\0"
    "sendData\0reSetListener\0hideVideo\0"
    "convertVideoName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBusHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      14,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   86,    4, 0x06 /* Public */,
       5,    0,   87,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   88,    4, 0x0a /* Public */,
       7,    2,   89,    4, 0x0a /* Public */,
      10,    0,   94,    4, 0x0a /* Public */,
      11,    1,   95,    4, 0x0a /* Public */,
      13,    1,   98,    4, 0x0a /* Public */,
      14,    1,  101,    4, 0x0a /* Public */,
      16,    0,  104,    4, 0x0a /* Public */,
      17,    1,  105,    4, 0x0a /* Public */,
      18,    1,  108,    4, 0x0a /* Public */,
      19,    0,  111,    4, 0x0a /* Public */,
      20,    0,  112,    4, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      21,    1,  113,    4, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantList,    8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void DBusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notifySignal(); break;
        case 1: _t->quitApp(); break;
        case 2: _t->returnHome(); break;
        case 3: _t->callMethod((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QList<QVariant>(*)>(_a[2]))); break;
        case 4: _t->pauseAll(); break;
        case 5: _t->onDataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->messageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->showingApp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->quit(); break;
        case 9: _t->requestToPause((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->reSetListener(); break;
        case 12: _t->hideVideo(); break;
        case 13: _t->convertVideoName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        {
            using _t = void (DBusHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBusHandler::quitApp)) {
                *result = 1;
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void DBusHandler::notifySignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DBusHandler::quitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
