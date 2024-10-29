#include "DateController.h"
#include "DateModel.h"
#include <QDateTime>
#include <QDate>
#include <QDebug>
#include "LogHelper.h"
#include "SettingController.h"
#include "StatusBarController.h"

DateController::DateController()
    : m_timer(new QTimer()), currentDate(new QDate()), currentTime(new QTime())
    , m_isPM(false)
{
    LOG_INFO << " => start";
    /*DateModel**/ mInstance = DateModel::getInstance();
    dbusHandler = DbusHandler::getInstance();

    StatusBarController* sController = StatusBarController::getInstance();
    m_timer->setInterval(1000);
    connect(m_timer, &QTimer::timeout, this, &DateController::getUpdate);
    connect(mInstance, &DateModel::isFormat24hChanged, this,
            &DateController::onIsFormatChanged);
    connect(mInstance, &DateModel::isCustomizeChanged, this,
            &DateController::onIsCustomizeChanged);
    connect(this, &DateController::currentMonthChanged,
            mInstance, &DateModel::updateDays);
    connect(this, &DateController::currentYearChanged,
            mInstance, &DateModel::updateDays);
    connect(this, &DateController::timeShowingChanged,
            sController, &StatusBarController::sendTimeToStatusBar);
    connect(this, &DateController::dateShowingChanged,
            sController, &StatusBarController::sendDateToStatusBar);
    connect(this, &DateController::dateShowingChanged,
            dbusHandler, &DbusHandler::setDate);
    connect(this, &DateController::timeShowingChanged,
            dbusHandler, &DbusHandler::setTime);
    m_timer->start();
    LOG_INFO << " => end";
}

DateController *DateController::getInstance()
{
    static DateController* controller = new DateController();
    return controller;
}

int DateController::currentHour() const
{
    return m_currentHour;
}

void DateController::setCurrentHour(int newCurrentHour)
{
    if (m_currentHour == newCurrentHour)
        return;
    m_currentHour = newCurrentHour;
    emit currentHourChanged();
}

int DateController::currentMinute() const
{
    return m_currentMinute;
}

void DateController::setCurrentMinute(int newCurrentMinute)
{
    if (m_currentMinute == newCurrentMinute)
        return;
    m_currentMinute = newCurrentMinute;
    emit currentMinuteChanged();
}

int DateController::currentSecond() const
{
    return m_currentSecond;
}

void DateController::setCurrentSecond(int newCurrentSecond)
{
    if (m_currentSecond == newCurrentSecond)
        return;
    m_currentSecond = newCurrentSecond;
    emit currentSecondChanged();
}

int DateController::currentDay() const
{
    return m_currentDay;
}

void DateController::setCurrentDay(int newCurrentDay)
{
    if (m_currentDay == newCurrentDay)
        return;
    m_currentDay = newCurrentDay;
    emit currentDayChanged();
}

int DateController::currentMonth() const
{
    return m_currentMonth;
}

void DateController::setCurrentMonth(int newCurrentMonth)
{
    if (m_currentMonth == newCurrentMonth)
        return;
    m_currentMonth = newCurrentMonth;
    // qDebug() << "Current month is " << m_currentMonth + 1
    //          << "\nCurrent year is "
    //          << DateModel::getInstance()->years().at(m_currentYear);
    emit currentMonthChanged(DateModel::getInstance()->years().at(m_currentYear).toInt(),
                             m_currentMonth + 1);

    // update current Day
    if(m_currentDay > DateModel::getInstance()->days().size() - 1){
        setCurrentDay(0);
    }
}

int DateController::currentYear() const
{
    return m_currentYear;
}

void DateController::setCurrentYear(int newCurrentYear)
{
    if (m_currentYear == newCurrentYear)
        return;
    m_currentYear = newCurrentYear;
    // qDebug() << "Come here to change year";
    emit currentYearChanged(DateModel::getInstance()->years().at(m_currentYear).toInt(),
                            m_currentMonth + 1);
    if(m_currentDay > DateModel::getInstance()->days().size() - 1){
        setCurrentDay(0);
    }
}

void DateController::initialize(QQmlContext *context)
{
    if(context != nullptr){
        context->setContextProperty("DateController", this);
        context->setContextProperty("DateModel", DateModel::getInstance());
    }
}

void DateController::setFormat(bool format)
{
    DateModel::getInstance()->setIsFormat24h(format);
}

