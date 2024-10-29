#include "SettingController.h"
#include <QSettings>
#include <QThread>
SettingController::SettingController(QObject *parent) : QObject(parent)
{
    loadSettings();
    connect(Model::getInstance(), SIGNAL(listChanged()), this, SLOT(setCurrentSongFromSetting()));
    connect(Controller::getInstance(), SIGNAL(positionChanged()), this, SLOT(save()));
    connect(Model::getInstance(), SIGNAL(currentSongChanged()), this, SLOT(save()));
}
SettingController *SettingController::getInstance()
{
    static SettingController *instance = new SettingController();
    return instance;
}

void SettingController::save()
{
    QSettings settings("settings.ini", QSettings::IniFormat);
    settings.setValue("title", Model::getInstance()->getCurrentSong()->getTitle());
    settings.setValue("position", Controller::getInstance()->getPosition());
    if (settings.status() == QSettings::NoError) {
            qDebug() << "Settings saved successfully.";
        } else {
            qDebug() << "Error while saving settings.";
        }
}

void SettingController::loadSettings()
{
    QSettings settings("settings.ini", QSettings::IniFormat);

    title = settings.value("title").toString();
    position = settings.value("position").toInt();

}

void SettingController::setCurrentSongFromSetting()
{
    if(found) return;
    QList<QObject*> songList = Model::getInstance()->getSongList();
    if(title == "")
    {
        Model::getInstance()->setCurrentSong((Song*) songList.at(0));
        found = true;
    }
    else {
        Song* newSong = (Song*) songList.last();
        if(newSong->getTitle() == title)
        {
            Model::getInstance()->setCurrentSong(newSong);
            Controller::getInstance()->setPos(position);
            Controller::getInstance()->play();
            QThread::msleep(4000);
            found = true;
        }
    }
}



