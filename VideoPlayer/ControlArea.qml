import QtQuick 2.15
import "./CommonComponent"

Item {
    Rectangle{
        anchors.fill: parent
        color: "transparent"
        ControlVolume{
            anchors.bottom: parent.bottom
            anchors.verticalCenter: controlBtn.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: parent.width * 0.02
        }
        ControlButton{
            id: controlBtn
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
