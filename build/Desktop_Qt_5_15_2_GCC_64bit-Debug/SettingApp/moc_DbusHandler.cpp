/****************************************************************************
** Meta object code from reading C++ file 'DbusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SettingApp/src/controller/DbusHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DbusHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DbusHandler_t {
    QByteArrayData data[23];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DbusHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DbusHandler_t qt_meta_stringdata_DbusHandler = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DbusHandler"
QT_MOC_LITERAL(1, 12, 14), // "DBus Interface"
QT_MOC_LITERAL(2, 27, 27), // "com.fpt.SettingAppInterface"
QT_MOC_LITERAL(3, 55, 17), // "visibleWinChanged"
QT_MOC_LITERAL(4, 73, 0), // ""
QT_MOC_LITERAL(5, 74, 7), // "quitApp"
QT_MOC_LITERAL(6, 82, 10), // "returnHome"
QT_MOC_LITERAL(7, 93, 15), // "messageReceived"
QT_MOC_LITERAL(8, 109, 3), // "msg"
QT_MOC_LITERAL(9, 113, 9), // "setVolume"
QT_MOC_LITERAL(10, 123, 6), // "volume"
QT_MOC_LITERAL(11, 130, 11), // "setLanguage"
QT_MOC_LITERAL(12, 142, 4), // "code"
QT_MOC_LITERAL(13, 147, 7), // "setDate"
QT_MOC_LITERAL(14, 155, 4), // "date"
QT_MOC_LITERAL(15, 160, 7), // "setTime"
QT_MOC_LITERAL(16, 168, 4), // "time"
QT_MOC_LITERAL(17, 173, 11), // "hideSetting"
QT_MOC_LITERAL(18, 185, 11), // "homeCreated"
QT_MOC_LITERAL(19, 197, 10), // "showingApp"
QT_MOC_LITERAL(20, 208, 4), // "temp"
QT_MOC_LITERAL(21, 213, 4), // "quit"
QT_MOC_LITERAL(22, 218, 10) // "visibleWin"

    },
    "DbusHandler\0DBus Interface\0"
    "com.fpt.SettingAppInterface\0"
    "visibleWinChanged\0\0quitApp\0returnHome\0"
    "messageReceived\0msg\0setVolume\0volume\0"
    "setLanguage\0code\0setDate\0date\0setTime\0"
    "time\0hideSetting\0homeCreated\0showingApp\0"
    "temp\0quit\0visibleWin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DbusHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
      12,   16, // methods
       1,  100, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   76,    4, 0x06 /* Public */,
       5,    0,   77,    4, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   78,    4, 0x0a /* Public */,
       7,    1,   79,    4, 0x0a /* Public */,
       9,    1,   82,    4, 0x0a /* Public */,
      11,    1,   85,    4, 0x0a /* Public */,
      13,    1,   88,    4, 0x0a /* Public */,
      15,    1,   91,    4, 0x0a /* Public */,
      17,    0,   94,    4, 0x0a /* Public */,
      18,    0,   95,    4, 0x0a /* Public */,
      19,    1,   96,    4, 0x0a /* Public */,
      21,    0,   99,    4, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,

 // properties: name, type, flags
      22, QMetaType::Bool, 0x00495903,

 // properties: notify_signal_id
       0,

       0        // eod
};

void DbusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DbusHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->visibleWinChanged(); break;
        case 1: _t->quitApp(); break;
        case 2: _t->returnHome(); break;
        case 3: _t->messageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setLanguage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setDate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->hideSetting(); break;
        case 9: _t->homeCreated(); break;
        case 10: _t->showingApp((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DbusHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbusHandler::visibleWinChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DbusHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DbusHandler::quitApp)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DbusHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->visibleWin(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DbusHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVisibleWin(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DbusHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DbusHandler.data,
    qt_meta_data_DbusHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DbusHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DbusHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DbusHandler.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "IFHomeInterfaces"))
        return static_cast< IFHomeInterfaces*>(this);
    return QObject::qt_metacast(_clname);
}

int DbusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DbusHandler::visibleWinChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DbusHandler::quitApp()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
