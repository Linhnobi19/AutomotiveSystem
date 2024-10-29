#ifndef VIDEOLIB_H
#define VIDEOLIB_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "VideoLib_global.h"
#include "IFMediaInterface.h"


class VIDEOLIB_EXPORT VideoLib
{
    VideoLib();
public:
    static VideoLib* getInstance();
    void setListeners(IFMediaInterface *object, const QString &serviceName, const QString &objectPath,
                      const QString &serviceInterface);
    QJsonObject convertJsonObject(const QString &serviceName, const QString &objectPath,
                                  const QString &serviceInterface);
    QString getServiceName() const;
    QString getPathName() const;
    QString getInterface() const;
    void hideApp();
private:
    QString m_serviceName, m_pathName, m_interface;
};

#endif // VIDEOLIB_H
