#include "Model.h"
#include "Controller.h"
#include "DBusHandler.h"
#include <QDebug>

Model::Model(QObject *parent) : QAbstractListModel(parent), m_currentSong(new Song())
{
    QDir dir = QDir::currentPath();
    dir.cd("../Resource/music");
    QStringList filters;
    filters << "*.mp3";
    QFileInfoList fileInfoList = dir.entryInfoList(filters, QDir::Files);

    for (const QFileInfo &fileInfo : fileInfoList) {
        QString filePath = fileInfo.absoluteFilePath();

        QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
        Song *song = new Song();

        QDir dir = QDir::currentPath();
        dir.cd("../Resource/imageMusic");

        QObject::connect(mediaPlayer, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
            qDebug() << status;
            if(mediaPlayer->isMetaDataAvailable())
            {
                QString title = mediaPlayer->metaData(QMediaMetaData::Title).toString();
                QString artist = mediaPlayer->metaData(QMediaMetaData::ContributingArtist).toString();
                QString album = mediaPlayer->metaData(QMediaMetaData::AlbumTitle).toString();
                QImage image = mediaPlayer->metaData(QMediaMetaData::CoverArtImage).value<QImage>();
                QString filename = fileInfo.fileName();

                if(!image.isNull()){
                    image.save(dir.absolutePath() + "/" + title + ".png");
                    song->setImagePath(dir.absolutePath() + "/" + title + ".png");
                }
                else {
                    qDebug() << "Hehe " << dir.absolutePath();
                    song->setImagePath(dir.absolutePath() + "/default.jpg");
                }

                if (title.isEmpty()) title = fileInfo.fileName();

                song->setTitle(title);
                song->setArtist(artist);
                song->setAlbum(album);
                song->setPath(fileInfo.absoluteFilePath());
                song->setFileName(filename);
                qDebug() << song->getTitle();
                qDebug() << song->getArtist();
                qDebug() << song->getAlbum();
                qDebug() << song->getPath();
                song->setIndex(m_songList.size());
                m_songList.append(song);
                searchListAdd(song);
                qDebug() << song->getIndex();

                emit listChanged();
                //setCurrentSong(qobject_cast<Song*>(m_songList.at(0)));
                Controller::getInstance()->pause();


            }
        });
        QObject::connect(mediaPlayer, &QMediaPlayer::durationChanged, this, [=](qint64 duration)
        {
            song->setDuration(duration / 1000);
        });

        mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
    }
}

Model *Model::getInstance()
{
    static Model* m_instance = new Model();
    return m_instance;
}

int Model::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_searchList.count();
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_searchList.count())
        return QVariant();

    Song* song = m_searchList.at(index.row());
    switch (role) {
    case TitleRole:
        return song->getTitle();
    case ArtistRole:
        return song->getArtist();
    case AlbumRole:
        return song->getAlbum();
    case DurationRole:
        return song->getDuration();
    case ImagePathRole:
        return song->getImagePath();
    case FileNameRole:
        return song->getFileName();
    case PathRole:
        return song->getPath();
    case IndexRole:
        return song->getIndex();
    default:
        return QVariant();
    }
}

QHash<int, QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[TitleRole] = "title";
    roles[ArtistRole] = "artist";
    roles[AlbumRole] = "album";
    roles[DurationRole] = "duration";
    roles[ImagePathRole] = "imagePath";
    roles[FileNameRole] = "fileName";
    roles[PathRole] = "path";
    roles[IndexRole] = "index";
    return roles;
}

Song* Model::getCurrentSong() const
{
    return m_currentSong;
}

void Model::setCurrentSong(Song *currentSong)
{
    if (m_currentSong == currentSong)
        return;

    m_currentSong = currentSong;
    emit currentSongChanged();

    Controller::getInstance()->setMediaSource(currentSong->getPath());
    Controller::getInstance()->play();
    DBusHandler::getInstance()->convertMusic(currentSong->getTitle(), currentSong->getArtist(), currentSong->getImagePath());
}


void Model::searchListClear()
{
    beginRemoveRows(QModelIndex(), 0, m_searchList.size()-1);
    m_searchList.clear();
    endRemoveRows();
}

void Model::searchListAdd(Song *song)
{
    beginInsertRows(QModelIndex(), m_searchList.size(), m_searchList.size());
    m_searchList.append(song);
    endInsertRows();
}



QList<QObject *> Model::getSongList() const
{
    return m_songList;
}

void Model::setSongList(QList<QObject *> songList)
{
    if (m_songList == songList)
        return;

    m_songList = songList;
}
