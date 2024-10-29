#include "DbusHandler.h"
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QDebug>
#include "LogHelper.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "DateController.h"
#include "Translator.h"
#include "VolumeController.h"


DbusHandler::DbusHandler(QObject *parent)
    : m_visibleWin(false)
{
    registerDbus();
    connectToHome();
    homeCreated();
}

DbusHandler *DbusHandler::getInstance()
{
    static DbusHandler* dbusInstance = new DbusHandler();
    return dbusInstance;
}

void DbusHandler::registerDbus()
{
    LOG_INFO << " => start";
    serviceName = "settingapp.servicemock";
    pathName = "/settingappPath";
    interface = "com.fpt.SettingAppInterface";

    QDBusConnection connection = QDBusConnection::sessionBus();

    // register dbus connection name
    if(!connection.registerService(serviceName)){
        qDebug() << "Cannot register service name of setting app";
    }
    if(!connection.registerObject(pathName, interface,
                                   this, QDBusConnection::ExportAllSlots)){
        qDebug() << "Connot register object of setting app";
    }

    // this signal for every app ran before setting know
    QDBusMessage mess = QDBusMessage::createSignal(pathName, interface, "settingOpen");
    connection.send(mess);

    LOG_INFO << " => end";
}

void DbusHandler::callMethod(const QString &methodName, const QList<QVariant> &listArg)
{
    // LOG_INFO << " => start";
    for(auto listen : listeners){
        QDBusMessage message = QDBusMessage::createMethodCall(
            listen.service,
            listen.path,
            listen.interface,
            methodName);

        // qDebug() << "Service name: " << listen.service
        //          << "\nPath name: " << listen.path
        //          << "\nInterface: " << listen.interface << "\n";

        foreach(QVariant var, listArg){
            message << var;
        }
        QDBusReply<void> reply =
            QDBusConnection::sessionBus().call(message, QDBus::NoBlock);

        if(!reply.isValid()){
            qDebug() << "Error: " << reply.error();
        }
        // else {
        //     qDebug() << "Call method successfully";
        // }
    }
    // LOG_INFO << " => end";
}

void DbusHandler::connectToHome()
{
    QString pathHome = HomeLib::getInstance()->getPathName();
    QString interfaceHome = HomeLib::getInstance()->getInterface();
    QDBusConnection connection = QDBusConnection::sessionBus();
    connection.connect("", pathHome, interfaceHome, "homeOpen", this, SLOT(homeCreated()));
}

void DbusHandler::setVolume(int volume)
{
    LOG_INFO << " => start";
    QJsonObject jsObj;
    jsObj.insert("messageID", "change volume");
    jsObj.insert("data", volume);

    QJsonDocument doc(jsObj);
    QString msg = doc.toJson();
    callMethod("onDataReceived", {msg});
}

void DbusHandler::setLanguage(QString code)
{
    LOG_INFO << " => start";
    QJsonObject jsObj;
    jsObj.insert("messageID", "change language");
    jsObj.insert("data", code);

    QJsonDocument doc(jsObj);
    QString msg = doc.toJson();
    callMethod("onDataReceived", {msg});
}

void DbusHandler::setDate(QString date)
{
    // LOG_INFO << " => start";
    QJsonObject jsObj;
    jsObj.insert("messageID", "change date");
    jsObj.insert("data", date);

    QJsonDocument doc(jsObj);
    QString msg = doc.toJson();
    callMethod("onDataReceived", {msg});
}

void DbusHandler::setTime(QString time)
{
    // LOG_INFO << " => start";
    QJsonObject jsObj;
    jsObj.insert("messageID", "change time");
    jsObj.insert("data", time);

    QJsonDocument doc(jsObj);
    QString msg = doc.toJson();
    callMethod("onDataReceived", {msg});
}

void DbusHandler::hideSetting()
{
    setVisibleWin(false);
}

void DbusHandler::homeCreated()
{
    // set listener to home
    qDebug() << "Set listener here";
    HomeLib::getInstance()->setListeners(this, serviceName, pathName, interface);

}

void DbusHandler::showingApp(int temp)
{
    if(temp == 2){
        setVisibleWin(true);
        HomeLib::getInstance()->hideHome();
    }
}

void DbusHandler::quit()
{
    emit quitApp();
}

void DbusHandler::messageReceived(QString msg)
{
    LOG_INFO << " => start";
    QJsonDocument jsDoc = QJsonDocument::fromJson(msg.toUtf8());
    if(jsDoc.isObject()){
        // setting for format of json for listener set up to send to service
        QJsonObject jsObj = jsDoc.object();
        QString infMsg = jsObj.value("msg").toString();
        QJsonObject subObj = jsObj.value("data").toObject();
        if(infMsg == "addNew"){
            ClientInfo clientInfo;
            clientInfo.service = subObj.value("ServiceName").toString();
            clientInfo.path = subObj.value("Path").toString();
            clientInfo.interface = subObj.value("ServiceInterface").toString();

            // check service name is existed
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
            // each listener need to receive data when set and cann't wait
            // any data change
            DateController* dInstance = DateController::getInstance();
            setDate(dInstance->dateShowing());
            setTime(dInstance->timeShowing());
            setLanguage(Translator::getInstance()->currentLanguage());
            setVolume(VolumeController::getInstance()->currentVolume());

            qDebug() << "New client: " << clientInfo.service
                     << "\npath is: " << clientInfo.path
                     << "\ninterface: " << clientInfo.interface;
        }
    }
    LOG_INFO << " => end";
}

bool DbusHandler::visibleWin() const
{
    return m_visibleWin;
}

void DbusHandler::setVisibleWin(bool newVisibleWin)
{
    if (m_visibleWin == newVisibleWin)
        return;
    m_visibleWin = newVisibleWin;
    emit visibleWinChanged();
}

void DbusHandler::returnHome()
{
    HomeLib::getInstance()->returnHome();

}
