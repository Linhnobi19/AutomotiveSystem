#include "DBusHandler.h"

#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusReply>
#include <QtDBus/QDBusInterface>
#include <QtDBus/QDBusMessage>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <Controller.h>
#include "StatusBarController.h"
#include "LanguageController.h"
#include "Model.h"

DBusHandler::DBusHandler(QObject *parent)
{
    registerDbus();
    homeCreated();
    settingCreated();
    videoCreated();
    connectToHome();
    connectToSetting();
    connectToVideo();
}

DBusHandler *DBusHandler::getInstance()
{
    static DBusHandler *instance = new DBusHandler();
    return instance;
}

void DBusHandler::convertMusic(const QString &title, const QString &artist, const QString &imagePath)
{
    QJsonObject jsObj;
    jsObj.insert("messageID", "info from music");
    QJsonObject subObj;
    subObj.insert("title", title);
    subObj.insert("artist", artist);
    subObj.insert("imagePath", imagePath);
    jsObj.insert("data", subObj);
    QJsonDocument jsDoc(jsObj);
    QString str = jsDoc.toJson(QJsonDocument::Compact);
    qDebug() << "Json Music: " << str;
    // HomeLib::getInstance()->setListeners(this, "musicapp.servicemock", "/musicappPath", "com.fpt.MusicAppInterface" );
    // HomeLib::getInstance()->sendMessage(str);
    callMethod("sendData", {str});
}

void DBusHandler::registerDbus()
{
    serviceName = "musicapp.servicemock";
    path = "/musicappPath";
    interface = "com.fpt.MusicAppInterface";

    qDebug() << "registerService: " << QDBusConnection::sessionBus().registerService(serviceName);
    qDebug() << "registerObject: " << QDBusConnection::sessionBus().registerObject(path, interface,
                                                        this, QDBusConnection::ExportAllSlots);

    QDBusMessage mess = QDBusMessage::createSignal(path, interface,
                                                   "musicOpen");
    QDBusConnection::sessionBus().send(mess);
}



void DBusHandler::showingApp(int temp)
{
    if(temp == 0){
        Controller::getInstance()->setIsShow(true);
        HomeLib::getInstance()->hideHome();
    }
}

void DBusHandler::quit()
{
    emit quitApp();
}

void DBusHandler::onDataReceived(QString msg)
{
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
    if(doc.isObject()){
        QJsonObject obj = doc.object();
        QString message = obj.value("messageID").toString();
        if(message == "change date"){
            // qDebug() << "New date is " << obj.value("data").toString();
            StatusBarController::getInstance()
                ->sendDateToStatusBar(obj.value("data").toString());
        }
        else if(message == "change time"){
            // qDebug() << "New time is " << obj.value("data").toString();
            StatusBarController::getInstance()
                ->sendTimeToStatusBar(obj.value("data").toString());
        }
        else if(message == "change language"){
            if(obj.value("data").toString() == "VN"){
                LanguageController::getInstance()->setLanguage("Vietnam");
            }
            else {
                LanguageController::getInstance()->setLanguage("English");
            }

        }
        else if(message == "change volume"){
            Controller::getInstance()->setVolumeMedia(obj.value("data").toInt());
        }
    }
    else {
        qDebug() << "Data is not an object Json";
    }
}

void DBusHandler::hideMusic()
{
    Controller::getInstance()->setIsShow(false);
}

void DBusHandler::homeCreated()
{
    HomeLib::getInstance()->setListeners(this, "musicapp.servicemock",
                                         "/musicappPath", "com.fpt.MusicAppInterface" );
}

void DBusHandler::settingCreated()
{
    SettingLib::getInstance()->setListener(this, "musicapp.servicemock",
                                           "/musicappPath", "com.fpt.MusicAppInterface");
}

void DBusHandler::videoCreated()
{
    VideoLib::getInstance()->setListeners(this, "musicapp.servicemock",
                                            "/musicappPath", "com.fpt.MusicAppInterface");
}

void DBusHandler::pauseAll()
{
    callMethod("requestToPause", {"Request from music"});
}

void DBusHandler::sendData(QString msg)
{
    qDebug() << "Music func from app called do nothing in video";
}


void DBusHandler::callMethod(const QString &methodName, const QList<QVariant> &listArg)
{
    for(auto listener : listeners)
    {
        QDBusMessage message = QDBusMessage::createMethodCall(
                    listener.service,
                    listener.path,
                    listener.interface,
                    methodName);
        qDebug() << "Service name: " << listener.service
                 << "\nPath name: " << listener.path
                 << "\nInterface: " << listener.interface << "\n";
        foreach (QVariant var, listArg) {
            message << var;
        }
        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
        if(!reply.isValid()){
            qDebug() << "Error: " << reply.error();
        }
        else {
            qDebug() << "Call method successfully";
        }
    }
}

void DBusHandler::connectToHome()
{
    QString pathHome = HomeLib::getInstance()->getPathName();
    QString interfaceHome = HomeLib::getInstance()->getInterface();
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.connect("", pathHome, interfaceHome, "homeOpen", this, SLOT(homeCreated()));
}

void DBusHandler::connectToSetting()
{
    QString settingPath = SettingLib::getInstance()->getPathName();
    QString interfaceSetting = SettingLib::getInstance()->getInterface();
    qDebug() << settingPath;
    qDebug() << interfaceSetting;
    QDBusConnection connect = QDBusConnection::sessionBus();
    connect.connect("", settingPath, interfaceSetting, "settingOpen", this,
                    SLOT(settingCreated()));
}

void DBusHandler::connectToVideo()
{
    QString videoPath = VideoLib::getInstance()->getPathName();
    QString interfaceVideo = VideoLib::getInstance()->getInterface();
    QDBusConnection connect = QDBusConnection::sessionBus();
    connect.connect("", videoPath, interfaceVideo, "videoOpen", this,
                    SLOT(videoCreated()));
}

void DBusHandler::messageReceived(QString msg)
{
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject()){
        QJsonObject jsObj = jsDoc.object();
        QString infoMsg = jsObj.value("msg").toString();
        QJsonObject subObj = jsObj.value("data").toObject();
        if(infoMsg == "addNew"){
            ClientInfo clientInfo;
            clientInfo.service = subObj.value("ServiceName").toString();
            clientInfo.path = subObj.value("Path").toString();
            clientInfo.interface = subObj.value("ServiceInterface").toString();

            bool isExisted = false;
            for(int i = 0; i < listeners.size(); i++){
                if(listeners[i].service == clientInfo.service){
                    isExisted = true;
                    break;
                }
            }
            if(!isExisted){
                listeners.append(clientInfo);
            }
            Song* cur = Model::getInstance()->getCurrentSong();
            convertMusic(cur->getTitle(), cur->getArtist(), cur->getImagePath());

            qDebug() << "New client: " << clientInfo.service
                     << "\npath is: " << clientInfo.path
                     << "\ninterface: " << clientInfo.interface;


        }
    }
}

void DBusHandler::returnHome()
{
    HomeLib::getInstance()->returnHome();
}


void DBusHandler::requestToPause(const QString& msg)
{
    Controller::getInstance()->pause();
}
