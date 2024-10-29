#include "HomeLib.h"
#include <QDBusMessage>
#include <QDBusReply>
#include <QDBusConnection>
#include <QDebug>

HomeLib::HomeLib() {
    serviceName = "com.FinalMock.Dbus";
    pathName = "/HomeApp";
    interface =  "com.FinalMock.Dbus.Home";
}

HomeLib *HomeLib::getInstance()
{
    static HomeLib *temp = new HomeLib();
    return temp;
}

void HomeLib::setListeners(IFHomeInterfaces *object, const QString &serviceName, const QString &objectPath, const QString &serviceInterface)
{
    if(object == nullptr){
        qDebug() << "Object is null";
        return;
    }
    QDBusMessage mess = QDBusMessage::createMethodCall(this->serviceName, pathName, interface, "messageReceived");
    QJsonObject jsObj = convertJsonObject(serviceName, objectPath, serviceInterface);
    mess << QString(QJsonDocument(jsObj).toJson(QJsonDocument::Compact));
    QDBusReply<void> reply = QDBusConnection::sessionBus().call(mess, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

void HomeLib::sendMessage(const QString &msg)
{
    QDBusMessage mess = QDBusMessage::createMethodCall(serviceName, pathName, interface, "getMetaData");
    mess << msg;
    QDBusReply<void> reply = QDBusConnection::sessionBus().call(mess, QDBus::NoBlock);
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

void HomeLib::hideHome()
{
    QDBusMessage mess = QDBusMessage::createMethodCall
        (this->serviceName, pathName, interface, "hideHome");
    QDBusReply<void> reply = QDBusConnection::sessionBus().call(mess, QDBus::NoBlock);
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

void HomeLib::returnHome()
{
    QDBusMessage mess = QDBusMessage::createMethodCall(serviceName,
            pathName, interface, "returnHome");

    QDBusReply<void> reply = QDBusConnection::sessionBus().call(mess, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

QString HomeLib::getServiceName() const
{
    return serviceName;
}

QString HomeLib::getPathName() const
{
    return pathName;
}

QString HomeLib::getInterface() const
{
    return interface;
}

QJsonObject HomeLib::convertJsonObject(const QString &serviceName, const QString &objectPath, const QString &serviceInterface)
{
    QJsonObject jsObj, subObj;
    subObj.insert("ServiceName", serviceName);
    subObj.insert("Path", objectPath);
    subObj.insert("ServiceInterface", serviceInterface);
    jsObj.insert("msg", "addNew");
    jsObj.insert("data", subObj);
    return jsObj;
}
