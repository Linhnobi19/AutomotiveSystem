#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QPluginLoader>
#include "VideoModel.h"
#include "VideoHandler.h"
#include "StatusBarController.h"
#include "LangController.h"
#include "DBusHandler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    DBusHandler* videoDbus = DBusHandler::getInstance();
    engine.rootContext()->setContextProperty("DbusHandler", videoDbus);
    StatusBarController::getInstance()->loaderInstance(engine);
    engine.rootContext()->setContextProperty("VideoModel", VideoModel::getInstance());
    engine.rootContext()->setContextProperty("VideoHandler", VideoHandler::getInstance());
    QObject::connect(LangController::getInstance(), &LangController::languageChanged,
                     &engine, &QQmlApplicationEngine::retranslate);
    QObject::connect(videoDbus, &DBusHandler::quitApp,
                     &app, &QGuiApplication::quit);

    QObject::connect(&app, &QGuiApplication::aboutToQuit,
                     videoDbus, &DBusHandler::returnHome);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);
    return app.exec();
}
