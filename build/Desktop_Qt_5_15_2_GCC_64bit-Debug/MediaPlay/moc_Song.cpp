/****************************************************************************
** Meta object code from reading C++ file 'Song.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../MediaPlay/Song.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Song.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Song_t {
    QByteArrayData data[18];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Song_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Song_t qt_meta_stringdata_Song = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Song"
QT_MOC_LITERAL(1, 5, 12), // "titleChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 13), // "artistChanged"
QT_MOC_LITERAL(4, 33, 12), // "albumChanged"
QT_MOC_LITERAL(5, 46, 16), // "imagePathChanged"
QT_MOC_LITERAL(6, 63, 12), // "indexChanged"
QT_MOC_LITERAL(7, 76, 11), // "pathChanged"
QT_MOC_LITERAL(8, 88, 15), // "durationChanged"
QT_MOC_LITERAL(9, 104, 15), // "fileNameChanged"
QT_MOC_LITERAL(10, 120, 5), // "title"
QT_MOC_LITERAL(11, 126, 6), // "artist"
QT_MOC_LITERAL(12, 133, 5), // "album"
QT_MOC_LITERAL(13, 139, 9), // "imagePath"
QT_MOC_LITERAL(14, 149, 5), // "index"
QT_MOC_LITERAL(15, 155, 4), // "path"
QT_MOC_LITERAL(16, 160, 8), // "duration"
QT_MOC_LITERAL(17, 169, 8) // "fileName"

    },
    "Song\0titleChanged\0\0artistChanged\0"
    "albumChanged\0imagePathChanged\0"
    "indexChanged\0pathChanged\0durationChanged\0"
    "fileNameChanged\0title\0artist\0album\0"
    "imagePath\0index\0path\0duration\0fileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Song[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       8,   62, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    0,   55,    2, 0x06 /* Public */,
       4,    0,   56,    2, 0x06 /* Public */,
       5,    0,   57,    2, 0x06 /* Public */,
       6,    0,   58,    2, 0x06 /* Public */,
       7,    0,   59,    2, 0x06 /* Public */,
       8,    0,   60,    2, 0x06 /* Public */,
       9,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::QString, 0x00495103,
      13, QMetaType::QString, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::Int, 0x00495103,
      17, QMetaType::QString, 0x00495103,

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

void Song::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Song *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged(); break;
        case 1: _t->artistChanged(); break;
        case 2: _t->albumChanged(); break;
        case 3: _t->imagePathChanged(); break;
        case 4: _t->indexChanged(); break;
        case 5: _t->pathChanged(); break;
        case 6: _t->durationChanged(); break;
        case 7: _t->fileNameChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::artistChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::albumChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::imagePathChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::indexChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::pathChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::durationChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Song::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Song::fileNameChanged)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Song *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getTitle(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getArtist(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getAlbum(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getImagePath(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getIndex(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->getPath(); break;
        case 6: *reinterpret_cast< int*>(_v) = _t->getDuration(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->getFileName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Song *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setArtist(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setAlbum(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setImagePath(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setIndex(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->setPath(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setDuration(*reinterpret_cast< int*>(_v)); break;
        case 7: _t->setFileName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Song::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Song.data,
    qt_meta_data_Song,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Song::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Song::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Song.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Song::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
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
void Song::titleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Song::artistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Song::albumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Song::imagePathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Song::indexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Song::pathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Song::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Song::fileNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
