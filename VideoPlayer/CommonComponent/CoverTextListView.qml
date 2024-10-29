import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height
    property string textBoxList: ""
    property bool isClicked: false
    Rectangle{
        width: parent.width
        height: parent.height
        color: "transparent"
        clip: true
        Text{
            id: scrollingText
            text: textBoxList
            font.pixelSize: 30
            color: "white"
            anchors.verticalCenter: parent.verticalCenter
            elide: Text.ElideNone
            width: parent.width
            x: isClicked ? parent.width : 0
        }
        NumberAnimation {
            target: scrollingText
            property: "x"
            from: parent.width
            to: -scrollingText.width
            duration: 8000
            loops: Animation.Infinite
            running: isClicked ? true : false
        }
    }
}
