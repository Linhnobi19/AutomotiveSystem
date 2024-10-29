#ifndef SETTINGCONTROLLER_H
#define SETTINGCONTROLLER_H

#include <QObject>
#include "SettingsModel.h"
#include <QQmlContext>

class SettingController : public QObject
{
    Q_OBJECT
    explicit SettingController(QObject *parent = nullptr);
public:
    static SettingController* getInstance();
    Q_INVOKABLE void reset();
    void loadAllData();
    bool loadData(const QString& key);
    void saveData(const QString& key, const QVariant& data);
    void initialize(QQmlContext* context);

private:
    SettingsModel* instance;

};

#endif // SETTINGCONTROLLER_H
