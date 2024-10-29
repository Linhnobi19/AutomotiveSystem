#ifndef DATECONTROLLER_H
#define DATECONTROLLER_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QQmlContext>
#include "DateModel.h"
#include "DbusHandler.h"

class DateController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentHour READ currentHour
                   WRITE setCurrentHour NOTIFY currentHourChanged FINAL)
    Q_PROPERTY(int currentMinute READ currentMinute
                   WRITE setCurrentMinute NOTIFY currentMinuteChanged FINAL)
    Q_PROPERTY(int currentSecond READ currentSecond
                   WRITE setCurrentSecond NOTIFY currentSecondChanged FINAL)
    Q_PROPERTY(int currentDay READ currentDay
                   WRITE setCurrentDay NOTIFY currentDayChanged FINAL)
    Q_PROPERTY(int currentMonth READ currentMonth
                   WRITE setCurrentMonth NOTIFY currentMonthChanged FINAL)
    Q_PROPERTY(int currentYear READ currentYear
                   WRITE setCurrentYear NOTIFY currentYearChanged FINAL)
    Q_PROPERTY(bool isPM READ isPM WRITE setIsPM NOTIFY isPMChanged FINAL)

    Q_PROPERTY(QString dateShowing READ dateShowing WRITE setDateShowing NOTIFY dateShowingChanged FINAL)
    Q_PROPERTY(QString timeShowing READ timeShowing WRITE setTimeShowing NOTIFY timeShowingChanged FINAL)

    DateController();
public:
    static DateController* getInstance();
    bool allowedSaveData = false;   // avoid the first time that load Data
                                    // and change from setting

    int currentHour() const;
    void setCurrentHour(int newCurrentHour);

    int currentMinute() const;
    void setCurrentMinute(int newCurrentMinute);

    int currentSecond() const;
    void setCurrentSecond(int newCurrentSecond);

    int currentDay() const;
    void setCurrentDay(int newCurrentDay);

    int currentMonth() const;
    void setCurrentMonth(int newCurrentMonth);

    int currentYear() const;
    void setCurrentYear(int newCurrentYear);

    void initialize(QQmlContext* context);

    void setFormat(bool format);
    void setCustom(bool cus);

    bool isPM() const;
    void setIsPM(bool newIsPM);

    QString dateShowing() const;
    void setDateShowing(const QString &newDateShowing);

    QString timeShowing() const;
    void setTimeShowing(QString newTimeShowing);

public slots:
    void onIsFormatChanged(bool format);
    void onIsCustomizeChanged(bool custom);
    void getUpdate();
    void storingCustomTime();
    void getUpdateCustom(const QString& dateStore,
                         const QString& curTime);

signals:

    void currentHourChanged();

    void currentMinuteChanged();

    void currentSecondChanged();

    void currentDayChanged();

    void currentMonthChanged(int year, int month);

    void currentYearChanged(int year, int month);
    void isPMChanged();

    void dateShowingChanged(QString dateChange);

    void timeShowingChanged(QString timeChange);

private:
    // utility for storing data

    QTimer* m_timer;
    int m_actuallyHour = 0;
    int m_currentHour = 0;
    int m_currentMinute = 0;
    int m_currentSecond = 0;
    int m_currentDay = 0;
    int m_currentMonth = 0;
    int m_currentYear = 0;

    DbusHandler* dbusHandler;

    DateModel* mInstance;

    QDate* currentDate;
    QTime* currentTime;

    bool m_isPM;
    QString m_dateShowing;
    QString m_timeShowing;
    QString convertTimeShowing(QTime time, bool format);
};

#endif // DATECONTROLLER_H
