#include "StatusBar.h"
#include <QQmlContext>
#include <QUrl>

StatusBar::StatusBar() {}

QString StatusBar::StatusBarName() const
{
    return "StatusBarPlugin";
}

StatusBar::~StatusBar()
{

}

void StatusBar::registerObject(QQmlApplicationEngine *engine)
{
    if(engine){
        engine->rootContext()->setContextProperty("DateShow", this);
    }
    qmlRegisterType(QUrl("qrc:/StatusBarPlug.qml"),
                    "Fpt.StatusBar",1 , 0,"CustomStatusBar");
}

void StatusBar::sendTimeToPlugin(const QString &data)
{
    if(!data.isEmpty()){
        setTime(data);
    }
}

void StatusBar::sendDateToPlugin(const QString &data)
{
    if(!data.isEmpty()){
        setDate(data);
    }
}

QString StatusBar::date() const
{
    return m_date;
}

void StatusBar::setDate(const QString &newDate)
{
    if (m_date == newDate)
        return;
    m_date = newDate;
    emit dateChanged();
}

QString StatusBar::time() const
{
    return m_time;
}

void StatusBar::setTime(const QString &newTime)
{
    if (m_time == newTime)
        return;
    m_time = newTime;
    emit timeChanged();
}
