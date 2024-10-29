#ifndef TRANSLAIONCONTROLLER_H
#define TRANSLAIONCONTROLLER_H

#include <QObject>
#include <QTranslator>

class TranslationController : public QObject
{
    Q_OBJECT
public:
    static TranslationController *getInstance();
    void setLanguage(QString language);

signals:
    void languageChanged(QString tmp);

private:
    explicit TranslationController(QObject *parent = nullptr);
    QTranslator* translator;

signals:
};

#endif // TRANSLAIONCONTROLLER_H
