#include "DbusHandlerAppHome.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QImage>
#include "StatusBarController.h"
#include "VideoLib.h"
#include "MusicLib.h"
#include "TranslaionController.h"

DbusHandlerAppHome::DbusHandlerAppHome(QObject *parent)
    : m_appRun(-1)
{
    QDBusConnection::sessionBus().registerService("com.FinalMock.Dbus");
    QDBusConnection::sessionBus().registerObject("/HomeApp", "com.FinalMock.Dbus.Home", this, QDBusConnection::ExportAllSlots);

    connect(this, &DbusHandlerAppHome::sourceImageChanged, [&](){
        if (m_sourceImage.isEmpty()) {
            setSourceImage("qrc:/SourceImage/musicBtn.png");
        }
    });

    QDBusConnection connection = QDBusConnection::sessionBus();


    // this signal for every app ran before setting know
    QDBusMessage mess = QDBusMessage::createSignal("/HomeApp", "com.FinalMock.Dbus.Home",
                                                   "homeOpen");
    connection.send(mess);
    connectToSetting();
    settingCreated();
    connectMusic();
    musicCreated();
    connectToVideo();
    videoCreated();
}

void DbusHandlerAppHome::openApp(int temp)
{
    callMethod("showingApp", {temp});
    qDebug() << "Open app " << temp;
}

void DbusHandlerAppHome::callMethod(const QString &methodName, const QList<QVariant> &temp)
{
    for(auto listen : listeners)
    {
        QDBusMessage message = QDBusMessage::createMethodCall(
            listen.service,
            listen.path,
            listen.interface,
            methodName);
        foreach (QVariant var, temp){
            message << var;
        }

        qDebug() << "Called to " << listen.service << " with method is " << methodName;

        QDBusReply<void> reply = QDBusConnection::sessionBus().call(message, QDBus::NoBlock);
        if(!reply.isValid())
        {
            qDebug() << "Error: " << reply.error();
        }
    }
}

void DbusHandlerAppHome::returnHome()
{
    qDebug() << "This function return home";
    setCheckOpenApp(false);
    SettingLib::getInstance()->hideApp();
    MusicLib::getInstance()->hideApp();
    VideoLib::getInstance()->hideApp();
}

void DbusHandlerAppHome::messageReceived(QString msg)
{
    qDebug() << "=>Start";
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject())
    {
        QJsonObject jsObj = jsDoc.object();
        QString infMsg = jsObj.value("msg").toString();
        QJsonObject subObj = jsObj.value("data").toObject();
        if(infMsg == "addNew")
        {
            ClientInfor client;
            client.service = subObj.value("ServiceName").toString();
            client.path    = subObj.value("Path").toString();
            client.interface = subObj.value("ServiceInterface").toString();

            bool isExisted = false;
            for(int i = 0; i < listeners.size(); i++){
                if(listeners[i].service == client.service){
                    isExisted = true;
                    break;
                }
            }
            if(!isExisted){
                listeners.append(client);
            }
            qDebug() << "New sevice: " << client.service;
            qDebug() << "New path: " << client.path;
            qDebug() << "New interface: " << client.interface;
        }
    }
}

void DbusHandlerAppHome::getMetaData(const QString &msg)
{
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject())
    {
        QJsonObject jsObj = jsDoc.object();
        QJsonObject subObj = jsObj.value("data").toObject();
        QString msgID = jsObj.value("messageID").toString();
        if(msgID == "info from music")
        {
            setAppRun(0);
            setMusicTitle(subObj.value("title").toString());
            setMusicAuthor(subObj.value("artist").toString());
            setSourceImage("file://" + subObj.value("imagePath").toString());
            qDebug() << subObj.value("imagePath").toString();
        }
        else if(msgID == "info from video")
        {
            setAppRun(1);
            setVideoTitle(subObj.value("title").toString());
            qDebug() << "video Title: " << subObj.value("title").toString();
        }
    }
}

void DbusHandlerAppHome::hideHome()
{
    setCheckOpenApp(true);
}

void DbusHandlerAppHome::settingCreated()
{
    SettingLib::getInstance()->setListener(this, "com.FinalMock.Dbus",
                                           "/HomeApp", "com.FinalMock.Dbus.Home");
}

void DbusHandlerAppHome::onDataReceived(QString msg)
{
    QJsonDocument doc = QJsonDocument::fromJson(msg.toUtf8());
    if(doc.isObject()){
        QJsonObject obj = doc.object();
        QString message = obj.value("messageID").toString();
        if(message == "change date"){
            // qDebug() << "New date is " << obj.value("data").toString();
            StatusBarController::getInstance()
                ->sendDate(obj.value("data").toString());
        }
        else if(message == "change time"){
            // qDebug() << "New time is " << obj.value("data").toString();
            StatusBarController::getInstance()
                ->sendTime(obj.value("data").toString());
        }
        else if(message == "change language"){
            qDebug() << "New language is " << obj.value("data").toString();
            TranslationController::getInstance()->setLanguage(obj.value("data").toString());
        }
        else if(message == "change volume"){
            qDebug() << "New volume is " << obj.value("data").toString();
        }
    }
    else {
        qDebug() << "Data is not an object Json";
    }
}

