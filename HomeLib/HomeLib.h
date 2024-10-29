#ifndef HOMELIB_H
#define HOMELIB_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "HomeLib_global.h"

class IFHomeInterfaces {
public:
    //virtual void requestPause(x) = 0;
    virtual void showingApp(int temp) = 0;
    virtual void quit() = 0;
};

class HOMELIB_EXPORT HomeLib
{
    HomeLib();
public:
    static HomeLib * getInstance();
    void setListeners(IFHomeInterfaces *object, const QString &serviceName, const QString &objectPath,
                      const QString &serviceInterface);
    void sendMessage(const QString &msg);
    void hideHome();

    void returnHome();

    QString getServiceName() const;
    QString getPathName() const;
    QString getInterface() const;
private:
    QString serviceName;
    QString pathName;
    QString interface;
    QJsonObject convertJsonObject(const QString &serviceName, const QString &objectPath,
                                  const QString &serviceInterface);
};

#endif // HOMELIB_H
