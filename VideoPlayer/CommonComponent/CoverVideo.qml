import QtQuick 2.15
import QtQuick.Controls.Fusion 2.12
import QtMultimedia 5.5

Item {
    property bool doubleTap: true
    property string currentVideoTxt: ""
    signal showFullScreen()
    Rectangle{
        id: coverVideo
        width: doubleTap ? parent.width * 0.8 : parent.width
        height: doubleTap ? parent.height * 0.8 : parent.height
        anchors.centerIn: parent
        VideoOutput{
            id: videoOutput
            source: VideoHandler
            anchors.fill: parent
            visible: true
            TapHandler {
                onDoubleTapped: {
                    showFullScreen()
                    doubleTap = !doubleTap
                }
                onTapCountChanged: {
                    VideoHandler.requestPause()
                }
            }
        }
        Text{
            text: currentVideoTxt
            color: "black"
            font.pixelSize: 30
            anchors.centerIn: parent
        }
    }
    Component.onCompleted: {
        VideoHandler.setVideoSink(videoOutput.videoSurface)
    }
}
