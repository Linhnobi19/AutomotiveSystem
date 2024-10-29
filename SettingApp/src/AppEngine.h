#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>


class AppEngine : public QObject
{
    Q_OBJECT
private:
    explicit AppEngine(QObject *parent = nullptr);

public:
    ~AppEngine();

    // singleton pattern
    static AppEngine *getInstance();

    // initialize app
    void initialize(QGuiApplication *app);

public slots:
    void updateWindow(QString msg);

private:
    void registerQmlObjects();
    void createControllers();
    void initControllers();
    void initScreens();

private:
    static AppEngine* m_instance;
    bool m_initialized;
    bool m_visibleWindow;

    QGuiApplication* m_app;
    QQmlApplicationEngine m_engine;
};

#endif // APPENGINE_H
