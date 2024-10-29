import QtQuick 2.15

Item {
    width: 300
    height: 60
    property bool checkPause: false
    property int videoIndexQML: 0
    Row{
        anchors.fill: parent
        spacing: 50
        Rectangle{
            id: backBtn
            width: 50
            height: 50
            color: "white"
            radius: 50
            anchors.verticalCenter: playBtn.verticalCenter
            Image {
                source: "qrc:/SourceImage/backButton.png"
                anchors.fill: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed: backBtn.opacity  = 0.3
                onReleased: backBtn.opacity = 1
                onClicked: {
                    if(VideoHandler.checkHaveVideoIsPlaying){
                        videoIndexQML = VideoHandler.videoIndex
                        if(videoIndexQML > 0)
                        {
                            videoIndexQML --
                            VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(videoIndexQML)
                            VideoHandler.videoIndex = videoIndexQML
                        }
                        else
                        {   VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(0)
                            VideoHandler.videoIndex = 0
                        }
                        DbusHandler.pauseAll();
                    }
                }
            }
        }

        Rectangle{
            id: playBtn
            width: 60
            height: 60
            color: "white"
            radius: 60
            Image {
                source: !VideoHandler.checkPause ? "qrc:/SourceImage/pauseButton.png" : "qrc:/SourceImage/playButton.png"
                anchors.fill: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed: playBtn.opacity  = 0.3
                onReleased: playBtn.opacity = 1
                onClicked:
                {
                    if(VideoHandler.checkHaveVideoIsPlaying){
                        VideoHandler.requestPause()
                        DbusHandler.pauseAll();
                    }
                }
            }
        }

        Rectangle{
            id: nextBtn
            width: 50
            height: 50
            color: "white"
            radius: 50
            anchors.verticalCenter: playBtn.verticalCenter
            Image {
                source: "qrc:/SourceImage/nextButton.png"
                anchors.fill: parent
            }
            MouseArea{
                anchors.fill: parent
                onPressed: nextBtn.opacity  = 0.3
                onReleased: nextBtn.opacity = 1
                onClicked: {
                    if(VideoHandler.checkHaveVideoIsPlaying)
                    {
                        videoIndexQML = VideoHandler.videoIndex
                        if(videoIndexQML < VideoHandler.sizeList - 1)
                        {
                            videoIndexQML ++
                            VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(videoIndexQML)
                            VideoHandler.videoIndex = videoIndexQML
                        }
                        else
                        {
                            VideoHandler.checkNextVideo = true
                            VideoHandler.chooseVideo(0)
                            VideoHandler.videoIndex = 0
                        }
                        DbusHandler.pauseAll();
                    }
                }
            }
        }
    }
}
