#ifndef DBUSHANDLERAPPHOME_H
#define DBUSHANDLERAPPHOME_H

#include <QObject>
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDebug>
#include <QList>
#include <QDBusReply>
#include "SettingLib.h"
#include "IFMediaInterface.h"

struct ClientInfor{
    ClientInfor(){}
    QString service = "";
    QString path = "";
    QString interface = "";
};

class DbusHandlerAppHome : public QObject, public IFSettingAppListener,
                           public IFMediaInterface
{
    Q_OBJECT
    Q_CLASSINFO("APP_HOME", "com.FinalMock.Dbus.Home")
public:
    explicit DbusHandlerAppHome(QObject *parent = nullptr);
    Q_PROPERTY(bool checkOpenApp READ checkOpenApp WRITE setCheckOpenApp NOTIFY checkOpenAppChanged FINAL)
    Q_PROPERTY(QString videoTitle READ videoTitle WRITE setVideoTitle NOTIFY videoTitleChanged FINAL)
    Q_PROPERTY(QString musicTitle READ musicTitle WRITE setMusicTitle NOTIFY musicTitleChanged FINAL)
    Q_PROPERTY(QString musicAuthor READ musicAuthor WRITE setMusicAuthor NOTIFY musicAuthorChanged FINAL)
    Q_PROPERTY(QString sourceImage READ sourceImage WRITE setSourceImage NOTIFY sourceImageChanged FINAL)
    Q_PROPERTY(int appRun READ appRun WRITE setAppRun NOTIFY appRunChanged FINAL)
    Q_INVOKABLE void openApp(int temp);
    bool checkOpenApp() const;
    void setCheckOpenApp(bool newCheckOpenApp);
    QString videoTitle() const;
    void setVideoTitle(const QString &newVideoTitle);
    QString musicTitle() const;
    void setMusicTitle(const QString &newMusicTitle);
    QString musicAuthor() const;
    void setMusicAuthor(const QString &newMusicAuthor);
    QString sourceImage() const;
    void setSourceImage(const QString &newSourceImage);

    void connectToSetting();
    void connectMusic();
    void connectToVideo();

    int appRun() const;
    void setAppRun(int newAppRun);

public slots:
    void callMethod(const QString &methodName, const QList<QVariant> &temp);
    void returnHome();
    void messageReceived(QString msg);
    void getMetaData(const QString &msg);
    void hideHome();

    void settingCreated();
    void onDataReceived(QString msg);   // slot override from setting
    void quitAllApp();

    void musicCreated();
    void requestToPause(const QString& msg);
    void sendData(QString msg);

    void videoCreated();
signals:
    void openVideoApp(int id);
    void checkOpenAppChanged();
    void videoTitleChanged();
    void musicTitleChanged();
    void musicAuthorChanged();
    void sourceImageChanged();

    void appRunChanged();

private:
    QList<ClientInfor> listeners;
    bool m_checkOpenApp;
    QString m_videoTitle;
    QString m_musicTitle;
    QString m_musicAuthor;
    QString m_sourceImage = "qrc:/SourceImage/musicBtn.png";


    int m_appRun;
};

#endif // DBUSHANDLERAPPHOME_H
