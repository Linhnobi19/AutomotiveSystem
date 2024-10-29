#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QTranslator>
#include <QQmlContext>
#include "DbusHandler.h"

class Translator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentLanguage READ currentLanguage
            WRITE setCurrentLanguage NOTIFY currentLanguageChanged FINAL)
    explicit Translator(QObject *parent = nullptr);
public:

    static Translator* getInstance();

    QString currentLanguage() const;
    void setCurrentLanguage(const QString &newCurrentLanguage);

    void initialize(QQmlContext* context);
public slots:
    void changeLanguage(const QString& codeLanguage);
    void saveDate(const QString& codeLanguage);
signals:
    void currentLanguageChanged(QString str);

private:
    QString m_currentLanguage;
    QTranslator* trans;

    DbusHandler* dbusHandler;
};

#endif // TRANSLATOR_H
