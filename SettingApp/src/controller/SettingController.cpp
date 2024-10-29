#include "SettingController.h"
#include "LogHelper.h"


SettingController::SettingController(QObject *parent)
    : QObject{parent}
{
    // initialize model to load old setting
    LOG_INFO << " => start";
    instance = SettingsModel::getInstance();
    LOG_INFO << " => end";
}

SettingController *SettingController::getInstance()
{
    static SettingController* controller = new SettingController();

    return controller;
}

void SettingController::reset()
{
    LOG_INFO << " => start";
    instance->resetToDefault();
    LOG_INFO << " => end";
}

void SettingController::loadAllData()
{
    LOG_INFO << " => start";
    instance->loadAllData();
    // instance->resetToDefault();
    LOG_INFO << " => end";
}

bool SettingController::loadData(const QString &key)
{
    LOG_INFO << " => start";
    bool check = instance->loadData(key);
    LOG_INFO << " => end";
    return check;
}

void SettingController::saveData(const QString& key,
                                 const QVariant& data)
{
    LOG_INFO << " => start";
    instance->saveData(key, data);
    LOG_INFO << " => end";
}

void SettingController::initialize(QQmlContext* context)
{
    context->setContextProperty("SettingController", this);
}
