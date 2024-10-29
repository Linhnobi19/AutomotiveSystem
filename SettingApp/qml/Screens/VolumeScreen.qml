import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: volumeItem

    Rectangle{
        id: subVolume
        width: height = 40
        radius: 20
        color: "#7695FF"
        anchors{
            left: parent.left
            leftMargin: 25
            verticalCenter: sliderVolume.verticalCenter
        }
        Text{
            text: "-"
            font.bold: true
            font.pointSize: 12
            color: "white"
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                subVolume.scale = 1.2
            }
            onExited: {
                subVolume.scale = 1.0
            }

            onClicked: {
                sliderVolume.value -= 1
            }
        }
    }
    Slider{
        id: sliderVolume
        width: parent.width * 7 / 10
        height: 20
        from: 0
        to: 12
        anchors {
            top: parent.top
            topMargin: 150
            horizontalCenter: parent.horizontalCenter
        }
        value: VolumeController.currentVolume
        onValueChanged: {
            VolumeController.currentVolume = value
        }
        // property bool maskVisible: false

        stepSize: 1
        background: Rectangle{
            width: sliderVolume.availableWidth
            height: sliderVolume.height
            color: "transparent"
            // border.color: "#00CCDD"
            radius: 20
            x: sliderVolume.leftPadding
            Rectangle{
                id: mask
                anchors.fill: parent
                color: "#7695FF"
                opacity: 0.3
                radius: parent.radius
            }

            Rectangle{
                id: visualSlider
                width: parent.width * sliderVolume.visualPosition
                height: parent.height
                radius: parent.radius
                color: "#7695FF"
            }
        }

        handle: Item{
            width: 30
            height: 30
            x: parent.leftPadding - width / 2
               + parent.visualPosition * parent.availableWidth
            anchors.verticalCenter: parent.verticalCenter

            // Rectangle{
            //     id: maskGlow
            //     // anchors.fill: parent
            //     width: 80
            //     height: 80
            //     anchors.centerIn: parent
            //     radius: 40
            //     color: "#9DBDFF"
            //     opacity: 0.2
            //     visible: sliderVolume.maskVisible
            // }
            Rectangle{
                id: button
                anchors.fill: parent
                // anchors.centerIn: parent
                radius: 15
                color: "#1E2A5E"

                Text{
                    text: sliderVolume.value
                    font.pointSize: 9
                    anchors.centerIn: parent
                    color: "white"
                    font.bold: true
                }
            }
            // MouseArea{
            //     id: handleMouseArea
            //     anchors.fill: parent
            //     propagateComposedEvents: true

            //     hoverEnabled: true

            //     onEntered:
            //     {
            //         maskGlow.visible = true
            //         console.log("pressed")
            //     }
            //     onExited: {
            //         maskGlow.visible = false
            //         console.log("released")
            //     }
            // }
        }

    }

    Rectangle{
        id: increseVolume
        width: height = 40
        radius: 20
        color: "#7695FF"
        anchors{
            right: parent.right
            rightMargin: 25
            verticalCenter: sliderVolume.verticalCenter
        }
        Text{
            text: "+"
            font.bold: true
            color: "white"
            font.pointSize: 12
            anchors.centerIn: parent
        }

        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {
                increseVolume.scale = 1.2
            }
            onExited: {
                increseVolume.scale = 1.0
            }
            onClicked: {
                sliderVolume.value += 1
            }
        }
    }
}
