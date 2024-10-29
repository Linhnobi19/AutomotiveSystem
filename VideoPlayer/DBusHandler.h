#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusMessage>
#include <QDebug>
#include <QDBusReply>
#include <QList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonObject>
#include "SettingLib.h"
#include "HomeLib.h"
#include "libMusic/IFMediaInterface.h"

struct ClientInfor{
    ClientInfor(){}
    QString service = "";
    QString path = "";
    QString interface = "";
};

class DBusHandler : public QObject, public IFSettingAppListener, public IFHomeInterfaces,
                    public IFMediaInterface
{
    Q_OBJECT
    Q_CLASSINFO("APP_VIDEO", "com.FinalMock.Dbus.Video")
public:
    static DBusHandler* getInstance();
    Q_INVOKABLE void convertVideoName(const QString &temp);
    void setListener();
    void emitSignalAndConnectFromOthers();

signals:
    void notifySignal();
    void quitApp();
public slots:

    void returnHome();
    void callMethod(const QString& methodName, const QList<QVariant>& args);
    void pauseAll();
    void onDataReceived(QString msg) override;
    void messageReceived(const QString &msg);
    void showingApp(int temp) override;
    void quit() override;
    void requestToPause(const QString& msg) override;
    void sendData(QString msg) override;

    // Video Slot
    void reSetListener();
    void hideVideo();
private:
    explicit DBusHandler(QObject *parent = nullptr);
    QList<ClientInfor> listeners;
};

#endif // DBUSHANDLER_H
