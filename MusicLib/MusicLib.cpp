#include "MusicLib.h"
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusReply>

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include "QDebug"

MusicLib *MusicLib::getInstance()
{
    static MusicLib *m_instance = new MusicLib();
    return m_instance;
}

void MusicLib::setListener(IFMediaInterface* obj, const QString &serviceName, const QString &path, const QString &interface)
{
    if(!obj){
        return;
    }
    QDBusMessage message = QDBusMessage::createMethodCall(
                m_serviceName,
                m_pathName,
                m_interface,
                "messageReceived" );

    QJsonObject jsObj;
    jsObj.insert("msg", "addNew");

    QJsonObject jsSubObj;
    jsSubObj.insert("ServiceName", serviceName);
    jsSubObj.insert("Path", path);
    jsSubObj.insert("ServiceInterface", interface);

    jsObj.insert("data", jsSubObj);

    message << QString(QJsonDocument(jsObj).toJson(QJsonDocument::Compact));

    QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

QString MusicLib::getServiceName() const
{
    return m_serviceName;
}

QString MusicLib::getPathName() const
{
    return m_pathName;
}

QString MusicLib::getInterface() const
{
    return m_interface;
}

void MusicLib::hideApp()
{
    QDBusMessage message = QDBusMessage::createMethodCall(
        m_serviceName,
        m_pathName,
        m_interface,
        "hideMusic" );

    QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
    qDebug() << "Method is called";
    if(!reply.isValid())
    {
        qDebug() << "Error: " << reply.error();
    }
}

