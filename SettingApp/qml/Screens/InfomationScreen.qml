import QtQuick 2.15

Item {
    anchors.fill: parent
    Image{
        id: qrImage
        width: 150
        height: 150
        source: "qrc:/images/qtQr.png"
        anchors {
            left: parent.left
            leftMargin: 30
            top: parent.top
            topMargin: 30
        }
        fillMode: Image.PreserveAspectFit
        smooth: true
    }
    Text {
        id: textDes
        width: 300
        wrapMode: Text.WordWrap
        text: qsTr("STR_Please using your mobile device to check QR code")
        font {
            bold: true
            pointSize: 18
        }
        anchors {
            leftMargin: 30
            left: qrImage.right
            verticalCenter: qrImage.verticalCenter
        }
    }
}
