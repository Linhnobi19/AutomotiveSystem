#ifndef MUSICLIB_H
#define MUSICLIB_H

#include "MusicLib_global.h"
#include <QObject>
#include "IFMediaInterface.h"

class MUSICLIB_EXPORT MusicLib
{
    QString m_serviceName = "musicapp.servicemock";
    QString m_pathName = "/musicappPath";
    QString m_interface = "com.fpt.MusicAppInterface";

    MusicLib() {}
public:
    static MusicLib* getInstance();
    void setListener(IFMediaInterface* obj, const QString &serviceName, const QString &path, const QString &interface);

    QString getServiceName() const;
    QString getPathName() const;
    QString getInterface() const;

    void hideApp();
};

#endif // MUSICLIB_H
