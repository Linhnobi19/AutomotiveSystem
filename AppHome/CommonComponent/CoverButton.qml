
import QtQuick 2.15
import CustomImage 1.0
Item {
    property string sourceImage: ""
    property string titleBtn: ""
    property string mediaTitleTxt: ""
    property string mediaAuthorTxt: ""
    signal clickedBtn()

    property bool allowRunningText: false

    onAllowRunningTextChanged: {
        coverOne.isRunning = false;
        coverTwo.isRunning = false;

        if(allowRunningText && !coverOne.isRunning){
            coverOne.trigger();
        }
    }


    Rectangle{
        id: btn
        // width: 320
        // height: 370
        anchors.fill: parent
        Text {
            text: titleBtn
            font.pixelSize: 30
            font.bold: true
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 30
        }
        CustomImage {
            id: image
            source: sourceImage
            width: 350
            height: 350
            radius: 30
            anchors.centerIn: parent
            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onEntered: image.opacity = 0.5
                onExited: image.opacity = 1
                onClicked: clickedBtn()
            }
        }
        MovingText{
            id: coverOne
            width: 250
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: image.bottom
            textShow: mediaTitleTxt

            onNext: {
                if(allowRunningText){
                    coverTwo.trigger();
                }
            }

        }

        MovingText{
            id: coverTwo
            width: 250
            height: 30
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: coverOne.bottom
            textShow: mediaAuthorTxt
            onNext: {
                if(allowRunningText){
                    coverOne.trigger();
                }
            }
        }
    }
}