void DateController::setCustom(bool cus)
{
    DateModel::getInstance()->setIsCustomize(cus);
}


void DateController::onIsFormatChanged(bool format)
{
    LOG_INFO << " => start";
    if(allowedSaveData){
        m_timeShowing = convertTimeShowing(*currentTime, format);

    }
    if(!format && m_currentHour > 12){
        // because setting is not format 24h
        setCurrentHour(m_currentHour - 12);
    }
    else {
        int temp = m_currentHour;
        if(mInstance->isFormat24h() && m_isPM){
            temp += 12;
        }
        qDebug() << "Temp is " << temp;
        setCurrentHour(0);
        setCurrentHour(temp);
    }
    SettingController* sInstance = SettingController::getInstance();
    sInstance->saveData("Format24h", format);
    LOG_INFO << " => end";
}

void DateController::onIsCustomizeChanged(bool custom)
{
    LOG_INFO << " => start";
    SettingController* sInstance = SettingController::getInstance();
    sInstance->saveData("Customize", custom);
    if(custom && allowedSaveData){
        storingCustomTime();
    }
    LOG_INFO << " => end";
}

void DateController::getUpdate()
{
    // LOG_INFO << " => start";
    // m_timer->stop();
    DateModel* instance = DateModel::getInstance();
    if(!instance->isCustomize()){
        QDateTime date = QDateTime::currentDateTime();
        *currentDate = date.date();
        *currentTime = date.time();
        if(date.time().hour() > 12){
            setIsPM(true);
        }
        else {
            setIsPM(false);
        }
        setTimeShowing(convertTimeShowing(*currentTime, mInstance->isFormat24h()));
        setDateShowing((*currentDate).toString("dd/MM"));
        // m_actuallyHour = date.time().hour();
        if(!instance->isFormat24h() && date.time().hour() > 12){
            // because setting is not format 24h
            setCurrentHour(date.time().hour() - 12);
        }
        else {
            setCurrentHour(date.time().hour());
        }
        setCurrentMinute(date.time().minute());
        setCurrentSecond(date.time().second());
        setCurrentDay(date.date().day() - 1);
        setCurrentMonth(date.date().month() - 1);

        int start = instance->years().at(0).toInt();
        setCurrentYear(date.date().year() - start);
    }
    else{
        QDateTime date ;
        date.setDate(*currentDate);
        date.setTime(*currentTime);
        date = date.addSecs(1);
        *currentDate = date.date();
        *currentTime = date.time();
        setTimeShowing(convertTimeShowing(*currentTime, mInstance->isFormat24h()));
        setDateShowing((*currentDate).toString("dd/MM"));
    }
}

void DateController::storingCustomTime()
{
    if(mInstance->isCustomize()){
        // try to store the currentIndex
        QDateTime timeCus;
        QDate date;
        int year = (mInstance->years().at(m_currentYear)).toInt();
        date.setDate(year, m_currentMonth + 1, m_currentDay + 1);
        QTime time;
        if(m_isPM && !mInstance->isFormat24h()){
            time.setHMS(m_currentHour + 12,
                        m_currentMinute, m_currentSecond);
        }
        else{
            time.setHMS(m_currentHour,
                        m_currentMinute, m_currentSecond);
        }
        timeCus.setDate(date);
        timeCus.setTime(time);
        *currentDate = date;
        *currentTime = time;

        m_timer->stop();
        setTimeShowing(convertTimeShowing(time, mInstance->isFormat24h()));
        setDateShowing(date.toString("dd/MM"));
        m_timer->start();

        SettingController* sInstance = SettingController::getInstance();
        QDateTime timeCurrent = QDateTime::currentDateTime();
        sInstance->saveData("CustomizeTime",
                            QVariant::fromValue(timeCus.toString(Qt::ISODate)));
        sInstance->saveData("CurrentTime",
                            QVariant::fromValue(timeCurrent.toString(Qt::ISODate)));
        qDebug() << "Time cus is " << timeCus;

    }
}

