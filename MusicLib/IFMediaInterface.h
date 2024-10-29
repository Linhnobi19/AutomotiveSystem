#ifndef IFMEDIAINTERFACE_H
#define IFMEDIAINTERFACE_H
#include <QString>

class IFMediaInterface
{
public:
    IFMediaInterface() {}
    virtual ~IFMediaInterface() {}
    virtual void requestToPause(const QString& msg) = 0;
    virtual void sendData(QString msg) = 0;
};
#endif // IFMEDIAINTERFACE_H
