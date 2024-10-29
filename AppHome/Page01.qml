import QtQuick 2.15
import "./CommonComponent"
Item {
    Row{
        CoverButton{
            id: musicButton
            width: 540
            height: 500
            // sourceImage: "qrc:/SourceImage/musicBtn.png"
            sourceImage: AppHome.sourceImage
            titleBtn: qsTr("Music")
            mediaTitleTxt: AppHome.musicTitle
            mediaAuthorTxt: AppHome.musicAuthor


        }
        CoverButton{
            id: videoButton
            width: 540
            height: 500
            sourceImage: "qrc:/SourceImage/videoBtn.png"
            titleBtn: qsTr("Video")
            mediaTitleTxt: AppHome.videoTitle


        }
    }

    Connections{
        target: AppHome
        function onAppRunChanged(){
            // console.log("come here");
            if(AppHome.appRun == 0){
                musicButton.allowRunningText = false;
                musicButton.allowRunningText = true;
                videoButton.allowRunningText = false;
            }
            else if(AppHome.appRun == 1){
                videoButton.allowRunningText = false;
                videoButton.allowRunningText = true;
                musicButton.allowRunningText = false;
            }
        }
    }

    Connections{
        target: musicButton
        function onClickedBtn(){
            AppHome.openApp(0)
        }
    }

    Connections{
        target: videoButton
        function onClickedBtn(){
            AppHome.openApp(1)
        }
    }
}
