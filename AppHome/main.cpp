#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QObject>
#include "DbusHandlerAppHome.h"
#include "StatusBarController.h"
#include "ImageItem.h"
#include "TranslaionController.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    DbusHandlerAppHome HomeApp;
    StatusBarController::getInstance()->loaderInstance(engine);
    QObject::connect(&app, &QGuiApplication::aboutToQuit,
                     &HomeApp, &DbusHandlerAppHome::quitAllApp);
    QObject::connect(TranslationController::getInstance(),
                     &TranslationController::languageChanged,
                     &engine, &QQmlApplicationEngine::retranslate);
    TranslationController::getInstance()->setLanguage("EN");

    qmlRegisterType<ImageItem>("CustomImage", 1, 0, "CustomImage");

    engine.rootContext()->setContextProperty("AppHome", &HomeApp);
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
