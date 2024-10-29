import QtQuick 2.15


Rectangle {
    id: root
    radius: 5

    property var myFunc: function(){}
    property string textShow: "Unknow"
    property string sourceImage
    property bool showImage: false

    onSourceImageChanged: {
        if(sourceImage === ""){
            showImage = false
        }
        else {
            showImage = true
        }
    }

    Text{
        text: textShow
        anchors.centerIn: parent
        visible: !showImage
    }
    Image{
        width: parent.width - 5
        height: parent.height - 5
        anchors.centerIn: parent
        fillMode: Image.PreserveAspectFit
        visible: showImage
        source: "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/" + sourceImage
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            parent.color = "#FFE1FF"
        }
        onExited: {
            parent.color = "white"
        }

        onClicked: {
            console.log(parent.width)
            root.myFunc()
        }
    }
}
