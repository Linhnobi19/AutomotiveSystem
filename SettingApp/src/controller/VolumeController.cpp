#include "VolumeController.h"
#include "LogHelper.h"
#include "SettingController.h"

VolumeController::VolumeController(QObject *parent)
    : QObject{parent}
{
    LOG_INFO << " => start";
    connect(this, &VolumeController::currentVolumeChanged,
            this, &VolumeController::saveData);

    dbusHandler = DbusHandler::getInstance();
    connect(this, &VolumeController::currentVolumeChanged,
            dbusHandler, &DbusHandler::setVolume);

    LOG_INFO << " => end";
}

VolumeController *VolumeController::getInstance()
{
    static VolumeController* controller = new VolumeController();

    return controller;
}

int VolumeController::currentVolume() const
{
    return m_currentVolume;
}

void VolumeController::setCurrentVolume(int newCurrentVolume)
{
    if (m_currentVolume == newCurrentVolume)
        return;
    m_currentVolume = newCurrentVolume;
    emit currentVolumeChanged(m_currentVolume);
}

void VolumeController::initialize(QQmlContext *context)
{
    context->setContextProperty("VolumeController", this);
}

void VolumeController::saveData(int value)
{
    SettingController* sInstance = SettingController::getInstance();
    sInstance->saveData("Volume", value);
}
