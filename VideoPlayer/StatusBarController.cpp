#include "StatusBarController.h"
#include <QPluginLoader>
#include <QDebug>
#include <QDir>

StatusBarController::StatusBarController(QObject *parent)
    : QObject{parent}
{}
StatusBarController *StatusBarController::getInstance()
{
    static StatusBarController* statusBar = new StatusBarController();
    return statusBar;
}

StatusBarController::~StatusBarController()
{
    interface = nullptr;
    loader->unload();
}

void StatusBarController::loaderInstance(QQmlApplicationEngine &engine)
{
    qDebug() << QDir::currentPath();
    QDir dir = QDir::currentPath();
    dir.cd("../StatusBarPlugin");
    qDebug() << dir.absolutePath();
    const QStringList entries = dir.entryList(QStringList() << "*.so", QDir::Files);
    foreach(QString name, entries) {
        QPluginLoader* loader = new QPluginLoader(dir.absoluteFilePath(name));
        qDebug() << "Loading plugin from:" << loader->fileName();
        QObject *plugin = loader->instance();

        if (plugin) {
            interface = qobject_cast<StatusBarInterface*>(plugin);
            if (interface) {
                this->loader = loader;
                interface->registerObject(&engine);
            } else {
                qDebug() << "Failed to cast to StatusBarInterface.";
            }
        } else {
            qDebug() << "Failed to load plugin:" << loader->errorString();
            qDebug() << "Error while loading:" << loader->fileName();
        }
    }
}



void StatusBarController::sendDateToStatusBar(const QString &data)
{
    if(interface){
        interface->sendDateToPlugin(data);
    }
}

void StatusBarController::sendTimeToStatusBar(const QString &data)
{
    if(interface){
        interface->sendTimeToPlugin(data);
    }
}
