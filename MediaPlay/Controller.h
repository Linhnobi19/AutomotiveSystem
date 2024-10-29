#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model.h"
#include <QObject>
#include <QMediaPlayer>


class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int position READ getPosition WRITE setPosition NOTIFY positionChanged FINAL)
    Q_PROPERTY(bool isShow READ getIsShow WRITE setIsShow NOTIFY isShowChanged)
    Q_PROPERTY(bool isPause READ getIsPause WRITE setIsPause NOTIFY isPauseChanged FINAL)
    Q_PROPERTY(bool isRepeat READ getIsRepeat WRITE setIsRepeat NOTIFY isRepeatChanged)
    Q_PROPERTY(bool isShuffle READ getIsShuffle WRITE setIsShuffle NOTIFY isShuffleChanged)
public:
    static Controller* getInstance();
    void setMediaSource(QString source);

    int getPosition() const;
    void setPosition(int position);

    bool getIsShow() const;
    void setIsShow(bool isShow);

    bool getIsPause() const;
    void setIsPause(bool newIsPause);

    bool getIsRepeat() const;
    void setIsRepeat(bool isRepeat);

    bool getIsShuffle() const;
    void setIsShuffle(bool isShuffle);

    void loadSettings();
    void saveSettings();

public slots:
    void play();
    void pause();
    void next();
    void prev();
    void back();
    void skip();
    void repeat();
    void shuffle();
    void setPos(int value);
    void setSong(int index);
    void setVolumeMedia(int val);
    void setSearch(QString search);




signals:
    void positionChanged( );
    void isShowChanged();
    void isPauseChanged();

    void isRepeatChanged();

    void isShuffleChanged( );

private:
    explicit Controller(QObject *parent = nullptr);
    QMediaPlayer* mediaPlayer = new QMediaPlayer(this);
    int m_position = 0;
    bool m_isShow;
    bool m_isPause;
    bool m_isRepeat = false;
    bool m_isShuffle = false;
};

#endif // CONTROLLER_H
