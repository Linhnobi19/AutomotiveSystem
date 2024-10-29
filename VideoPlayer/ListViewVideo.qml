import QtQuick 2.15
import "./CommonComponent"

Item {
    signal loadSuccessVideo()
    Rectangle{
        id: listVideo
        width: parent.width
        height: parent.height
        color: "transparent"
        visible: true
        ListView{
            id: myListViewVideo
            width: parent.width
            height: parent.height
            model: VideoModel
            clip: true
            currentIndex: -1
            delegate: Row{
                width: parent.width
                height: 80
                Rectangle{
                    id: coverFileName
                    width: parent.width * 0.5
                    height: parent.height
                    border.width: 1
                    border.color: "white"
                    color: VideoHandler.videoIndex === index && VideoHandler.checkHaveVideoIsPlaying ? "#ff2147" : "#4da0dc"
                    CoverIconVideoPlaying{
                        id: coverIconVideoPlaying
                        width: 80
                        height: 80
                        anchors.left: parent.left
                        anchors.leftMargin: 60
                        visible: VideoHandler.videoIndex === index && VideoHandler.checkHaveVideoIsPlaying ? true : false
                    }
                    Loader {
                        id: coverTextLoader
                        width: parent.width - 60 - coverIconVideoPlaying.width
                        height: 50
                        anchors.left: coverIconVideoPlaying.right
                        anchors.leftMargin: 0
                        anchors.verticalCenter: parent.verticalCenter
                        sourceComponent: VideoHandler.videoIndex === index ? coverTextComponent : null
                    }
                    Component {
                        id: coverTextComponent
                        CoverTextListView {
                            textBoxList: model.fileName
                            isClicked: true
                        }
                    }
                    Text {
                        text: model.fileName
                        visible: VideoHandler.videoIndex !== index
                        color: "white"
                        font.pixelSize: 30
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 50
                        elide: Text.ElideRight
                        width: parent.width - 80
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            DbusHandler.pauseAll();
                            loadSuccessVideo()
                            VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(index)
                            VideoHandler.videoIndex = index
                        }
                    }
                }
                Rectangle{
                    id: coverFilePath
                    width: parent.width * 0.5
                    height: parent.height
                    border.width: 1
                    border.color: "white"
                    color: VideoHandler.videoIndex === index && VideoHandler.checkHaveVideoIsPlaying ? "#ff2147" : "#4da0dc"
                    Loader {
                        width: parent.width - 50
                        height: 50
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 50
                        sourceComponent: VideoHandler.videoIndex === index ? coverTextFilePath : null
                    }
                    Component {
                        id: coverTextFilePath
                        CoverTextListView {
                            textBoxList: model.filePath
                            isClicked: true
                        }
                    }
                    Text {
                        text: model.filePath
                        visible: VideoHandler.videoIndex !== index
                        color: "white"
                        font.pixelSize: 30
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 50
                        elide: Text.ElideRight
                        width: parent.width - 80
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            DbusHandler.pauseAll();
                            loadSuccessVideo()
                            VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(index)
                            VideoHandler.videoIndex = index
                        }
                    }
                }
            }
        }
    }
}
