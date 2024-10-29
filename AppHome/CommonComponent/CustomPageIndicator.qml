import QtQuick 2.15

Item {
    property color rectPage01: "transparent"
    property color rectPage02: "transparent"
    width: 100
    height: 20

    Rectangle{
        anchors.fill: parent
        color: "transparent"
        Rectangle{
            width: 45
            height: 12
            color: rectPage01
            anchors.left: parent.left
            border.width: 1
        }
        Rectangle{
            width: 45
            height: 12
            color: rectPage02
            anchors.right: parent.right
            border.width: 1
        }
    }
}
