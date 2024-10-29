import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import Qt.labs.platform 1.1
import Fpt.StatusBar 1.0
import "./CommonComponent"

Window {
    id: root
    width: 1080
    height: 608
    visible: VideoHandler.checkShowApp ? true : false // add ! to test
    title: qsTr("Video App")
    property bool checkShowList: false
    property bool checkShowFullScreen: false
    Item{
        anchors.fill: parent
        CustomStatusBar{
            id: statusBar
            width: parent.width
            height: 60
            textDirect : checkShowList ? qsTr("Video > List") : qsTr("Video > Play")
            modelListButton : !checkShowList ? [
                                                   {
                                                       "textButton" : "Back",
                                                       "image" : "left.png",
                                                       "func" : function(){
                                                       }
                                                   },
                                                   {
                                                       "textButton" : "Home",
                                                       "image" : "home.png",
                                                       "func" : function() {
                                                           DbusHandler.returnHome();
                                                       }
                                                   },
                                                   {
                                                       "textButton" : "Zoom",
                                                       "image" : "zoom.png",
                                                       "func" : function() {
                                                           if(!checkShowFullScreen){
                                                               root.showFullScreen()
                                                           }
                                                           else
                                                           {
                                                               root.showNormal()
                                                           }
                                                           checkShowFullScreen =! checkShowFullScreen
                                                       }
                                                   },
                                                   {
                                                       "textButton" : "List",
                                                       "image" : "list.png",
                                                       "func" : function() {
                                                           checkShowList =! checkShowList
                                                       }
                                                   },

                                                   {
                                                       "textButton" : "Folder",
                                                       "image" : "folder.png",
                                                       "func" : function() {
                                                           folderDialog.open()
                                                       }
                                                   }
                                               ] :  [
                                                   {
                                                       "textButton" : "Back",
                                                       "image" : "left.png",
                                                       "func" : function(){
                                                           checkShowList =! checkShowList
                                                       }
                                                   },
                                                   {
                                                       "textButton" : "Home",
                                                       "image" : "home.png",
                                                       "func" : function() {
                                                           DbusHandler.returnHome();
                                                       }
                                                   },
                                                   {
                                                       "textButton" : "Zoom",
                                                       "image" : "zoom.png",
                                                       "func" : function() {
                                                           if(!checkShowFullScreen){
                                                               root.showFullScreen()
                                                           }
                                                           else
                                                           {
                                                               root.showNormal()
                                                           }
                                                           checkShowFullScreen =! checkShowFullScreen
                                                       }
                                                   },

                                                   {
                                                       "textButton" : "Folder",
                                                       "image" : "folder.png",
                                                       "func" : function() {
                                                           folderDialog.open()
                                                       }
                                                   }
                                               ]
        }

        CoverVideo{
            id: coverVideo
            width: parent.width
            height: parent.height
            currentVideoTxt: !VideoHandler.checkHaveVideoIsPlaying ? qsTr("Open folder to load video") : ""
        }
        ControlArea{
            id: controlArea
            width: parent.width
            height: 80
            visible: !checkShowList
            anchors.bottom: parent.bottom
        }
        VideoSlider{
            id: videoSlider
            width: parent.width
            height: 40
            visible: !checkShowList
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: controlArea.top
        }
        ListViewVideo{
            id: listVideo
            width: parent.width
            height: parent.height - statusBar.height
            visible: checkShowList ? true : false
            anchors.top: statusBar.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
        FolderDialog {
            id: folderDialog
            onAccepted: {
                console.log("Selected Folder: " + folderDialog.folder)
                VideoHandler.loadFolderPath(folderDialog.folder)
                coverVideo.currentVideoTxt = qsTr("Open list to choose video")
            }
            onRejected: {
                console.log("Folder video not choosen")
            }
        }
    }
    Connections{
        target: listVideo
        function onLoadSuccessVideo(){
            checkShowList =! checkShowList
            VideoHandler.checkHaveVideoIsPlaying = true
            coverVideo.currentVideoTxt = qsTr("")
        }
    }

    Connections{
        target: coverVideo
        function onShowFullScreen(){
            if(!checkShowFullScreen){
                root.showFullScreen()
            }
            else
            {
                root.showNormal()
            }
            checkShowFullScreen =! checkShowFullScreen
        }
    }
}
