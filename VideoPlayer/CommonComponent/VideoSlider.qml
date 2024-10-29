import QtQuick 2.15
import QtQuick.Controls 2.15

Item {

    function getVideoPos()
    {
        var secondNow = Math.floor(VideoHandler.videoPos);
        var minuteNow = Math.floor(secondNow / 60);
        secondNow = secondNow % 60;
        var formattedSecond = secondNow < 10 ? "0" + secondNow : secondNow;
        return minuteNow + ":" + formattedSecond;
    }

    function getVideoDuaration()
    {
        var secondTotal = Math.floor(VideoHandler.videoDuaration);
        var minuteTotal = Math.floor(secondTotal / 60);
        secondTotal = secondTotal % 60;
        var formattedSecond = secondTotal < 10 ? "0" + secondTotal : secondTotal;
        return minuteTotal + ":" + formattedSecond;
    }

    Rectangle{
        anchors.fill: parent
        color: "transparent"

        Text {
            id: currentPos
            text: getVideoPos()
            font.pixelSize: 20
            anchors.right: videoControlPosition.left
            anchors.rightMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            color: "black"
        }

        Slider
        {
            id: videoControlPosition
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            width: parent.width * 0.75
            from: 0
            to: VideoHandler.videoDuaration
            value: VideoHandler.videoPos

            onMoved: {
                VideoHandler.myChangedPosition(value)
            }

            onValueChanged: {
                console.log(value   )
            }
        }

        Text {
            id: totalPos
            text: getVideoDuaration()
            font.pixelSize: 20
            anchors.left: videoControlPosition.right
            anchors.leftMargin: 30
            anchors.verticalCenter: parent.verticalCenter
            color: "black"
        }
    }
}
