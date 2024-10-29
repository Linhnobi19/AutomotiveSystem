#ifndef STATUSBARCONTROLLER_H
#define STATUSBARCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "StatusBar_Interface.h"
#include <QPluginLoader>

class StatusBarController : public QObject
{
    Q_OBJECT
    explicit StatusBarController(QObject *parent = nullptr);
public:
    static StatusBarController* getInstance();
    ~StatusBarController();

    void loaderInstance(QQmlApplicationEngine& engine);

public slots:
    void sendDateToStatusBar(const QString& data);
    void sendTimeToStatusBar(const QString& data);

private:
    StatusBarInterface* interface;
    QPluginLoader* loader;
};

#endif // STATUSBARCONTROLLER_H
