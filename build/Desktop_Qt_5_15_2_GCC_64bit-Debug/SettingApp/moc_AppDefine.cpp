/****************************************************************************
** Meta object code from reading C++ file 'AppDefine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SettingApp/src/common/AppDefine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppDefine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppDefine_t {
    QByteArrayData data[7];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppDefine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppDefine_t qt_meta_stringdata_AppDefine = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AppDefine"
QT_MOC_LITERAL(1, 10, 9), // "SCREEN_ID"
QT_MOC_LITERAL(2, 20, 15), // "SCREEN_LANGUAGE"
QT_MOC_LITERAL(3, 36, 13), // "SCREEN_VOLUME"
QT_MOC_LITERAL(4, 50, 11), // "SCREEN_DATE"
QT_MOC_LITERAL(5, 62, 11), // "SCREEN_INFO"
QT_MOC_LITERAL(6, 74, 12) // "SCREEN_RESET"

    },
    "AppDefine\0SCREEN_ID\0SCREEN_LANGUAGE\0"
    "SCREEN_VOLUME\0SCREEN_DATE\0SCREEN_INFO\0"
    "SCREEN_RESET"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppDefine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, alias, flags, count, data
       1,    1, 0x0,    5,   19,

 // enum data: key, value
       2, uint(AppDefine::SCREEN_LANGUAGE),
       3, uint(AppDefine::SCREEN_VOLUME),
       4, uint(AppDefine::SCREEN_DATE),
       5, uint(AppDefine::SCREEN_INFO),
       6, uint(AppDefine::SCREEN_RESET),

       0        // eod
};

void AppDefine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject AppDefine::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_AppDefine.data,
    qt_meta_data_AppDefine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppDefine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppDefine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppDefine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppDefine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
