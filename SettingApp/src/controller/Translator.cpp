 #include "Translator.h"
#include "LogHelper.h"
#include <QGuiApplication>
#include <SettingController.h>

Translator::Translator(QObject *parent)
    : QObject{parent}, trans(new QTranslator())
{
    connect(this, &Translator::currentLanguageChanged,
            this, &Translator::saveDate);
    dbusHandler = DbusHandler::getInstance();
    connect(this, &Translator::currentLanguageChanged,
            dbusHandler, &DbusHandler::setLanguage);
}

Translator *Translator::getInstance()
{
    static Translator* translation;
    if(translation == nullptr){
        translation = new Translator();
    }
    return translation;
}




QString Translator::currentLanguage() const
{
    return m_currentLanguage;
}

void Translator::setCurrentLanguage(const QString &newCurrentLanguage)
{
    if (m_currentLanguage == newCurrentLanguage)
        return;
    m_currentLanguage = newCurrentLanguage;
    emit currentLanguageChanged(m_currentLanguage);
}

void Translator::changeLanguage(const QString &codeLanguage)
{
    if(m_currentLanguage != codeLanguage){
        qApp->removeTranslator(trans);
        if(trans->load(QString
                        (":/translation/myapp_%1.qm").arg(codeLanguage))){
            LOG_INFO << "loaded successfully";
            qApp->installTranslator(trans);
            setCurrentLanguage(codeLanguage);
        }
        else{
            LOG_INFO << "Can not load the file translation";
        }
    }
}

void Translator::saveDate(const QString &codeLanguage)
{
    SettingController* sInstance = SettingController::getInstance();
    sInstance->saveData("Language", codeLanguage);
}

void Translator::initialize(QQmlContext *context)
{
    context->setContextProperty("Translator", this);
}
