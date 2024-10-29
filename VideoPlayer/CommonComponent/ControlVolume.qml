import QtQuick 2.15
import QtQuick.Controls 2.12

Item {
    width: 200
    height: 50
    Rectangle{
        id: volumeDownBtn
        anchors.fill: parent
        color: "transparent"
        Rectangle{
            width: 40
            height: 40
            radius: 40
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
            Image{
                width: 40
                height: 40
                source: "qrc:/SourceImage/volumeDownBtn.png"
            }
        }
    }

    Slider
    {
        id: volumeControlSLider
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: volumeDownBtn.verticalCenter
        width: 110
        from: 0
        value: VideoHandler.volume
        to: 12
        stepSize: 1.0
        onValueChanged:
        {
            VideoHandler.volume  = value
        }
    }

    Rectangle{
        id: volumeUpBtn
        anchors.fill: parent
        color: "transparent"
        Rectangle{
            width: 40
            height: 40
            radius: 40
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            Image{
                width: 40
                height: 40
                source: "qrc:/SourceImage/volumeUpBtn.png"
            }
        }
    }
}
