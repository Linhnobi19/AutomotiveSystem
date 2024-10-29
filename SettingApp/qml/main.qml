import QtQuick 2.15
import QtQuick.Window 2.15
import "Screens"
import "CommonItems"
import AppEnums 1.0
import Fpt.StatusBar 1.0

Window {
    id: windowScreen
    width: 1080
    height: 608
    visible: DbusHandler.visibleWin
    // visible: true
    title: qsTr("STR_Setting App")

    function updateVisible(visibleW : Boolean) {
        console.log("Visible variable is %1".arg(visibleW))
        windowScreen.visible = visibleW;
    }

    Rectangle{
        id: background
        anchors.fill: parent
        color: "#FAF7F0"
    }

    CustomStatusBar{
        id: statusBar
        width: parent.width
        height: 60
        textDirect: qsTr("Setting")
        Component.onCompleted: {
            console.log("Status bar is created completely");
            modelListButton = [
                        {
                            "textButton" : "Back",
                            "image" : "left.png",
                            "func" : function() {
                                DbusHandler.returnHome();
                                console.log("click to back")
                            }
                        },
                        {
                            "textButton" : "Home",
                            "image" : "home.png",
                            "func" : function() {
                                console.log("click to home")
                                DbusHandler.returnHome();
                            }
                        }

                    ]
        }
    }

    property int widthScreen: windowScreen.width - leftSet.width
    LeftSetting{
        id: leftSet
        height: parent.height - 60
        anchors.bottom: parent.bottom

        onCurrentScreenChanged: {
            switch(currentScreen){
            case AppEnums.SCREEN_LANGUAGE:
                backgroundScreen.state = "languageScreen"
                break;
            case AppEnums.SCREEN_VOLUME:
                backgroundScreen.state = "volumeScreen"
                break;
            case AppEnums.SCREEN_DATE:
                backgroundScreen.state = "dateScreen"
                break;
            case AppEnums.SCREEN_INFO:
                backgroundScreen.state = "infoScreen"
                break;
            case AppEnums.SCREEN_RESET:
                backgroundScreen.state = "resetScreen"
                break;
            }
        }
    }

    Rectangle{
        id: backgroundScreen
        color: "transparent"
        width: windowScreen.widthScreen
        height: leftSet.height
        anchors {
            left: leftSet.right
            top: leftSet.top
        }

        state: "languageScreen"

        states: [
            State {
                name: "languageScreen"
                PropertyChanges {
                    target: languageScreen
                    visible: true
                }
                PropertyChanges {
                    target: volumeScreen
                    visible: false
                }
                PropertyChanges {
                    target: dateScreen
                    visible: false
                }
                PropertyChanges {
                    target: infoScreen
                    visible: false
                }
                PropertyChanges {
                    target: resetScreen
                    visible: false
                }
            },
            State {
                name: "volumeScreen"
                PropertyChanges {
                    target: languageScreen
                    visible: false
                }
                PropertyChanges {
                    target: volumeScreen
                    visible: true
                }
                PropertyChanges {
                    target: dateScreen
                    visible: false
                }
                PropertyChanges {
                    target: infoScreen
                    visible: false
                }
                PropertyChanges {
                    target: resetScreen
                    visible: false
                }
            },
            State {
                name: "dateScreen"
                PropertyChanges {
                    target: languageScreen
                    visible: false
                }
                PropertyChanges {
                    target: volumeScreen
                    visible: false
                }
                PropertyChanges {
                    target: dateScreen
                    visible: true
                }
                PropertyChanges {
                    target: infoScreen
                    visible: false
                }
                PropertyChanges {
                    target: resetScreen
                    visible: false
                }
            },
            State {
                name: "infoScreen"
                PropertyChanges {
                    target: languageScreen
                    visible: false
                }
                PropertyChanges {
                    target: volumeScreen
                    visible: false
                }
                PropertyChanges {
                    target: dateScreen
                    visible: false
                }
                PropertyChanges {
                    target: infoScreen
                    visible: true
                }
                PropertyChanges {
                    target: resetScreen
                    visible: false
                }
            },
            State {
                name: "resetScreen"
                PropertyChanges {
                    target: languageScreen
                    visible: false
                }
                PropertyChanges {
                    target: volumeScreen
                    visible: false
                }
                PropertyChanges {
                    target: dateScreen
                    visible: false
                }
                PropertyChanges {
                    target: infoScreen
                    visible: false
                }
                PropertyChanges {
                    target: resetScreen
                    visible: true
                }
            }
        ]

        LanguageScreen{
            id: languageScreen
            anchors.fill: parent
        }

        VolumeScreen{
            id: volumeScreen
            anchors.fill: parent
        }

        DateScreen{
            id: dateScreen
            anchors.fill: parent
            colorMask: "#FAF7F0"
        }
        InfomationScreen{
            id: infoScreen
        }
    }
    ResetScreen{
        id: resetScreen
        anchors.centerIn: parent
    }
}
