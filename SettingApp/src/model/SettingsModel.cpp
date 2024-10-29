#include "SettingsModel.h"
#include <QDir>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include <QDateTime>
#include "LogHelper.h"
#include "DateController.h"
#include "VolumeController.h"
#include "Translator.h"

SettingsModel::SettingsModel(QObject *parent)
    : QObject{parent}, m_setting("MockProject", "SettingApp")
{
    LOG_INFO << " => start";
    LOG_INFO << " => end";
}

SettingsModel *SettingsModel::getInstance()
{
    static SettingsModel* setModel;
    if(setModel == nullptr){
        setModel = new SettingsModel();
    }
    return setModel;
}

void SettingsModel::loadAllData()
{
    if(!loadData("Language") || !loadData("Volume")
        || !loadData("Format24h") || !loadData("Customize")){
        resetToDefault();
    }
    else{
        qDebug() << "Clear all ";
        // m_setting.clear();
    }
}

void SettingsModel::resetToDefault()
{
    LOG_INFO << " => start";
    QDir dir(QDir::currentPath());
    qDebug() << dir;
    // for (int var = 0; var < 3; ++var) {
    //     dir.cdUp();
    // }
    dir.cdUp();
    QString path = dir.absolutePath() + "/Resource/setting.json";
    qDebug() << "File path is " << path;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        qDebug() << file.errorString();
        qDebug() << "Couldn't open the file or couldn't find any dir like this";
    }
    else{
        QJsonDocument doc(QJsonDocument::fromJson(file.readAll()));
        if(!doc.isObject()){
            qDebug() << "It's not a json object";
            return;
        }
        QJsonObject obj = doc.object();
        if(obj.value("ID") != "Setting Default App"){
            qDebug() << "It's not option for setting app";
            return;
        }
        QJsonObject objValue = obj.value("values").toObject();

        DateController * instance = DateController::getInstance();
        instance->setFormat(objValue.value("format24h").toBool());
        instance->setCustom(objValue.value(
                            "customizeDate").toBool());
        VolumeController* vInstance = VolumeController::getInstance();
        qDebug() << obj.value("volume").toInt();
        vInstance->setCurrentVolume(objValue.value("volume").toInt());

        Translator * tInstance = Translator::getInstance();
        tInstance->changeLanguage(
            objValue.value("language").toString());
        file.close();
    }
    LOG_INFO << " => end";
}

bool SettingsModel::loadData(const QString& key)
{
    if(key == "Language"){
        QString strLang = m_setting.value(key, "").toString();
        if(strLang.isEmpty()){
            return false;
        }

        Translator * tInstance = Translator::getInstance();
        tInstance->changeLanguage(strLang);
        return true;
    }
    if(key == "Volume"){
        int volume = m_setting.value(key, -1).toInt();
        if(volume == -1){
            return false;
        }
        VolumeController* vInstance = VolumeController::getInstance();
        vInstance->setCurrentVolume(volume);
        return true;
    }

    if(key == "Format24h"){
        bool checkFormat = m_setting.value("Format24h", false).toBool();

        DateController * instance = DateController::getInstance();
        instance->setFormat(checkFormat);
        return true;
    }
    if(key == "Customize"){
        bool checkCus = m_setting.value("Customize", false).toBool();
        DateController * instance = DateController::getInstance();
        instance->setCustom(checkCus);

        if(checkCus){
            LOG_INFO << " => start getting date time";
            // QVariant dateTime = m_setting.value(
            //                     "CustomizeTime", QString());
            QString dateTime = m_setting.value(
                                "CustomizeTime", QString()).toString();
            QString curTime = m_setting.value(
                                "CurrentTime", QString()).toString();
            qDebug() << "Date time getting is " << dateTime;
            instance->getUpdateCustom(dateTime, curTime);
            LOG_INFO << " => end getting date time";
        }
        instance->allowedSaveData = true;

        return true;
    }

    return false;
}

void SettingsModel::saveData(const QString& key, const QVariant& data)
{
    LOG_INFO << " => start";
    LOG_INFO << "Value is " << data;
    m_setting.setValue(key, data);
    LOG_INFO << " => end";
}
