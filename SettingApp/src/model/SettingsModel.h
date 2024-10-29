#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include <QObject>
#include <QSettings>


class SettingsModel : public QObject
{
    Q_OBJECT

    explicit SettingsModel(QObject *parent = nullptr);

public:
    static SettingsModel* getInstance();

    void loadAllData();
    void resetToDefault();
    bool loadData(const QString& key);
    void saveData(const QString& key, const QVariant& data);

private:
    QSettings m_setting;

};

#endif // SETTINGSMODEL_H
