#include "LanguageController.h"
#include <QCoreApplication>
#include "DBusHandler.h"
#include <QDebug>
LanguageController::LanguageController(QObject *parent) : QObject(parent)
{
    translator = new QTranslator();
//    connect(this, SIGNAL(languageChanged(QString)),
//            DBusHandler::getInstance(), SLOT(setLanguage(QString)));
}

LanguageController *LanguageController::getInstance()
{
    static LanguageController* instance = new LanguageController();
    return instance;
}

void LanguageController::setLanguage(QString language)
{
    qDebug() << 1;
    if(translator)
    {
        qApp->removeTranslator(translator);
        translator = new QTranslator();
    }
    if(language == "English")
    {
        if(translator->load(":/language/Media_EN.qm"))
        {
            qApp->installTranslator(translator);
        }
    }
    if(language == "Vietnam")
    {
        if(translator->load(":/language/Media_VN.qm"))
        {
            qApp->installTranslator(translator);
        }
    }
    emit languageChanged(language);
}



