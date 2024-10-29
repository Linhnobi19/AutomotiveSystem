#ifndef SETTINGLIB_H
#define SETTINGLIB_H

#include <QtCore/qglobal.h>
#include <QObject>

#if defined(SETTINGLIB_LIBRARY)
#define SETTINGLIB_EXPORT Q_DECL_EXPORT
#else
#define SETTINGLIB_EXPORT Q_DECL_IMPORT
#endif


class IFSettingAppListener {
public:
    virtual void onDataReceived(QString msg) = 0;
};

class SETTINGLIB_EXPORT SettingLib
{
    SettingLib();

    QString serviceName;
    QString pathName;
    QString interface;
public:
    static SettingLib* getInstance();
    void setListener(IFSettingAppListener* object, const QString& sername,
                     const QString& path, const QString& interface);
    QString getServiceName() const;
    QString getPathName() const;
    QString getInterface() const;
};

#endif // SETTINGLIB_H
