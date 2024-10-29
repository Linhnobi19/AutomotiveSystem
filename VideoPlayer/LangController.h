#ifndef LANGCONTROLLER_H
#define LANGCONTROLLER_H

#include <QObject>
#include <QTranslator>

class LangController : public QObject
{
    Q_OBJECT
public:
    static LangController *getInstance();
    void setLanguage(QString language);

signals:
    void languageChanged(QString tmp);

private:
    explicit LangController(QObject *parent = nullptr);
    QTranslator* translator;
};

#endif // LANGCONTROLLER_H
