import QtQuick 2.12

Item {

    property string sText: "Unknown"
    property string sColor: "black"
    property bool isRunning: false
    property int fontWeight: Font.Normal
    property bool fontItalic: false
    signal animationFinished()
    clip: true
    Item
    {
        anchors.fill: parent
        anchors.left: parent.left
        anchors.leftMargin: 15

        Text {
            id: myText
            anchors.verticalCenter: parent.verticalCenter
            width: isRunning ? implicitWidth/*paintedWidth*/ : parent.width
            elide: isRunning ? Text.ElideNone : Text.ElideRight

            text: sText
            color: sColor

            font.pixelSize: 20
            font.weight: fontWeight
            font.italic: fontItalic
            font.bold: true

            PropertyAnimation on x
            {
                id: myAnimation
                running: false

                from: parent.width/2
                duration: 8000
                onFinished:
                {
                    myText.x = 0;
                    animationFinished();
                }
            }
        }

        Timer
        {
            interval: 100
            repeat: false
            running:
            {
                if(isRunning == false)
                {

                    myAnimation.stop();
                    myText.x = 0;
                }
                return isRunning
            }
            onTriggered:
            {
                if(parent.width <= myText.width)
                {
                    myAnimation.to = -myText.width/2
                    myAnimation.restart();
                }
                else animationFinished();
            }
        }
    }

}
