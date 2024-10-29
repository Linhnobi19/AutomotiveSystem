#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include "Controller.h"
#include "Model.h"
class SettingController : public QObject
{
    Q_OBJECT
public:
    static SettingController *getInstance();
    void loadSettings();
public slots:
    void save();
    void setCurrentSongFromSetting();


private:
    explicit SettingController(QObject *parent = nullptr);
    int position = -1;
    QString title = "";
    bool found = false;

};

#endif // SETTINGCONTROLLER_H
