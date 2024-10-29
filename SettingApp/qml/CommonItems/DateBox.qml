import QtQuick 2.15

Item {
    id: root
    implicitWidth: 100
    implicitHeight: 40
    property string textShow
    property bool checked: false
    signal clickBox()

    Rectangle{
        id: checkBox
        anchors.left: parent.left
        width: height = 40
        border.color: "#1E2A5E"
        border.width: 2
        color: "transparent"
        Image {
            id: checkFormat
            source: "qrc:/images/checkMark.png"
            visible: checked
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                clickBox();
            }
        }
    }

    Text{
        id: textDes
        text: textShow
        anchors{
            left: checkBox.right
            leftMargin: 20
            verticalCenter: checkBox.verticalCenter
        }
        font{
            bold: checked
            pointSize: 18
        }

    }
}