void DateController::getUpdateCustom(const QString &dateStore,
                                     const QString& curTime)
{
    // if dateStore is QDateTime default ==> get CurrentDate
    LOG_INFO << " => start";
    qDebug() << "Come to getUpdateCustom after loading from setting";
    if(QDateTime::fromString(dateStore, Qt::ISODate).isNull() ||
        QDateTime::fromString(dateStore, Qt::ISODate) == QDateTime()){
        qDebug () << "no Data store";
        mInstance->setIsCustomize(false);
        this->getUpdate();
        mInstance->setIsCustomize(true);
    }
    else{
        QDateTime currentTime = QDateTime::currentDateTime();
        QDateTime currentCusTime;
        int mSec = currentTime.toMSecsSinceEpoch()
                   - QDateTime::fromString(curTime, Qt::ISODate).toMSecsSinceEpoch();
        currentCusTime = QDateTime::fromMSecsSinceEpoch(
            QDateTime::fromString(dateStore, Qt::ISODate)
                .toMSecsSinceEpoch() + mSec);
        qDebug() << "Current cusTime is " << currentCusTime;
        qDebug() << "Current time is " << currentCusTime.time();
        qDebug() << "Is format 24h " << mInstance->isFormat24h();
        // (*this->currentTime) = currentCusTime.time();
        // (*this->currentDate) = currentCusTime.date();
        // m_timeShowing = convertTimeShowing(currentCusTime.time(), mInstance->isFormat24h());
        // m_dateShowing = currentCusTime.date().toString("dd/MM");
        *this->currentTime = currentCusTime.time();
        *this->currentDate = currentCusTime.date();
        setTimeShowing(convertTimeShowing(currentCusTime.time(), mInstance->isFormat24h()));
        setDateShowing(currentCusTime.date().toString("dd/MM"));
        LOG_INFO << " End to update data";

        if(mInstance->isFormat24h()){
            setCurrentHour(currentCusTime.time().hour());
        }
        else {
            setCurrentHour(currentCusTime.time().hour() - 12);
        }
        if(currentCusTime.time().hour() > 12){
            setIsPM(true);
        }
        else{
            setIsPM(false);
        }
        setCurrentMinute(currentCusTime.time().minute());
        setCurrentSecond(currentCusTime.time().second());
        setCurrentDay(currentCusTime.date().day() - 1);
        setCurrentMonth(currentCusTime.date().month() - 1);
        LOG_INFO << "Before set year";
        int start = mInstance->years().at(0).toInt();
        setCurrentYear(currentCusTime.date().year() - start);
    }
    LOG_INFO << " => end";
}


QString DateController::convertTimeShowing(QTime time, bool format)
{
    if(format){
        if(time.hour() >= 12){
            setIsPM(true);
        }
        else {
            setIsPM(false);
        }
        return time.toString("hh:mm:ss");
    }
    else {
        int hour = time.hour();
        int minute = time.minute();
        int second = time.second();

        QString suffix; // Chuỗi để chứa AM hoặc PM tùy chỉnh

        if (hour >= 12) {
            suffix = tr("PM"); // Bạn có thể thay "PM" thành ký tự của ngôn ngữ khác
            if (hour > 12){
                setIsPM(true);
                hour -= 12; // Chuyển từ 24h sang 12h nếu cần
            }
        } else {
            suffix = tr("AM"); // Tương tự cho "AM"
            setIsPM(false);
            if (hour == 0)
            hour = 12; // Giờ 0 thành 12 AM
        }

        QString formattedTime = QString("%1:%2:%3 %4")
                                    .arg(hour, 2, 10, QChar('0'))  // Định dạng giờ
                                    .arg(minute, 2, 10, QChar('0')) // Định dạng phút
                                    .arg(second, 2, 10, QChar('0')) // Định dạng giây
                                    .arg(suffix); // Ký hiệu AM/PM tùy chỉnh
        // qDebug() << formattedTime;
        return formattedTime;
    }
}

bool DateController::isPM() const
{
    return m_isPM;
}

void DateController::setIsPM(bool newIsPM)
{
    if (m_isPM == newIsPM)
        return;
    m_isPM = newIsPM;
    emit isPMChanged();
}

QString DateController::dateShowing() const
{
    return m_dateShowing;
}

void DateController::setDateShowing(const QString &newDateShowing)
{
    if (m_dateShowing == newDateShowing)
        return;
    m_dateShowing = newDateShowing;
    emit dateShowingChanged(m_dateShowing);
}

QString DateController::timeShowing() const
{
    return m_timeShowing;
}

void DateController::setTimeShowing(QString newTimeShowing)
{
    if (m_timeShowing == newTimeShowing)
        return;
    m_timeShowing = newTimeShowing;
    emit timeShowingChanged(m_timeShowing);
}
