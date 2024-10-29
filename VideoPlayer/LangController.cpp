#include "LangController.h"
#include <QCoreApplication>
#include <QDebug>

LangController::LangController(QObject *parent)
    : QObject{parent}
{
    translator = new QTranslator();
}

LangController *LangController::getInstance()
{
    static LangController* instance = new LangController();
    return instance;
}

void LangController::setLanguage(QString language)
{
    if(translator)
    {
        qDebug() << "Come here";
        qApp->removeTranslator(translator);
        translator = new QTranslator();
    }
    if(language == "EN")
    {
        if(translator->load(":/trans_ENG.qm"))
        {
            qApp->installTranslator(translator);
        }
    }
    if(language == "VN")
    {
        if(translator->load(":/trans_VN.qm"))
        {
            qDebug() << "Come here to load vn language";
            qApp->installTranslator(translator);
        }
    }
    emit languageChanged(language);
}
