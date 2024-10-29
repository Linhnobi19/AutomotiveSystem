import QtQuick 2.15

Rectangle {
    width: 80
    height: 40
    border.color: "black"
    color: "#7695FF"

    property string textShow
    signal clickButton();

    Text {
        id: textButton
        text: textShow
        anchors.centerIn: parent
        font {
            bold: true
            pointSize: 14
        }
        color: "white"
    }

    MouseArea{
        anchors.fill: parent
        hoverEnabled: true

        onEntered: {
            parent.color = "#b6c6fa"
        }

        onExited: {
            parent.color = "#7695FF"
        }

        onClicked: {
            clickButton();
        }
    }
}
