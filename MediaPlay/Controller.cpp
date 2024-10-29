#include "Controller.h"
#include <QDebug>
#include <QMediaMetaData>
#include <QAudio>
#include <QRandomGenerator>
#include "DBusHandler.h"

Controller::Controller(QObject *parent) : QObject(parent), m_isShow(false)
{
    connect(mediaPlayer, &QMediaPlayer::positionChanged, this, [=](qint64 pos) {
          setPosition(pos / 1000);
       });
    QObject::connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged,this, [=](int status){
        if(status == QMediaPlayer::EndOfMedia)
        {
            if(!m_isRepeat) next();
            play();

        }
    });
    mediaPlayer->setVolume(50);
}


Controller *Controller::getInstance()
{
    static Controller* instance = new Controller();
    return instance;
}

void Controller::setMediaSource(QString source)
{
    mediaPlayer->setMedia(QUrl::fromLocalFile(source));
}

int Controller::getPosition() const
{
    return m_position;
}

void Controller::setPosition(int position)
{
    if (m_position == position)
        return;

    m_position = position;
    emit positionChanged();
}

bool Controller::getIsShow() const
{
    return m_isShow;
}

void Controller::play()
{
    if(mediaPlayer->state() == QMediaPlayer::PlayingState)
    {
        setIsPause(false);
        mediaPlayer->pause();
    }
    else {
        DBusHandler::getInstance()->pauseAll();
        qDebug() << 1;
        mediaPlayer->play();
        qDebug() << 2;
        setIsPause(true);
    }
}

void Controller::pause()
{
    setIsPause(false);
    mediaPlayer->pause();
}

void Controller::next()
{
    Song* currentSong = Model::getInstance()->getCurrentSong();
    QList<QObject*> songList = Model::getInstance()->getSongList();
    int nextIndex = -1;
    if(m_isShuffle)
    {
        nextIndex =  QRandomGenerator::global()->bounded(0, songList.length());
    }
    else nextIndex = (currentSong->getIndex() + 1) % songList.size();
    Song* nextSong = (Song*) songList.at(nextIndex);
    Model::getInstance()->setCurrentSong(nextSong);
    // mediaPlayer->play();
}

void Controller::prev()
{
    Song* currentSong = Model::getInstance()->getCurrentSong();
    QList<QObject*> songList = Model::getInstance()->getSongList();
    int nextIndex = (currentSong->getIndex() - 1 + songList.size() ) % songList.size();
    Song* nextSong = (Song*) songList.at(nextIndex);
    Model::getInstance()->setCurrentSong(nextSong);
}

void Controller::back()
{
    if(m_position < 0) return;
    setPos(std::max((m_position - 10), 0));
}

void Controller::skip()
{
    setPos(std::min(m_position + 10, Model::getInstance()->getCurrentSong()->getDuration()));
}

void Controller::repeat()
{
    setIsRepeat(!m_isRepeat);
}

void Controller::shuffle()
{
    setIsShuffle(!m_isShuffle);
}

void Controller::setPos(int value)
{
    mediaPlayer->setPosition(value * 1000);
}

void Controller::setSong(int index)
{
    QList<QObject*> songList = Model::getInstance()->getSongList();
    Song* nextSong = (Song*) songList.at(index);
    Model::getInstance()->setCurrentSong(nextSong);
}

void Controller::setVolumeMedia(int val)
{
    int actualVolume = val * 100 / 12;
    qreal linearVolume = QAudio::convertVolume(actualVolume / qreal(100.0),
                                               QAudio::LogarithmicVolumeScale,
                                               QAudio::LinearVolumeScale);

    mediaPlayer->setVolume(qRound(linearVolume * 100));
}


void Controller::setSearch(QString search)
{
    Model* model = Model::getInstance();
    qDebug() <<2 << model->getCurrentSong()->getTitle();

    model->searchListClear();
    qDebug() <<1 << model->getCurrentSong()->getTitle();

    search = search.toLower();
    QList<QObject*> songList = model->getSongList();
    foreach (QObject* obj, songList) {
        Song* song = (Song*) obj;
        QStringList attributes = {
            song->getTitle().toLower(),
            song->getPath().toLower(),
            song->getArtist().toLower()
        };

        if (std::any_of(attributes.begin(), attributes.end(),
                        [&search](const QString& attribute) {
                        return attribute.contains(search);
    }))
        {
            model->searchListAdd(song);
        }
    }
//    emit model->searchListChanged();
}

void Controller::setIsShuffle(bool isShuffle)
{
    if (m_isShuffle == isShuffle)
        return;

    m_isShuffle = isShuffle;
    emit isShuffleChanged();
}

void Controller::loadSettings()
{

}

void Controller::setIsRepeat(bool isRepeat)
{
    if (m_isRepeat == isRepeat)
        return;

    m_isRepeat = isRepeat;
    emit isRepeatChanged();
}

bool Controller::getIsShuffle() const
{
    return m_isShuffle;
}

void Controller::setIsShow(bool isShow)
{
    if (m_isShow == isShow)
        return;

    m_isShow = isShow;
    emit isShowChanged();
}

bool Controller::getIsPause() const
{
    return m_isPause;
}

void Controller::setIsPause(bool newIsPause)
{
    if (m_isPause == newIsPause)
        return;
    m_isPause = newIsPause;
    emit isPauseChanged();
}

bool Controller::getIsRepeat() const
{
    return m_isRepeat;
}
