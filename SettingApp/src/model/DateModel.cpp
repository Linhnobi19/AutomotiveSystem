#include "DateModel.h"
#include <QDebug>
#include <QDate>
#include "LogHelper.h"

DateModel::DateModel()
    : m_isFormat24h(false), m_isCustomize(false)
{
    LOG_INFO << " => start";
    QDate date = QDate::currentDate();
    m_hours = generate(12, 0);
    m_minutes = generate(60, 0);
    m_seconds = generate(60, 0);
    m_days = generate(date.daysInMonth(), 1);
    m_months = generate(12, 1);
    m_years = generate(300, date.year() - 150);
    LOG_INFO << "Called Date Model";

    connect(this, &DateModel::isFormat24hChanged, this,
            &DateModel::onIsFormatChanged);
    LOG_INFO << " => end";
}

DateModel *DateModel::getInstance()
{
    static DateModel* mydate = new DateModel();
    // if(mydate == nullptr){
    //     mydate = new DateModel();
    // }
    return mydate;
}


QStringList DateModel::hours() const
{
    return m_hours;
}

void DateModel::setHours(const QStringList &newHours)
{
    if (m_hours == newHours)
        return;
    m_hours = newHours;
    emit hoursChanged();
}

QStringList DateModel::seconds() const
{
    return m_seconds;
}

void DateModel::setSeconds(const QStringList &newSeconds)
{
    if (m_seconds == newSeconds)
        return;
    m_seconds = newSeconds;
    emit secondsChanged();
}

QStringList DateModel::minutes() const
{
    return m_minutes;
}

void DateModel::setMinutes(const QStringList &newMinutes)
{
    if (m_minutes == newMinutes)
        return;
    m_minutes = newMinutes;
    emit minutesChanged();
}

QStringList DateModel::days() const
{
    return m_days;
}

void DateModel::setDays(const QStringList &newDays)
{
    if (m_days == newDays)
        return;
    m_days = newDays;
    emit daysChanged();
}

QStringList DateModel::months() const
{
    return m_months;
}

void DateModel::setMonths(const QStringList &newMonths)
{
    if (m_months == newMonths)
        return;
    m_months = newMonths;
    emit monthsChanged();
}

QStringList DateModel::years() const
{
    return m_years;
}

void DateModel::setYears(const QStringList &newYears)
{
    if (m_years == newYears)
        return;
    m_years = newYears;

    emit yearsChanged();
}

bool DateModel::isFormat24h() const
{
    return m_isFormat24h;
}

void DateModel::setIsFormat24h(bool newIsFormat24h)
{
    if (m_isFormat24h == newIsFormat24h)
        return;
    m_isFormat24h = newIsFormat24h;
    emit isFormat24hChanged(m_isFormat24h);
}

bool DateModel::isCustomize() const
{
    return m_isCustomize;
}

void DateModel::setIsCustomize(bool newIsCustomize)
{
    if (m_isCustomize == newIsCustomize)
        return;
    m_isCustomize = newIsCustomize;
    emit isCustomizeChanged(m_isCustomize);
}

QStringList DateModel::generate(int number, int start)
{
    QStringList list;
    for(int i = start; i < start + number; i++){
        if(i < 10)
            list.append("0" + QString::number(i));
        else
            list.append(QString::number(i));
    }
    return list;
}

void DateModel::updateDays(int year, int month)
{
    QDate date;
    date.setDate(year, month, 1);
    setDays(generate(date.daysInMonth(), 1));
}

void DateModel::onIsFormatChanged(bool format)
{
    if(format){
        setHours(generate(24, 0));
    }
    else{
        setHours(generate(12, 0));
    }
}
