#ifndef SONG_H
#define SONG_H

#include <QObject>

class Song : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ getTitle WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString artist READ getArtist WRITE setArtist NOTIFY artistChanged)
    Q_PROPERTY(QString album READ getAlbum WRITE setAlbum NOTIFY albumChanged)
    Q_PROPERTY(QString imagePath READ getImagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(int index READ getIndex WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(QString path READ getPath WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(int duration READ getDuration WRITE setDuration NOTIFY durationChanged)
    Q_PROPERTY(QString fileName READ getFileName WRITE setFileName NOTIFY fileNameChanged)
public:
    explicit Song(QObject *parent = nullptr);

    QString getTitle() const;
    void setTitle(QString title);

    QString getArtist() const;
    void setArtist(QString artist);

    QString getAlbum() const;
    void setAlbum(QString album);

    QString getImagePath() const;
    void setImagePath(QString imagePath);

    int getIndex() const;
    void setIndex(int index);

    QString getPath() const;
    void setPath(QString path);

    int getDuration() const;
    void setDuration(int duration);

    QString getFileName() const;
    void setFileName(QString fileName);

signals:

    void titleChanged( );

    void artistChanged();

    void albumChanged();

    void imagePathChanged();

    void indexChanged();

    void pathChanged();

    void durationChanged( );

    void fileNameChanged( );

private:
    QString m_title;
    QString m_artist;
    QString m_album;
    QString m_imagePath;
    int m_index = 0;
    QString m_path;
    int m_duration = 0;
    QString m_fileName;
};

#endif // SONG_H
