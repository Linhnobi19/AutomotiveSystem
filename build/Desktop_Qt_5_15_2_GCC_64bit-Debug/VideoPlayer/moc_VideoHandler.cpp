/****************************************************************************
** Meta object code from reading C++ file 'VideoHandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../VideoPlayer/VideoHandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VideoHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_VideoHandler_t {
    QByteArrayData data[36];
    char stringdata0[525];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_VideoHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_VideoHandler_t qt_meta_stringdata_VideoHandler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "VideoHandler"
QT_MOC_LITERAL(1, 13, 16), // "videoSinkChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "videoPosChanged"
QT_MOC_LITERAL(4, 47, 15), // "durationChanged"
QT_MOC_LITERAL(5, 63, 17), // "videoIndexChanged"
QT_MOC_LITERAL(6, 81, 15), // "sizeListChanged"
QT_MOC_LITERAL(7, 97, 17), // "checkPauseChanged"
QT_MOC_LITERAL(8, 115, 30), // "checkHaveVideoIsPlayingChanged"
QT_MOC_LITERAL(9, 146, 13), // "volumeChanged"
QT_MOC_LITERAL(10, 160, 21), // "videoDuarationChanged"
QT_MOC_LITERAL(11, 182, 19), // "checkShowAppChanged"
QT_MOC_LITERAL(12, 202, 21), // "checkNextVideoChanged"
QT_MOC_LITERAL(13, 224, 27), // "handlePlaybackStatusChanged"
QT_MOC_LITERAL(14, 252, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(15, 272, 6), // "status"
QT_MOC_LITERAL(16, 279, 5), // "pause"
QT_MOC_LITERAL(17, 285, 17), // "myChangedPosition"
QT_MOC_LITERAL(18, 303, 3), // "pos"
QT_MOC_LITERAL(19, 307, 12), // "requestPause"
QT_MOC_LITERAL(20, 320, 12), // "setVideoSink"
QT_MOC_LITERAL(21, 333, 22), // "QAbstractVideoSurface*"
QT_MOC_LITERAL(22, 356, 12), // "newVideoSink"
QT_MOC_LITERAL(23, 369, 11), // "chooseVideo"
QT_MOC_LITERAL(24, 381, 4), // "temp"
QT_MOC_LITERAL(25, 386, 14), // "loadFolderPath"
QT_MOC_LITERAL(26, 401, 9), // "videoSink"
QT_MOC_LITERAL(27, 411, 10), // "videoIndex"
QT_MOC_LITERAL(28, 422, 8), // "sizeList"
QT_MOC_LITERAL(29, 431, 10), // "checkPause"
QT_MOC_LITERAL(30, 442, 12), // "checkShowApp"
QT_MOC_LITERAL(31, 455, 23), // "checkHaveVideoIsPlaying"
QT_MOC_LITERAL(32, 479, 14), // "checkNextVideo"
QT_MOC_LITERAL(33, 494, 8), // "videoPos"
QT_MOC_LITERAL(34, 503, 14), // "videoDuaration"
QT_MOC_LITERAL(35, 518, 6) // "volume"

    },
    "VideoHandler\0videoSinkChanged\0\0"
    "videoPosChanged\0durationChanged\0"
    "videoIndexChanged\0sizeListChanged\0"
    "checkPauseChanged\0checkHaveVideoIsPlayingChanged\0"
    "volumeChanged\0videoDuarationChanged\0"
    "checkShowAppChanged\0checkNextVideoChanged\0"
    "handlePlaybackStatusChanged\0"
    "QMediaPlayer::State\0status\0pause\0"
    "myChangedPosition\0pos\0requestPause\0"
    "setVideoSink\0QAbstractVideoSurface*\0"
    "newVideoSink\0chooseVideo\0temp\0"
    "loadFolderPath\0videoSink\0videoIndex\0"
    "sizeList\0checkPause\0checkShowApp\0"
    "checkHaveVideoIsPlaying\0checkNextVideo\0"
    "videoPos\0videoDuaration\0volume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VideoHandler[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
      10,  132, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,
       9,    0,  111,    2, 0x06 /* Public */,
      10,    0,  112,    2, 0x06 /* Public */,
      11,    0,  113,    2, 0x06 /* Public */,
      12,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    1,  115,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    1,  119,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      19,    0,  122,    2, 0x02 /* Public */,
      20,    1,  123,    2, 0x02 /* Public */,
      23,    1,  126,    2, 0x02 /* Public */,
      25,    1,  129,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void, QMetaType::QString,   24,

 // properties: name, type, flags
      26, 0x80000000 | 21, 0x0049590b,
      27, QMetaType::Int, 0x00495903,
      28, QMetaType::Int, 0x00495903,
      29, QMetaType::Bool, 0x00495903,
      30, QMetaType::Bool, 0x00495903,
      31, QMetaType::Bool, 0x00495903,
      32, QMetaType::Bool, 0x00495903,
      33, QMetaType::LongLong, 0x00495903,
      34, QMetaType::LongLong, 0x00495903,
      35, QMetaType::Int, 0x00495903,

 // properties: notify_signal_id
       0,
       3,
       4,
       5,
       9,
       6,
      10,
       1,
       8,
       7,

       0        // eod
};

void VideoHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VideoHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->videoSinkChanged(); break;
        case 1: _t->videoPosChanged(); break;
        case 2: _t->durationChanged(); break;
        case 3: _t->videoIndexChanged(); break;
        case 4: _t->sizeListChanged(); break;
        case 5: _t->checkPauseChanged(); break;
        case 6: _t->checkHaveVideoIsPlayingChanged(); break;
        case 7: _t->volumeChanged(); break;
        case 8: _t->videoDuarationChanged(); break;
        case 9: _t->checkShowAppChanged(); break;
        case 10: _t->checkNextVideoChanged(); break;
        case 11: _t->handlePlaybackStatusChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 12: _t->pause(); break;
        case 13: _t->myChangedPosition((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->requestPause(); break;
        case 15: _t->setVideoSink((*reinterpret_cast< QAbstractVideoSurface*(*)>(_a[1]))); break;
        case 16: _t->chooseVideo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->loadFolderPath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 15:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::videoSinkChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::videoPosChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::durationChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::videoIndexChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::sizeListChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::checkPauseChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::checkHaveVideoIsPlayingChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::volumeChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::videoDuarationChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::checkShowAppChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (VideoHandler::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&VideoHandler::checkNextVideoChanged)) {
                *result = 10;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractVideoSurface* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<VideoHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QAbstractVideoSurface**>(_v) = _t->videoSink(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->videoIndex(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->sizeList(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->checkPause(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->checkShowApp(); break;
        case 5: *reinterpret_cast< bool*>(_v) = _t->checkHaveVideoIsPlaying(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->checkNextVideo(); break;
        case 7: *reinterpret_cast< qint64*>(_v) = _t->videoPos(); break;
        case 8: *reinterpret_cast< qint64*>(_v) = _t->videoDuaration(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->volume(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<VideoHandler *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setVideoSink(*reinterpret_cast< QAbstractVideoSurface**>(_v)); break;
        case 1: _t->setVideoIndex(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setSizeList(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setCheckPause(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setCheckShowApp(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setCheckHaveVideoIsPlaying(*reinterpret_cast< bool*>(_v)); break;
        case 6: _t->setCheckNextVideo(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setVideoPos(*reinterpret_cast< qint64*>(_v)); break;
        case 8: _t->setVideoDuaration(*reinterpret_cast< qint64*>(_v)); break;
        case 9: _t->setVolume(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject VideoHandler::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_VideoHandler.data,
    qt_meta_data_VideoHandler,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *VideoHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VideoHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_VideoHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VideoHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void VideoHandler::videoSinkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void VideoHandler::videoPosChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void VideoHandler::durationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void VideoHandler::videoIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void VideoHandler::sizeListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void VideoHandler::checkPauseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void VideoHandler::checkHaveVideoIsPlayingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void VideoHandler::volumeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void VideoHandler::videoDuarationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void VideoHandler::checkShowAppChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void VideoHandler::checkNextVideoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
