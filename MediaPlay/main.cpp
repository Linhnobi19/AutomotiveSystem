#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QThread>
#include "Model.h"
#include "Controller.h"
#include "DBusHandler.h"
#include "StatusBarController.h"
#include "LanguageController.h"
#include "SettingController.h"
#include <QObject>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    StatusBarController::getInstance()->loaderInstance(engine);
    engine.rootContext()->setContextProperty("Controller",Controller::getInstance());

    engine.rootContext()->setContextProperty("Model",  Model::getInstance());
//    QThread::msleep(3000);

    SettingController::getInstance();
    engine.rootContext()->setContextProperty("DBusHandler", DBusHandler::getInstance());
    engine.rootContext()->setContextProperty("Language", LanguageController::getInstance());

    QObject::connect(LanguageController::getInstance(), &LanguageController::languageChanged,
            &engine, &QQmlApplicationEngine::retranslate);

    QObject::connect(DBusHandler::getInstance(), &DBusHandler::quitApp,
                     &app, &QGuiApplication::quit);
    QObject::connect(&app, &QGuiApplication::aboutToQuit,
                     DBusHandler::getInstance(), &DBusHandler::returnHome);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();

}
