#ifndef DBUSHANDLER_H
#define DBUSHANDLER_H

#include <QObject>
#include "HomeLib.h"


struct ClientInfo{
    ClientInfo() {}
    QString service = "";
    QString path = "";
    QString interface = "";
};

class DbusHandler : public QObject, public IFHomeInterfaces
{
    Q_OBJECT

    Q_CLASSINFO("DBus Interface", "com.fpt.SettingAppInterface")
    Q_PROPERTY(bool visibleWin READ visibleWin WRITE setVisibleWin NOTIFY visibleWinChanged FINAL)
    explicit DbusHandler(QObject *parent = nullptr);
public:
    static DbusHandler* getInstance();

    void registerDbus();

    void callMethod(const QString& methodName,
                    const QList<QVariant>& listArg);

    void connectToHome();

    bool visibleWin() const;
    void setVisibleWin(bool newVisibleWin);


public slots:
    void returnHome();
    void messageReceived(QString msg);
    void setVolume(int volume);
    void setLanguage(QString code);
    void setDate(QString date);
    void setTime(QString time);
    void hideSetting();

    void homeCreated();
    // 2 more function

private:
    QString serviceName;
    QString pathName;
    QString interface;

    QList<ClientInfo> listeners;

    // IFHomeInterfaces interface
    bool m_visibleWin;

public slots:
    void showingApp(int temp);
    void quit();
signals:
    void visibleWinChanged();
    void quitApp();
};

#endif // DBUSHANDLER_H
