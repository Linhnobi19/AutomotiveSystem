#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "StatusBar_Interface.h"
#include <QObject>
#include <QQmlApplicationEngine>

class StatusBar : public QObject, public StatusBarInterface
{
    Q_OBJECT
    //đăng ký metadata của plugin với hệ thống plugin của Qt
    Q_PLUGIN_METADATA(IID StatusBarInterface_iid)
    //thông báo cho hệ thống plugin của Qt về các interface mà nó cần nhận diện và hỗ trợ
    Q_INTERFACES(StatusBarInterface)

    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged FINAL)
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged FINAL)
public:
    StatusBar();

    // StatusBarInterface interface
public:
    QString StatusBarName() const;
    ~StatusBar();
    void registerObject(QQmlApplicationEngine *engine);
    void sendDateToPlugin(const QString &data);
    void sendTimeToPlugin(const QString &data);

    QString date() const;
    void setDate(const QString &newDate);
    QString time() const;
    void setTime(const QString &newTime);

signals:
    void dateChanged();
    void timeChanged();

private:
    QString m_date;
    QString m_time;
};

#endif // STATUSBAR_H
