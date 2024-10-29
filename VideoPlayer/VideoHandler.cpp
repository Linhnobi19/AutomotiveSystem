#include "VideoHandler.h"
#include <QDebug>
#include <iostream>
#include <string>

VideoHandler::VideoHandler(QObject *parent)
    : QObject{parent}
{
    m_mediaPlayer = new QMediaPlayer();
    m_audioOutput = new QAudioOutput();
    m_state       = QMediaPlayer::StoppedState;
    QObject::connect(m_mediaPlayer, &QMediaPlayer::stateChanged, this, &VideoHandler::handlePlaybackStatusChanged);
    QObject::connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoHandler::setVideoPos);
    QObject::connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoHandler::setVideoDuaration);
    m_videoIndex    = 0;
    m_sizeList      = 0;
    m_checkPause    = false;
    m_checkShowApp            = false;
    m_videoIndex              = -1;
    m_checkHaveVideoIsPlaying = false;
    m_checkNextVideo          = false;
    m_isSeeking               = false;
    m_videoPos = 0;
    m_videoDuaration = 0;
    m_volume = 12;
}

VideoHandler *VideoHandler::getInstance()
{
    static VideoHandler* instance = new VideoHandler();
    return instance;
}

void VideoHandler::requestPause()
{
    setCheckPause(!m_checkPause);
    if (m_state == QMediaPlayer::PlayingState)
    {
        m_mediaPlayer->pause();
    }
    else if (m_state == QMediaPlayer::PausedState)
    {
        m_mediaPlayer->play();

    }
}

QAbstractVideoSurface *VideoHandler::videoSink() const
{
    return m_videoSink;
}

void VideoHandler::setVideoSink(QAbstractVideoSurface *newVideoSink)
{
    if (m_videoSink != newVideoSink)
    {
        m_videoSink = newVideoSink;
        m_mediaPlayer->setVideoOutput(m_videoSink);
        emit videoSinkChanged();
    }
}

void VideoHandler::chooseVideo(int temp)
{
    QString filePath = VideoModel::getInstance()->getVideoPath(temp);
    QString fileName = VideoModel::getInstance()->getVideoName(temp);
    qDebug() << "Errrrrr";
    DBusHandler::getInstance()->convertVideoName(fileName);
    m_mediaPlayer->setMedia(QUrl("file://" + filePath));
    m_mediaPlayer->play();
    qDebug() << "Current filePath is: "    << filePath;
    qDebug() << "Current Video Name is: "  << fileName;
    setCheckPause(true);
    setCheckHaveVideoIsPlaying(true);
}

void VideoHandler::loadFolderPath(const QString &temp)
{
    QString newPath = temp;
    VideoModel::getInstance()->loadVideoModel(newPath.remove("file://"));
    m_sizeList = VideoModel::getInstance()->sizeList();
}

void VideoHandler::handlePlaybackStatusChanged(QMediaPlayer::State status)
{
    qDebug() << "State: " << status;
    m_state = status;
    if (status == QMediaPlayer::StoppedState && !m_checkNextVideo)
    {
        int nextIndex = m_videoIndex;
        nextIndex++;
        if (nextIndex < m_sizeList)
        {
            chooseVideo(nextIndex);
            setVideoIndex(nextIndex);
        }
        else
        {
            chooseVideo(0);
            setVideoIndex(0);
        }
    }
}

void VideoHandler::pause()
{
    if (m_state == QMediaPlayer::PlayingState)
    {
        setCheckPause(!m_checkPause);
        m_mediaPlayer->pause();
    }
}

void VideoHandler::myChangedPosition(int pos)
{
    m_mediaPlayer->setPosition(pos*1000);
}

int VideoHandler::videoIndex() const
{
    return m_videoIndex;
}

void VideoHandler::setVideoIndex(int newVideoIndex)
{
    qDebug() << "Current video index: " << newVideoIndex;
    if (m_videoIndex == newVideoIndex)
        return;
    m_videoIndex = newVideoIndex;
    emit videoIndexChanged();
}

int VideoHandler::sizeList() const
{
    return m_sizeList;
}

void VideoHandler::setSizeList(int newSizeList)
{
}

bool VideoHandler::checkPause() const
{
    return m_checkPause;
}

void VideoHandler::setCheckPause(bool newCheckPause)
{
    if (m_checkPause == newCheckPause)
        return;
    m_checkPause = newCheckPause;
    emit checkPauseChanged();
}

bool VideoHandler::checkHaveVideoIsPlaying() const
{
    return m_checkHaveVideoIsPlaying;
}

void VideoHandler::setCheckHaveVideoIsPlaying(bool newCheckHaveVideoIsPlaying)
{
    if (m_checkHaveVideoIsPlaying == newCheckHaveVideoIsPlaying)
        return;
    m_checkHaveVideoIsPlaying = newCheckHaveVideoIsPlaying;
    emit checkHaveVideoIsPlayingChanged();
}

qint64 VideoHandler::videoPos() const
{
    return m_videoPos;
}

void VideoHandler::setVideoPos(qint64 newVideoPos)
{
    if(newVideoPos > 5000)
    {
        m_checkNextVideo = false;
    }
    if (m_videoPos == newVideoPos)
        return;
    m_videoPos = newVideoPos / 1000;
    emit videoPosChanged();
}

qint64 VideoHandler::videoDuaration() const
{
    return m_videoDuaration;
}

void VideoHandler::setVideoDuaration(qint64 newVideoDuaration)
{
    if (m_videoDuaration == newVideoDuaration)
        return;
    m_videoDuaration = newVideoDuaration / 1000;
    emit videoDuarationChanged();
}

int VideoHandler::volume() const
{
    return m_volume;
}

void VideoHandler::setVolume(int newVolume)
{

    if (m_volume == newVolume)
        return;
    m_volume = newVolume;
    qDebug() << "Volume: " << m_volume;
    int actualVolume = m_volume * 100 / 12;
    qreal linearVolume = QAudio::convertVolume(actualVolume / qreal(100.0),
                                               QAudio::LogarithmicVolumeScale,
                                               QAudio::LinearVolumeScale);
    m_mediaPlayer->setVolume(qRound(linearVolume * 100));
    emit volumeChanged();
}

bool VideoHandler::checkShowApp() const
{
    return m_checkShowApp;
}

void VideoHandler::setCheckShowApp(bool newCheckShowApp)
{
    if (m_checkShowApp == newCheckShowApp)
        return;
    m_checkShowApp = newCheckShowApp;
    emit checkShowAppChanged();
}

bool VideoHandler::checkNextVideo() const
{
    return m_checkNextVideo;
}

void VideoHandler::setCheckNextVideo(bool newCheckNextVideo)
{
    if (m_checkNextVideo == newCheckNextVideo)
        return;
    m_checkNextVideo = newCheckNextVideo;
    emit checkNextVideoChanged();
}

