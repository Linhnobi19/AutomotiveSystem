#ifndef VIDEOHANDLER_H
#define VIDEOHANDLER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAbstractVideoSurface>
#include <QAudioOutput>
#include <QDebug>
#include "VideoModel.h"
#include "DBusHandler.h"

class VideoHandler : public QObject
{
    Q_OBJECT
public:
    static VideoHandler *getInstance();
    Q_PROPERTY(QAbstractVideoSurface* videoSink READ videoSink WRITE setVideoSink NOTIFY videoSinkChanged FINAL)
    Q_PROPERTY(int videoIndex READ videoIndex WRITE setVideoIndex NOTIFY videoIndexChanged FINAL)
    Q_PROPERTY(int sizeList READ sizeList WRITE setSizeList NOTIFY sizeListChanged FINAL)
    Q_PROPERTY(bool checkPause READ checkPause WRITE setCheckPause NOTIFY checkPauseChanged FINAL)
    Q_PROPERTY(bool checkShowApp READ checkShowApp WRITE setCheckShowApp NOTIFY checkShowAppChanged FINAL)
    Q_PROPERTY(bool checkHaveVideoIsPlaying READ checkHaveVideoIsPlaying WRITE setCheckHaveVideoIsPlaying NOTIFY checkHaveVideoIsPlayingChanged FINAL)
    Q_PROPERTY(bool checkNextVideo READ checkNextVideo WRITE setCheckNextVideo NOTIFY checkNextVideoChanged FINAL)
    Q_PROPERTY(qint64 videoPos READ videoPos WRITE setVideoPos NOTIFY videoPosChanged FINAL)
    Q_PROPERTY(qint64 videoDuaration READ videoDuaration WRITE setVideoDuaration NOTIFY videoDuarationChanged FINAL)
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged FINAL)
    Q_INVOKABLE void requestPause();
    Q_INVOKABLE void setVideoSink(QAbstractVideoSurface *newVideoSink);
    Q_INVOKABLE void chooseVideo(int temp);
    Q_INVOKABLE void loadFolderPath(const QString &temp);
    QAbstractVideoSurface *videoSink() const;
    int videoIndex() const;
    void setVideoIndex(int newVideoIndex);
    int sizeList() const;
    void setSizeList(int newSizeList);
    bool checkPause() const;
    void setCheckPause(bool newCheckPause);
    bool checkHaveVideoIsPlaying() const;
    void setCheckHaveVideoIsPlaying(bool newCheckHaveVideoIsPlaying);
    qint64 videoPos() const;
    void setVideoPos(qint64 newVideoPos);
    qint64 videoDuaration() const;
    void setVideoDuaration(qint64 newVideoDuaration);
    int volume() const;
    void setVolume(int newVolume);
    bool checkShowApp() const;
    void setCheckShowApp(bool newCheckShowApp);
    bool checkNextVideo() const;
    void setCheckNextVideo(bool newCheckNextVideo);
signals:
    void videoSinkChanged();
    void videoPosChanged();
    void durationChanged();
    void videoIndexChanged();
    void sizeListChanged();
    void checkPauseChanged();
    void checkHaveVideoIsPlayingChanged();
    void volumeChanged();
    void videoDuarationChanged();
    void checkShowAppChanged();
    void checkNextVideoChanged();
public slots:
    void handlePlaybackStatusChanged(QMediaPlayer::State status);
    void pause();
    void myChangedPosition(int pos);

private:
    explicit VideoHandler(QObject *parent = nullptr);
    QAbstractVideoSurface *m_videoSink = nullptr;
    QMediaPlayer* m_mediaPlayer;
    QAudioOutput* m_audioOutput;
    QMediaPlayer::State m_state;
    int m_videoIndex;
    int m_sizeList;
    bool m_checkPause;
    bool m_checkHaveVideoIsPlaying;
    qint64 m_videoPos;
    qint64 m_videoDuaration;
    int m_volume;
    bool m_checkShowApp;
    bool m_checkNextVideo;
    bool m_isSeeking;
};

#endif // VIDEOHANDLER_H
