#ifndef VOLUMECONTROLLER_H
#define VOLUMECONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include "DbusHandler.h"

class VolumeController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentVolume READ currentVolume
                   WRITE setCurrentVolume NOTIFY currentVolumeChanged FINAL)
    explicit VolumeController(QObject *parent = nullptr);
public:
    static VolumeController* getInstance();

    int currentVolume() const;
    void setCurrentVolume(int newCurrentVolume);

    void initialize(QQmlContext* context);
public slots:
    void saveData(int value);
signals:
    void currentVolumeChanged(int value);
private:
    int m_currentVolume;
    DbusHandler* dbusHandler;
};

#endif // VOLUMECONTROLLER_H
