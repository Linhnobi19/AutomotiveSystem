#ifndef APPDEFINE_H
#define APPDEFINE_H

#include <QObject>
#include <QMap>

#define MAIN_QML    "qrc:/qml/main.qml"

class AppDefine : public QObject
{
    Q_OBJECT

    Q_ENUMS(SCREEN_ID)
public:

    enum SCREEN_ID : int {
        SCREEN_LANGUAGE,
        SCREEN_VOLUME,
        SCREEN_DATE,
        SCREEN_INFO,
        SCREEN_RESET
    };

};

// const QMap<int, QString> screenMap{
//     {AppDefine::SCREEN_LANGUAGE,
//      "qrc:/qml/Screens/LanguageScreen.qml"},
//     {AppDefine::SCREEN_VOLUME,
//      "qrc:/qml/Screens/VolumeScreen.qml"},
//     {AppDefine::SCREEN_DATE ,
//      "qrc:/qml/Screens/DateScreen.qml"},
//     {AppDefine::SCREEN_INFO ,
//      "qrc:/qml/Screens/InfomationScreen.qml"},
//     {AppDefine::SCREEN_RESET ,
//      "qrc:/qml/Screens/ResetScreen.qml"}
// };

#endif // APPDEFINE_H
