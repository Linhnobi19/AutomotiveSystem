#include "VideoLib.h"
#include <QDBusMessage>
#include <QDBusReply>
#include <QDBusConnection>
#include <QDebug>
VideoLib::VideoLib() {
    m_serviceName = "com.FinalMock.Video";
    m_pathName    = "/VideoApp";
    m_interface   = "com.FinalMock.Dbus.Video";
}

VideoLib *VideoLib::getInstance()
{
    static VideoLib *temp = new VideoLib();
    return temp;
}

void VideoLib::setListeners(IFMediaInterface *object, const QString &serviceName, const QString &objectPath, const QString &serviceInterface)
{
    if(object == nullptr){
        qDebug() << "Object is null";
        return;
    }
    QDBusMessage mess = QDBusMessage::createMethodCall(m_serviceName, m_pathName, m_interface, "messageReceived");
    QJsonObject jsObj = convertJsonObject(serviceName, objectPath, serviceInterface);
    mess << QString(QJsonDocument(jsObj).toJson(QJsonDocument::Compact));
    QDBusReply<void> reply = QDBusConnection::sessionBus().call(mess, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

QJsonObject VideoLib::convertJsonObject(const QString &serviceName, const QString &objectPath, const QString &serviceInterface)
{
    QJsonObject jsObj, subObj;
    subObj.insert("ServiceName", serviceName);
    subObj.insert("Path", objectPath);
    subObj.insert("ServiceInterface", serviceInterface);
    jsObj.insert("msg", "addNew");
    jsObj.insert("data", subObj);
    qDebug() << "Add successfully";
    return jsObj;
}

QString VideoLib::getServiceName() const
{
    return m_serviceName;
}

QString VideoLib::getPathName() const
{
    return m_pathName;
}

QString VideoLib::getInterface() const
{
    return m_interface;
}

void VideoLib::hideApp()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        m_serviceName,
        m_pathName,
        m_interface,
        "hideVideo" );
    QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}
