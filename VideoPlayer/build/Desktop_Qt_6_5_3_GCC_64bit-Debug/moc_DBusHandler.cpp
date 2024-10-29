/****************************************************************************
** Meta object code from reading C++ file 'DBusHandler.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DBusHandler.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DBusHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSDBusHandlerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSDBusHandlerENDCLASS = QtMocHelpers::stringData(
    "DBusHandler",
    "APP_HOME",
    "com.FinalMock.Dbus.Video",
    "testConnect",
    "",
    "msg",
    "showingApp",
    "convertVideoName",
    "temp"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSDBusHandlerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[9];
    char stringdata2[25];
    char stringdata3[12];
    char stringdata4[1];
    char stringdata5[4];
    char stringdata6[11];
    char stringdata7[17];
    char stringdata8[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSDBusHandlerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSDBusHandlerENDCLASS_t qt_meta_stringdata_CLASSDBusHandlerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "DBusHandler"
        QT_MOC_LITERAL(12, 8),  // "APP_HOME"
        QT_MOC_LITERAL(21, 24),  // "com.FinalMock.Dbus.Video"
        QT_MOC_LITERAL(46, 11),  // "testConnect"
        QT_MOC_LITERAL(58, 0),  // ""
        QT_MOC_LITERAL(59, 3),  // "msg"
        QT_MOC_LITERAL(63, 10),  // "showingApp"
        QT_MOC_LITERAL(74, 16),  // "convertVideoName"
        QT_MOC_LITERAL(91, 4)   // "temp"
    },
    "DBusHandler",
    "APP_HOME",
    "com.FinalMock.Dbus.Video",
    "testConnect",
    "",
    "msg",
    "showingApp",
    "convertVideoName",
    "temp"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDBusHandlerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       3,   16, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // classinfo: key, value
       1,    2,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   34,    4, 0x0a,    1 /* Public */,
       6,    0,   37,    4, 0x0a,    3 /* Public */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,   38,    4, 0x02,    4 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject DBusHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<IFHomeInterfaces::staticMetaObject>(),
    qt_meta_stringdata_CLASSDBusHandlerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDBusHandlerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDBusHandlerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<DBusHandler, std::true_type>,
        // method 'testConnect'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'showingApp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'convertVideoName'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void DBusHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DBusHandler *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->testConnect((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->showingApp(); break;
        case 2: _t->convertVideoName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *DBusHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBusHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDBusHandlerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return IFHomeInterfaces::qt_metacast(_clname);
}

int DBusHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IFHomeInterfaces::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
