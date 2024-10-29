import QtQuick 2.15

Rectangle {
    id: root
    width: 300
    // height: parent.height
    border.color: "blue"
    border.width: 2
    color: "transparent"
    property int currentScreen: 0
    property var modelStr: [qsTr("STR_Language"), qsTr("STR_Volumne"),
        qsTr("STR_Date/Time"), qsTr("STR_System Infomation"),
        qsTr("STR_Reset")]

    ListView{
        id: listSetting
        width: root.width
        height: root.height
        model: root.modelStr
        currentIndex: parent.currentScreen
        interactive: false
        highlight: Image{
            // anchors.fill: parent.width
            width: parent.width
            height: listSetting.height / listSetting.count
            // fillMode: Image.PreserveAspectCrop
            source: "qrc:/images/highlight.png"
        }

        delegate: Rectangle{
            width: listSetting.width
            height: listSetting.height / listSetting.count
            color: "transparent"
            Rectangle{
                id: lineBottom
                width: parent.width - 10
                height: 2
                anchors{
                    bottom: parent.bottom
                    horizontalCenter: parent.horizontalCenter
                }
                color: "gray"
                visible: index === listSetting.count - 1 ? false : true
            }
            Text {
                id: textSetting
                text: modelData
                color: listSetting.currentIndex == index ? "red" : "black"
                font {
                    pointSize: 14
                    bold: true
                }
                anchors {
                    left: parent.left
                    leftMargin: 30
                    verticalCenter: parent.verticalCenter
                }
            }

            Rectangle{
                id: mask
                anchors.fill: parent
                color: "transparent"
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true

                onEntered: {
                    mask.color = "#6A9AB0"
                    mask.opacity = 0.2
                }
                onExited: {
                    mask.color = "transparent"
                    mask.opacity = 1.0
                }

                onClicked: {
                    root.currentScreen = index
                }
            }
        }
    }
}