void DbusHandlerAppHome::quitAllApp()
{
    callMethod("quit", {});
}

void DbusHandlerAppHome::musicCreated()
{
    MusicLib::getInstance()->setListener(this, "com.FinalMock.Dbus",
                                "/HomeApp", "com.FinalMock.Dbus.Home");
}

void DbusHandlerAppHome::connectMusic()
{
    QString musicPath = MusicLib::getInstance()->getPathName();
    QString interfaceMusic = MusicLib::getInstance()->getInterface();
    QDBusConnection connect = QDBusConnection::sessionBus();
    connect.connect("", musicPath, interfaceMusic, "musicOpen", this,
                    SLOT(musicCreated()));
}

void DbusHandlerAppHome::connectToVideo()
{
    QString videoPath = VideoLib::getInstance()->getPathName();
    QString interfaceVideo = VideoLib::getInstance()->getInterface();
    QDBusConnection connect = QDBusConnection::sessionBus();
    connect.connect("", videoPath, interfaceVideo, "videoOpen", this,
                    SLOT(videoCreated()));
}

void DbusHandlerAppHome::requestToPause(const QString& msg)
{
    if(msg == "Request from music"){
        setAppRun(0);
    }
    else if(msg == "Request from video"){
        setAppRun(1);
    }
}

void DbusHandlerAppHome::sendData(QString msg)
{
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject())
    {
        QJsonObject jsObj = jsDoc.object();
        QJsonObject subObj = jsObj.value("data").toObject();
        QString msgID = jsObj.value("messageID").toString();
        if(msgID == "info from music")
        {
            setAppRun(0);
            setMusicTitle(subObj.value("title").toString());
            setMusicAuthor(subObj.value("artist").toString());
            setSourceImage("file://" + subObj.value("imagePath").toString());
            qDebug() << subObj.value("imagePath").toString();
        }
        else if(msgID == "info from video")
        {
            setAppRun(1);
            setVideoTitle(subObj.value("title").toString());
            qDebug() << "video Title: " << subObj.value("title").toString();
        }
    }
}

void DbusHandlerAppHome::videoCreated()
{
    VideoLib::getInstance()->setListeners(this, "com.FinalMock.Dbus",
                           "/HomeApp", "com.FinalMock.Dbus.Home");
}


bool DbusHandlerAppHome::checkOpenApp() const
{
    return m_checkOpenApp;
}

void DbusHandlerAppHome::setCheckOpenApp(bool newCheckOpenApp)
{
    if (m_checkOpenApp == newCheckOpenApp)
        return;
    m_checkOpenApp = newCheckOpenApp;
    emit checkOpenAppChanged();
}

QString DbusHandlerAppHome::videoTitle() const
{
    return m_videoTitle;
}

void DbusHandlerAppHome::setVideoTitle(const QString &newVideoTitle)
{
    if (m_videoTitle == newVideoTitle)
        return;
    m_videoTitle = newVideoTitle;
    emit videoTitleChanged();
}

QString DbusHandlerAppHome::musicTitle() const
{
    return m_musicTitle;
}

void DbusHandlerAppHome::setMusicTitle(const QString &newMusicTitle)
{
    if (m_musicTitle == newMusicTitle)
        return;
    m_musicTitle = newMusicTitle;
    emit musicTitleChanged();
}

QString DbusHandlerAppHome::musicAuthor() const
{
    return m_musicAuthor;
}

void DbusHandlerAppHome::setMusicAuthor(const QString &newMusicAuthor)
{
    if (m_musicAuthor == newMusicAuthor)
        return;
    m_musicAuthor = newMusicAuthor;
    emit musicAuthorChanged();
}

QString DbusHandlerAppHome::sourceImage() const
{
    return m_sourceImage;
}

void DbusHandlerAppHome::setSourceImage(const QString &newSourceImage)
{
    if (m_sourceImage == newSourceImage)
        return;
    m_sourceImage = newSourceImage;
    emit sourceImageChanged();
}

void DbusHandlerAppHome::connectToSetting()
{
    QString settingPath = SettingLib::getInstance()->getPathName();
    QString interfaceSetting = SettingLib::getInstance()->getInterface();
    qDebug() << settingPath;
    qDebug() << interfaceSetting;
    QDBusConnection connect = QDBusConnection::sessionBus();
    connect.connect("", settingPath, interfaceSetting, "settingOpen", this,
                    SLOT(settingCreated()));
}



int DbusHandlerAppHome::appRun() const
{
    return m_appRun;
}

void DbusHandlerAppHome::setAppRun(int newAppRun)
{
    if (m_appRun == newAppRun)
        return;
    m_appRun = newAppRun;
    qDebug() << "App run changed";
    emit appRunChanged();
}
