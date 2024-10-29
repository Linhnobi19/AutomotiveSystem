#ifndef STATUSBAR_INTERFACE_H
#define STATUSBAR_INTERFACE_H

#include <QObject>
#include <QQmlApplicationEngine>

class StatusBarInterface
{
public:
    virtual ~StatusBarInterface() {}
    virtual QString StatusBarName() const = 0;
    virtual void registerObject(QQmlApplicationEngine *engine) = 0;

    // Hàm để truyền thông tin từ app vào plugin
    virtual void sendDateToPlugin(const QString &data) = 0;
    virtual void sendTimeToPlugin(const QString &data) = 0;
};

#define StatusBarInterface_iid "com.fpt.StatusBarInterface"

//macro trong Qt dùng để đăng ký một interface với hệ thống meta-object của Qt
Q_DECLARE_INTERFACE(StatusBarInterface, StatusBarInterface_iid)

#endif // STATUSBAR_INTERFACE_H
