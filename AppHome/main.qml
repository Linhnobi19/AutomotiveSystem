import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import "./CommonComponent"
import Fpt.StatusBar 1.0

Window {
    width: 1080
    height: 608
    visible: !AppHome.checkOpenApp
    title: qsTr("Home App")
    Item{
        anchors.fill: parent
        // color: "lightgray"
        CustomStatusBar{
            id: statusBar
            width: parent.width
            height: 60
            textDirect: qsTr("Home")
            Component.onCompleted: {
                console.log("Status bar is created completely");
                modelListButton = [
                            {
                                "textButton" : "Home",
                                "image" : "home.png",
                                "func" : function() {
                                    console.log("click to home")
                                    appView.currentIndex = 0;
                                }
                            }

                        ]
            }
        }
        SwipeView{
            id: appView
            // width: 640
            // height: parent.height - statusBar.height - 30
            width: parent.width
            height: parent.height - statusBar.height - 30
            anchors.top: statusBar.bottom
            currentIndex: 0
            Item{
                Page01{
                    id: page01
                    width: parent.width
                    height: parent.height
                    anchors.top: parent.top
                    anchors.topMargin: 5
                }
            }
            Item{
                Page02{
                    id: page02
                    // width: 400
                    width: parent.width
                    height: parent.height
                    anchors.top: parent.top
                    anchors.topMargin: 5
                }
            }
        }
        CustomPageIndicator{
            id: customPageIndicator
            rectPage01: appView.currentIndex === 0 ? "blue" : "transparent"
            rectPage02: appView.currentIndex === 1 ? "blue" : "transparent"
            anchors.top: appView.bottom
            // anchors.left: parent.left
            // anchors.leftMargin: 270
            anchors.horizontalCenter: parent.horizontalCenter

        }
    }
}
