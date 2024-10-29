/****************************************************************************
** Meta object code from reading C++ file 'DateModel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../SettingApp/src/model/DateModel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DateModel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DateModel_t {
    QByteArrayData data[24];
    char stringdata0[249];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DateModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DateModel_t qt_meta_stringdata_DateModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "DateModel"
QT_MOC_LITERAL(1, 10, 12), // "hoursChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "secondsChanged"
QT_MOC_LITERAL(4, 39, 14), // "minutesChanged"
QT_MOC_LITERAL(5, 54, 11), // "daysChanged"
QT_MOC_LITERAL(6, 66, 13), // "monthsChanged"
QT_MOC_LITERAL(7, 80, 12), // "yearsChanged"
QT_MOC_LITERAL(8, 93, 18), // "isFormat24hChanged"
QT_MOC_LITERAL(9, 112, 6), // "format"
QT_MOC_LITERAL(10, 119, 18), // "isCustomizeChanged"
QT_MOC_LITERAL(11, 138, 6), // "custom"
QT_MOC_LITERAL(12, 145, 10), // "updateDays"
QT_MOC_LITERAL(13, 156, 4), // "year"
QT_MOC_LITERAL(14, 161, 5), // "month"
QT_MOC_LITERAL(15, 167, 17), // "onIsFormatChanged"
QT_MOC_LITERAL(16, 185, 5), // "hours"
QT_MOC_LITERAL(17, 191, 7), // "seconds"
QT_MOC_LITERAL(18, 199, 7), // "minutes"
QT_MOC_LITERAL(19, 207, 4), // "days"
QT_MOC_LITERAL(20, 212, 6), // "months"
QT_MOC_LITERAL(21, 219, 5), // "years"
QT_MOC_LITERAL(22, 225, 11), // "isFormat24h"
QT_MOC_LITERAL(23, 237, 11) // "isCustomize"

    },
    "DateModel\0hoursChanged\0\0secondsChanged\0"
    "minutesChanged\0daysChanged\0monthsChanged\0"
    "yearsChanged\0isFormat24hChanged\0format\0"
    "isCustomizeChanged\0custom\0updateDays\0"
    "year\0month\0onIsFormatChanged\0hours\0"
    "seconds\0minutes\0days\0months\0years\0"
    "isFormat24h\0isCustomize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DateModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       8,   84, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,
       8,    1,   70,    2, 0x06 /* Public */,
      10,    1,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,   76,    2, 0x0a /* Public */,
      15,    1,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, QMetaType::Bool,    9,

 // properties: name, type, flags
      16, QMetaType::QStringList, 0x00495903,
      17, QMetaType::QStringList, 0x00495903,
      18, QMetaType::QStringList, 0x00495903,
      19, QMetaType::QStringList, 0x00495903,
      20, QMetaType::QStringList, 0x00495903,
      21, QMetaType::QStringList, 0x00495903,
      22, QMetaType::Bool, 0x00495903,
      23, QMetaType::Bool, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,

       0        // eod
};

void DateModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DateModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hoursChanged(); break;
        case 1: _t->secondsChanged(); break;
        case 2: _t->minutesChanged(); break;
        case 3: _t->daysChanged(); break;
        case 4: _t->monthsChanged(); break;
        case 5: _t->yearsChanged(); break;
        case 6: _t->isFormat24hChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->isCustomizeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->updateDays((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->onIsFormatChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::hoursChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::secondsChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::minutesChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::daysChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::monthsChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (DateModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::yearsChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (DateModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::isFormat24hChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (DateModel::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DateModel::isCustomizeChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<DateModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QStringList*>(_v) = _t->hours(); break;
        case 1: *reinterpret_cast< QStringList*>(_v) = _t->seconds(); break;
        case 2: *reinterpret_cast< QStringList*>(_v) = _t->minutes(); break;
        case 3: *reinterpret_cast< QStringList*>(_v) = _t->days(); break;
        case 4: *reinterpret_cast< QStringList*>(_v) = _t->months(); break;
        case 5: *reinterpret_cast< QStringList*>(_v) = _t->years(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->isFormat24h(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->isCustomize(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<DateModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHours(*reinterpret_cast< QStringList*>(_v)); break;
        case 1: _t->setSeconds(*reinterpret_cast< QStringList*>(_v)); break;
        case 2: _t->setMinutes(*reinterpret_cast< QStringList*>(_v)); break;
        case 3: _t->setDays(*reinterpret_cast< QStringList*>(_v)); break;
        case 4: _t->setMonths(*reinterpret_cast< QStringList*>(_v)); break;
        case 5: _t->setYears(*reinterpret_cast< QStringList*>(_v)); break;
        case 6: _t->setIsFormat24h(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setIsCustomize(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject DateModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_DateModel.data,
    qt_meta_data_DateModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DateModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DateModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DateModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DateModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 8;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 8;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void DateModel::hoursChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DateModel::secondsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void DateModel::minutesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DateModel::daysChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void DateModel::monthsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void DateModel::yearsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void DateModel::isFormat24hChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void DateModel::isCustomizeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
