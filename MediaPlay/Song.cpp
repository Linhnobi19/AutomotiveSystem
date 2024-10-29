#include "Song.h"

Song::Song(QObject *parent) : QObject(parent)
{

}

QString Song::getTitle() const
{
    return m_title;
}

void Song::setTitle(QString title)
{
    if (m_title == title)
        return;

    m_title = title;
    emit titleChanged();
}

QString Song::getArtist() const
{
    return m_artist;
}

void Song::setArtist(QString artist)
{
    if (m_artist == artist)
        return;

    m_artist = artist;
    emit artistChanged();
}

QString Song::getAlbum() const
{
    return m_album;
}

void Song::setAlbum(QString album)
{
    if (m_album == album)
        return;

    m_album = album;
    emit albumChanged();
}

QString Song::getImagePath() const
{
    return m_imagePath;
}

void Song::setImagePath(QString imagePath)
{
    if (m_imagePath == imagePath)
        return;

    m_imagePath = imagePath;
    emit imagePathChanged();
}

int Song::getIndex() const
{
    return m_index;
}

void Song::setIndex(int index)
{
    if (m_index == index)
        return;

    m_index = index;
    emit indexChanged();
}

QString Song::getPath() const
{
    return m_path;
}

void Song::setPath(QString path)
{
    if (m_path == path)
        return;

    m_path = path;
    emit pathChanged();
}

int Song::getDuration() const
{
    return m_duration;
}

void Song::setDuration(int duration)
{
    if (m_duration == duration)
        return;

    m_duration = duration;
    emit durationChanged();
}

QString Song::getFileName() const
{
    return m_fileName;
}

void Song::setFileName(QString fileName)
{
    if (m_fileName == fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged();
}

