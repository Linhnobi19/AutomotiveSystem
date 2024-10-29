/****************************************************************************
** Meta object code from reading C++ file 'Controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MediaPlay/Controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[28];
    char stringdata0[242];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 15), // "positionChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "isShowChanged"
QT_MOC_LITERAL(4, 42, 14), // "isPauseChanged"
QT_MOC_LITERAL(5, 57, 15), // "isRepeatChanged"
QT_MOC_LITERAL(6, 73, 16), // "isShuffleChanged"
QT_MOC_LITERAL(7, 90, 4), // "play"
QT_MOC_LITERAL(8, 95, 5), // "pause"
QT_MOC_LITERAL(9, 101, 4), // "next"
QT_MOC_LITERAL(10, 106, 4), // "prev"
QT_MOC_LITERAL(11, 111, 4), // "back"
QT_MOC_LITERAL(12, 116, 4), // "skip"
QT_MOC_LITERAL(13, 121, 6), // "repeat"
QT_MOC_LITERAL(14, 128, 7), // "shuffle"
QT_MOC_LITERAL(15, 136, 6), // "setPos"
QT_MOC_LITERAL(16, 143, 5), // "value"
QT_MOC_LITERAL(17, 149, 7), // "setSong"
QT_MOC_LITERAL(18, 157, 5), // "index"
QT_MOC_LITERAL(19, 163, 14), // "setVolumeMedia"
QT_MOC_LITERAL(20, 178, 3), // "val"
QT_MOC_LITERAL(21, 182, 9), // "setSearch"
QT_MOC_LITERAL(22, 192, 6), // "search"
QT_MOC_LITERAL(23, 199, 8), // "position"
QT_MOC_LITERAL(24, 208, 6), // "isShow"
QT_MOC_LITERAL(25, 215, 7), // "isPause"
QT_MOC_LITERAL(26, 223, 8), // "isRepeat"
QT_MOC_LITERAL(27, 232, 9) // "isShuffle"

    },
    "Controller\0positionChanged\0\0isShowChanged\0"
    "isPauseChanged\0isRepeatChanged\0"
    "isShuffleChanged\0play\0pause\0next\0prev\0"
    "back\0skip\0repeat\0shuffle\0setPos\0value\0"
    "setSong\0index\0setVolumeMedia\0val\0"
    "setSearch\0search\0position\0isShow\0"
    "isPause\0isRepeat\0isShuffle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       5,  124, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    1,  112,    2, 0x0a /* Public */,
      17,    1,  115,    2, 0x0a /* Public */,
      19,    1,  118,    2, 0x0a /* Public */,
      21,    1,  121,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString,   22,

 // properties: name, type, flags
      23, QMetaType::Int, 0x00495903,
      24, QMetaType::Bool, 0x00495103,
      25, QMetaType::Bool, 0x00495903,
      26, QMetaType::Bool, 0x00495103,
      27, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->positionChanged(); break;
        case 1: _t->isShowChanged(); break;
        case 2: _t->isPauseChanged(); break;
        case 3: _t->isRepeatChanged(); break;
        case 4: _t->isShuffleChanged(); break;
        case 5: _t->play(); break;
        case 6: _t->pause(); break;
        case 7: _t->next(); break;
        case 8: _t->prev(); break;
        case 9: _t->back(); break;
        case 10: _t->skip(); break;
        case 11: _t->repeat(); break;
        case 12: _t->shuffle(); break;
        case 13: _t->setPos((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setSong((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->setVolumeMedia((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::positionChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::isShowChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::isPauseChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::isRepeatChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::isShuffleChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getPosition(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getIsShow(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getIsPause(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->getIsRepeat(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getIsShuffle(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPosition(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setIsShow(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setIsPause(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setIsRepeat(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setIsShuffle(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Controller::positionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controller::isShowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controller::isPauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Controller::isRepeatChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Controller::isShuffleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
