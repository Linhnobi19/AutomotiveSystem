/****************************************************************************
** Meta object code from reading C++ file 'DateController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SettingApp/src/controller/DateController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DateController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateController_t {
    QByteArrayData data[33];
    char stringdata0[437];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateController_t qt_meta_stringdata_DateController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DateController"
QT_MOC_LITERAL(1, 15, 18), // "currentHourChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "currentMinuteChanged"
QT_MOC_LITERAL(4, 56, 20), // "currentSecondChanged"
QT_MOC_LITERAL(5, 77, 17), // "currentDayChanged"
QT_MOC_LITERAL(6, 95, 19), // "currentMonthChanged"
QT_MOC_LITERAL(7, 115, 4), // "year"
QT_MOC_LITERAL(8, 120, 5), // "month"
QT_MOC_LITERAL(9, 126, 18), // "currentYearChanged"
QT_MOC_LITERAL(10, 145, 11), // "isPMChanged"
QT_MOC_LITERAL(11, 157, 18), // "dateShowingChanged"
QT_MOC_LITERAL(12, 176, 10), // "dateChange"
QT_MOC_LITERAL(13, 187, 18), // "timeShowingChanged"
QT_MOC_LITERAL(14, 206, 10), // "timeChange"
QT_MOC_LITERAL(15, 217, 17), // "onIsFormatChanged"
QT_MOC_LITERAL(16, 235, 6), // "format"
QT_MOC_LITERAL(17, 242, 20), // "onIsCustomizeChanged"
QT_MOC_LITERAL(18, 263, 6), // "custom"
QT_MOC_LITERAL(19, 270, 9), // "getUpdate"
QT_MOC_LITERAL(20, 280, 17), // "storingCustomTime"
QT_MOC_LITERAL(21, 298, 15), // "getUpdateCustom"
QT_MOC_LITERAL(22, 314, 9), // "dateStore"
QT_MOC_LITERAL(23, 324, 7), // "curTime"
QT_MOC_LITERAL(24, 332, 11), // "currentHour"
QT_MOC_LITERAL(25, 344, 13), // "currentMinute"
QT_MOC_LITERAL(26, 358, 13), // "currentSecond"
QT_MOC_LITERAL(27, 372, 10), // "currentDay"
QT_MOC_LITERAL(28, 383, 12), // "currentMonth"
QT_MOC_LITERAL(29, 396, 11), // "currentYear"
QT_MOC_LITERAL(30, 408, 4), // "isPM"
QT_MOC_LITERAL(31, 413, 11), // "dateShowing"
QT_MOC_LITERAL(32, 425, 11) // "timeShowing"

    },
    "DateController\0currentHourChanged\0\0"
    "currentMinuteChanged\0currentSecondChanged\0"
    "currentDayChanged\0currentMonthChanged\0"
    "year\0month\0currentYearChanged\0isPMChanged\0"
    "dateShowingChanged\0dateChange\0"
    "timeShowingChanged\0timeChange\0"
    "onIsFormatChanged\0format\0onIsCustomizeChanged\0"
    "custom\0getUpdate\0storingCustomTime\0"
    "getUpdateCustom\0dateStore\0curTime\0"
    "currentHour\0currentMinute\0currentSecond\0"
    "currentDay\0currentMonth\0currentYear\0"
    "isPM\0dateShowing\0timeShowing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       9,  118, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    2,   88,    2, 0x06 /* Public */,
       9,    2,   93,    2, 0x06 /* Public */,
      10,    0,   98,    2, 0x06 /* Public */,
      11,    1,   99,    2, 0x06 /* Public */,
      13,    1,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  105,    2, 0x0a /* Public */,
      17,    1,  108,    2, 0x0a /* Public */,
      19,    0,  111,    2, 0x0a /* Public */,
      20,    0,  112,    2, 0x0a /* Public */,
      21,    2,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::QString,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   22,   23,

 // properties: name, type, flags
      24, QMetaType::Int, 0x00495903,
      25, QMetaType::Int, 0x00495903,
      26, QMetaType::Int, 0x00495903,
      27, QMetaType::Int, 0x00495903,
      28, QMetaType::Int, 0x00495903,
      29, QMetaType::Int, 0x00495903,
      30, QMetaType::Bool, 0x00495903,
      31, QMetaType::QString, 0x00495903,
      32, QMetaType::QString, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,

       0        // eod
};

void DateController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DateController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentHourChanged(); break;
        case 1: _t->currentMinuteChanged(); break;
        case 2: _t->currentSecondChanged(); break;
        case 3: _t->currentDayChanged(); break;
        case 4: _t->currentMonthChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->currentYearChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->isPMChanged(); break;
        case 7: _t->dateShowingChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->timeShowingChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->onIsFormatChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->onIsCustomizeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->getUpdate(); break;
        case 12: _t->storingCustomTime(); break;
        case 13: _t->getUpdateCustom((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DateController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentHourChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DateController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentMinuteChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DateController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentSecondChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DateController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentDayChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DateController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentMonthChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DateController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::currentYearChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DateController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::isPMChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DateController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::dateShowingChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (DateController::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateController::timeShowingChanged)) {
                *result = 8;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DateController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->currentHour(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->currentMinute(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->currentSecond(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->currentDay(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->currentMonth(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->currentYear(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isPM(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->dateShowing(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->timeShowing(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DateController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCurrentHour(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setCurrentMinute(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setCurrentSecond(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setCurrentDay(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setCurrentMonth(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setCurrentYear(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setIsPM(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setDateShowing(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setTimeShowing(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DateController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DateController.data,
    qt_meta_data_DateController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DateController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DateController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DateController::currentHourChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DateController::currentMinuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DateController::currentSecondChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DateController::currentDayChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DateController::currentMonthChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void DateController::currentYearChanged(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void DateController::isPMChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void DateController::dateShowingChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void DateController::timeShowingChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
