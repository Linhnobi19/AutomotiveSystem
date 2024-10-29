#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include "HomeLib.h"
#include "SettingLib.h"
#include "VideoLib.h"

struct ClientInfo
{
    ClientInfo() {}
    QString service = "";
    QString path = "";
    QString interface = "";
};
class DBusHandler : public QObject, public IFHomeInterfaces, public IFSettingAppListener,
                    public IFMediaInterface
{
    Q_OBJECT
    Q_CLASSINFO("APP_MUSIC", "com.fpt.MusicAppInterface")
public:
    static DBusHandler* getInstance();

    Q_INVOKABLE void convertMusic(const QString &title, const QString &artist, const QString &imagePath );

    void registerDbus();
    void callMethod(const QString &methodName, const QList<QVariant>& listArg);
    void connectToHome();
    void connectToSetting();
    void connectToVideo();

public slots:
    void messageReceived(QString msg);
    void returnHome();
    void showingApp(int temp);
    void quit();
    void onDataReceived(QString msg);
    void hideMusic();

    void homeCreated();
    void settingCreated();
    void videoCreated();

    void pauseAll();

    // function override
    void requestToPause(const QString& msg);
    void sendData(QString msg);


signals:
    void quitApp();
private:
    explicit DBusHandler(QObject *parent = nullptr);
    QString serviceName;
    QString path;
    QString interface;
    QList<ClientInfo> listeners;


};

#endif // DBUSHANDLER_H
