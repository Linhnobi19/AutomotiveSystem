#include "SettingLib.h"
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>


SettingLib::SettingLib() {

    serviceName = "settingapp.servicemock";
    pathName = "/settingappPath";
    interface = "com.fpt.SettingAppInterface";

}

SettingLib *SettingLib::getInstance()
{
    static SettingLib* setApp = new SettingLib();
    return setApp;
}

void SettingLib::setListener(IFSettingAppListener *object,const QString &sername,
                             const QString &path, const QString &interface)
{
    if(object){
        QDBusMessage message = QDBusMessage::createMethodCall(
            serviceName,
            pathName,
            this->interface,
            "messageReceived");

        QJsonObject jsonObj;
        jsonObj.insert("msg", "addNew");

        QJsonObject jsonSubObj;
        jsonSubObj.insert("ServiceName", sername);
        jsonSubObj.insert("Path", (path));
        jsonSubObj.insert("ServiceInterface", interface );

        jsonObj.insert("data", jsonSubObj);

        message << QString(QJsonDocument(jsonObj).
                           toJson(QJsonDocument::Compact));

        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message);

        if(!reply.isValid()){
            qDebug() << "Error when call the message: " << reply.error();
        }
        else {
            qDebug() << "Successfully called a function from setting app";
        }
    }
}


QString SettingLib::getServiceName() const
{
    return serviceName;
}

QString SettingLib::getPathName() const
{
    return pathName;
}

QString SettingLib::getInterface() const
{
    return interface;
}

void SettingLib::hideApp()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        serviceName,
        pathName,
        this->interface,
        "hideSetting");

    QDBusReply<void> reply = QDBusConnection::sessionBus().call(message);

    if(!reply.isValid()){
        qDebug() << "Error when call the message: " << reply.error();
    }
    else {
        qDebug() << "Successfully called a hide fucntion from setting app";
    }
}


