#include "TranslaionController.h"
#include <QDebug>
#include <QGuiApplication>

TranslationController::TranslationController(QObject *parent)
    : QObject{parent}
{
    translator = new QTranslator();
}

TranslationController *TranslationController::getInstance()
{
    static TranslationController* transController = new TranslationController();
    return transController;
}

void TranslationController::setLanguage(QString language)
{
    if(translator)
    {
        qApp->removeTranslator(translator);
        translator = new QTranslator();
    }
    if(language == "EN")
    {
        if(translator->load(":/trans_EN.qm"))
        {
            qApp->installTranslator(translator);
        }
    }
    if(language == "VN")
    {
        if(translator->load(":/trans_VN.qm"))
        {
            qApp->installTranslator(translator);
        }
    }
    emit languageChanged(language);
}
