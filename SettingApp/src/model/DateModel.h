#ifndef DATEMODEL_H
#define DATEMODEL_H

#include <QObject>
#include <QStringList>
#include <QString>

class DateModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList hours READ hours
                   WRITE setHours NOTIFY hoursChanged FINAL)
    Q_PROPERTY(QStringList seconds READ seconds
                   WRITE setSeconds NOTIFY secondsChanged FINAL)
    Q_PROPERTY(QStringList minutes READ minutes
                   WRITE setMinutes NOTIFY minutesChanged FINAL)
    Q_PROPERTY(QStringList days READ days
                   WRITE setDays NOTIFY daysChanged FINAL)
    Q_PROPERTY(QStringList months READ months
                   WRITE setMonths NOTIFY monthsChanged FINAL)
    Q_PROPERTY(QStringList years READ years
                   WRITE setYears NOTIFY yearsChanged FINAL)

    Q_PROPERTY(bool isFormat24h READ isFormat24h
                   WRITE setIsFormat24h NOTIFY isFormat24hChanged FINAL)
    Q_PROPERTY(bool isCustomize READ isCustomize
                   WRITE setIsCustomize NOTIFY isCustomizeChanged FINAL)
    DateModel();
public:
    static DateModel* getInstance();
    QStringList hours() const;
    void setHours(const QStringList &newHours);

    QStringList seconds() const;
    void setSeconds(const QStringList &newSeconds);

    QStringList minutes() const;
    void setMinutes(const QStringList &newMinutes);

    QStringList days() const;
    void setDays(const QStringList &newDays);

    QStringList months() const;
    void setMonths(const QStringList &newMonths);

    QStringList years() const;
    void setYears(const QStringList &newYears);

    bool isFormat24h() const;
    void setIsFormat24h(bool newIsFormat24h);

    bool isCustomize() const;
    void setIsCustomize(bool newIsCustomize);


    QStringList generate(int number, int start = 0);

public slots:
    void updateDays(int year, int month);
signals:
    void hoursChanged();
    void secondsChanged();

    void minutesChanged();

    void daysChanged();

    void monthsChanged();

    void yearsChanged();

    void isFormat24hChanged(bool format);

    void isCustomizeChanged(bool custom);

public slots:
    void onIsFormatChanged(bool format);

private:
    QStringList m_hours;
    QStringList m_seconds;
    QStringList m_minutes;
    QStringList m_days;
    QStringList m_months;
    QStringList m_years;
    bool m_isFormat24h;
    bool m_isCustomize;
};

#endif // DATEMODEL_H
