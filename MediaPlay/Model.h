
#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QImage>
#include <QDir>
#include <QFileInfoList>
#include "Song.h"

class Model : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Song* currentSong READ getCurrentSong WRITE setCurrentSong NOTIFY currentSongChanged)
public:
    enum SongRoles {
        TitleRole = Qt::UserRole + 1,
        ArtistRole,
        AlbumRole,
        DurationRole,
        ImagePathRole,
        FileNameRole,
        PathRole,
        IndexRole
    };

    static Model* getInstance();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Song* getCurrentSong() const;
    void setCurrentSong(Song* currentSong);

    QList<QObject*> getSongList() const;
    void setSongList(QList<QObject*> songList);

    void searchListClear();
    void searchListAdd(Song *song);

signals:
    void currentSongChanged();
    void listChanged();

private:
    explicit Model(QObject *parent = nullptr);

    Song* m_currentSong;
    QList<QObject*> m_songList;
    QList<Song*> m_searchList;
};

#endif // MODEL_H
