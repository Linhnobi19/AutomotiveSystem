/****************************************************************************
** Meta object code from reading C++ file 'DBusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MediaPlay/DBusHandler.h"
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
    QByteArrayData data[23];
    char stringdata0[243];
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
QT_MOC_LITERAL(3, 48, 7), // "quitApp"
QT_MOC_LITERAL(4, 56, 0), // ""
QT_MOC_LITERAL(5, 57, 15), // "messageReceived"
QT_MOC_LITERAL(6, 73, 3), // "msg"
QT_MOC_LITERAL(7, 77, 10), // "returnHome"
QT_MOC_LITERAL(8, 88, 10), // "showingApp"
QT_MOC_LITERAL(9, 99, 4), // "temp"
QT_MOC_LITERAL(10, 104, 4), // "quit"
QT_MOC_LITERAL(11, 109, 14), // "onDataReceived"
QT_MOC_LITERAL(12, 124, 9), // "hideMusic"
QT_MOC_LITERAL(13, 134, 11), // "homeCreated"
QT_MOC_LITERAL(14, 146, 14), // "settingCreated"
QT_MOC_LITERAL(15, 161, 12), // "videoCreated"
QT_MOC_LITERAL(16, 174, 8), // "pauseAll"
QT_MOC_LITERAL(17, 183, 14), // "requestToPause"
QT_MOC_LITERAL(18, 198, 8), // "sendData"
QT_MOC_LITERAL(19, 207, 12), // "convertMusic"
QT_MOC_LITERAL(20, 220, 5), // "title"
QT_MOC_LITERAL(21, 226, 6), // "artist"
QT_MOC_LITERAL(22, 233, 9) // "imagePath"

    },
    "DBusHandler\0APP_MUSIC\0com.fpt.MusicAppInterface\0"
    "quitApp\0\0messageReceived\0msg\0returnHome\0"
    "showingApp\0temp\0quit\0onDataReceived\0"
    "hideMusic\0homeCreated\0settingCreated\0"
    "videoCreated\0pauseAll\0requestToPause\0"
    "sendData\0convertMusic\0title\0artist\0"
    "imagePath"
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
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   86,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   87,    4, 0x0a /* Public */,
       7,    0,   90,    4, 0x0a /* Public */,
       8,    1,   91,    4, 0x0a /* Public */,
      10,    0,   94,    4, 0x0a /* Public */,
      11,    1,   95,    4, 0x0a /* Public */,
      12,    0,   98,    4, 0x0a /* Public */,
      13,    0,   99,    4, 0x0a /* Public */,
      14,    0,  100,    4, 0x0a /* Public */,
      15,    0,  101,    4, 0x0a /* Public */,
      16,    0,  102,    4, 0x0a /* Public */,
      17,    1,  103,    4, 0x0a /* Public */,
      18,    1,  106,    4, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      19,    3,  109,    4, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    6,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   20,   21,   22,

       0        // eod
};

void DBusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quitApp(); break;
        case 1: _t->messageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->returnHome(); break;
        case 3: _t->showingApp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->quit(); break;
        case 5: _t->onDataReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->hideMusic(); break;
        case 7: _t->homeCreated(); break;
        case 8: _t->settingCreated(); break;
        case 9: _t->videoCreated(); break;
        case 10: _t->pauseAll(); break;
        case 11: _t->requestToPause((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->convertMusic((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DBusHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBusHandler::quitApp)) {
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
    if (!strcmp(_clname, "IFHomeInterfaces"))
        return static_cast< IFHomeInterfaces*>(this);
    if (!strcmp(_clname, "IFSettingAppListener"))
        return static_cast< IFSettingAppListener*>(this);
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
void DBusHandler::quitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
