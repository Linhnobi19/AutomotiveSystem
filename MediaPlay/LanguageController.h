#ifndef LANGUAGECONTROLLER_H
#define LANGUAGECONTROLLER_H

#include <QObject>
#include <QTranslator>
class LanguageController : public QObject
{
    Q_OBJECT
public:
    static LanguageController *getInstance();
public slots:
    void setLanguage(QString language);

signals:
    void languageChanged(QString tmp);
private:
    explicit LanguageController(QObject *parent = nullptr);
    QTranslator* translator;
};

#endif // LANGUAGECONTROLLER_H
