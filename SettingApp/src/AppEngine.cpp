#include "AppEngine.h"
#include "AppDefine.h"
#include "DateController.h"
#include "SettingController.h"
#include "LogHelper.h"
#include "VolumeController.h"
#include "Translator.h"
#include "DbusHandler.h"
#include "StatusBarController.h"


AppEngine* AppEngine::m_instance = nullptr;

AppEngine::AppEngine(QObject *parent)
    : QObject(parent)
    , m_initialized(false)
    , m_visibleWindow(true)
    , m_app(nullptr)
{
}

AppEngine::~AppEngine()
{
    LOG_INFO;
    m_app = nullptr;
}

AppEngine *AppEngine::getInstance()
{
    if(m_instance == nullptr)
    {
        m_instance = new AppEngine();
    }

    return m_instance;
}

void AppEngine::initialize(QGuiApplication *app)
{
    LOG_INFO << m_initialized;
    if(!m_initialized)
    {
        m_initialized = true;
        m_app = app;
        registerQmlObjects();
        createControllers();
        initControllers();
        initScreens();
    }
}

void AppEngine::updateWindow(QString msg)
{
    LOG_INFO << msg;
}

void AppEngine::registerQmlObjects()
{
    LOG_INFO << " => Start";
    qmlRegisterType<AppDefine>("AppEnums", 1, 0, "AppEnums");

    LOG_INFO << " => End";
}

void AppEngine::createControllers()
{
    LOG_INFO << " => Start";
    DbusHandler* dBusInstance = DbusHandler::getInstance();
    StatusBarController::getInstance();
    StatusBarController::getInstance()->loaderInstance(m_engine);
    SettingController *sInstance = SettingController::getInstance();
    DateController::getInstance();
    VolumeController::getInstance();
    Translator::getInstance();
    connect(dBusInstance, &DbusHandler::quitApp, m_app, &QGuiApplication::quit);
    QObject::connect(m_app, &QGuiApplication::aboutToQuit,
                     dBusInstance, &DbusHandler::returnHome);
    sInstance->loadAllData();

    LOG_INFO << " => End";
}

void AppEngine::initControllers()
{
    LOG_INFO << " => Start";
    DateController::getInstance()
        ->initialize(m_engine.rootContext());
    SettingController::getInstance()
        ->initialize(m_engine.rootContext());
    VolumeController::getInstance()
        ->initialize(m_engine.rootContext());
    Translator::getInstance()
        ->initialize(m_engine.rootContext());

    m_engine.rootContext()->setContextProperty("DbusHandler",
                                               DbusHandler::getInstance());

    QObject::connect(Translator::getInstance(),
                     &Translator::currentLanguageChanged, &m_engine,
                     &QQmlApplicationEngine::retranslate);

    LOG_INFO << " => End";
}

void AppEngine::initScreens()
{
    LOG_INFO << "InitScreen called" << " => Start";
    m_engine.load(QStringLiteral(MAIN_QML));
    if(m_engine.rootObjects().count() > 0)
    {
        // QMetaObject::invokeMethod(m_engine.rootObjects().at(0),
        //                           "updateVisible",
        //                           Q_ARG(QVariant, m_visibleWindow));
    }
    LOG_INFO << " => Start";
}
