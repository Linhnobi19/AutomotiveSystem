#include "DBusHandler.h"
#include "StatusBarController.h"
#include "VideoHandler.h"
#include <QDBusConnection>
#include "LangController.h"
#include "MusicLib.h"

DBusHandler::DBusHandler(QObject *parent)
{
    QDBusConnection::sessionBus().registerService("com.FinalMock.Video");
    QDBusConnection::sessionBus().registerObject("/VideoApp", "com.FinalMock.Dbus.Video", this, QDBusConnection::ExportAllSlots);
    SettingLib::getInstance()->setListener(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
    HomeLib::getInstance()->setListeners(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
    MusicLib::getInstance()->setListener(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
    emitSignalAndConnectFromOthers();
}

void DBusHandler::emitSignalAndConnectFromOthers()
{
    QDBusMessage signalOpen = QDBusMessage::createSignal("/VideoApp", "com.FinalMock.Dbus.Video",
                                                              "videoOpen");
    QDBusConnection::sessionBus().send(signalOpen);
    QDBusConnection::sessionBus().connect(SettingLib::getInstance()->getServiceName(),
                                          SettingLib::getInstance()->getPathName(),
                                          SettingLib::getInstance()->getInterface(),
                                          "settingOpen", this, SLOT(reSetListener()));
    QDBusConnection::sessionBus().connect(HomeLib::getInstance()->getServiceName(),
                                          HomeLib::getInstance()->getPathName(),
                                          HomeLib::getInstance()->getInterface(),
                                          "homeOpen", this, SLOT(reSetListener()));  // Ban chuyen lai sang signal ben b

    QDBusConnection::sessionBus().connect(MusicLib::getInstance()->getServiceName(),
                                          MusicLib::getInstance()->getPathName(),
                                          MusicLib::getInstance()->getInterface(),
                                          "musicOpen", this, SLOT(reSetListener()));


}

void DBusHandler::reSetListener()
{
    SettingLib::getInstance()->setListener(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
    HomeLib::getInstance()->setListeners(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
    MusicLib::getInstance()->setListener(this, "com.FinalMock.Video", "/VideoApp", "com.FinalMock.Dbus.Video");
}

void DBusHandler::returnHome()
{
    HomeLib::getInstance()->returnHome();
}


void DBusHandler::hideVideo()
{
    VideoHandler::getInstance()->setCheckShowApp(false);
}

void DBusHandler::pauseAll()
{
    callMethod("requestToPause", {"Request from video"});
}


void DBusHandler::messageReceived(const QString &msg)
{
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject())
    {
        QJsonObject jsObj = jsDoc.object();
        QString infMsg = jsObj.value("msg").toString();
        QJsonObject subObj = jsObj.value("data").toObject();
        if(infMsg == "addNew")
        {
            ClientInfor client;
            client.service   = subObj.value("ServiceName").toString();
            client.path      = subObj.value("Path").toString();
            client.interface = subObj.value("ServiceInterface").toString();

            bool isExisted = false;
            for(int i = 0; i < listeners.size(); i++){
                if(listeners[0].service == client.service){
                    isExisted = true;
                    break;
                }
            }
            if(!isExisted){
                listeners.append(client);
            }


            // convertVideoName(VideoHandler::getInstance());
            qDebug() << "New sevice: "    << client.service;
            qDebug() << "New path: "      << client.path;
            qDebug() << "New interface: " << client.interface;
        }
    }
}


void DBusHandler::sendData(QString msg){
    qDebug() << "Do nothing here in video app";
}

DBusHandler *DBusHandler::getInstance()
{
    static DBusHandler* instance = new DBusHandler();
    return instance;
}

void DBusHandler::convertVideoName(const QString &temp)
{
    QJsonObject jsObj, subObj;
    subObj.insert("title", temp);
    jsObj.insert("messageID", "info from video");
    jsObj.insert("data", subObj);
    QJsonDocument jsDoc(jsObj);
    QString jsonString = jsDoc.toJson(QJsonDocument::Compact);
    // HomeLib::getInstance()->sendMessage(jsonString);
    // sendData();
    callMethod("sendData", {jsonString});
}

void DBusHandler::callMethod(const QString &methodName, const QList<QVariant> &args)
{
    for(auto listen : listeners)
    {
        QDBusMessage message = QDBusMessage::createMethodCall(
            listen.service,
            listen.path,
            listen.interface,
            methodName);
        foreach (QVariant var, args){
            message << var;
        }

        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
        if(!reply.isValid())
        {
            qDebug() << "Error: " << reply.error();
        }
    }
}

void DBusHandler::onDataReceived(QString msg)
{
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject())
    {
        QJsonObject jsObj = jsDoc.object();
        QString message = jsObj.value("messageID").toString();
        if(message == "change date"){
            // qDebug() << "New date is " << obj.value("data").toString();
            StatusBarController::getInstance()
                ->sendDateToStatusBar(jsObj.value("data").toString());
        }
        else if(message == "change time")
        {
            StatusBarController::getInstance()
            ->sendTimeToStatusBar(jsObj.value("data").toString());
        }
        else if(message == "change language")
        {
            qDebug() << "New language is " << jsObj.value("data").toString();
            LangController::getInstance()->setLanguage(jsObj.value("data").toString());
        }
        else if(message == "change volume"){
            qDebug() << "New volume is " << jsObj.value("data").toString();
            VideoHandler::getInstance()->setVolume(jsObj.value("data").toInt());
        }
    }
    else
    {
        qDebug() << "Data is not an object Json";
    }
}

void DBusHandler::showingApp(int temp)
{
    if(temp == 1)
    {
        VideoHandler::getInstance()->setCheckShowApp(true);
        HomeLib::getInstance()->hideHome();
    }
}

void DBusHandler::quit()
{
    qDebug() << "Test quit app";
    emit quitApp();
}

void DBusHandler::requestToPause(const QString& msg)
{
    VideoHandler::getInstance()->pause();
}
