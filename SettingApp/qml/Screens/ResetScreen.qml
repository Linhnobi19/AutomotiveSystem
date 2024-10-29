import QtQuick 2.15
import QtQuick.Controls 2.15
import "../CommonItems"

Popup {
    id: messagePop
    width: 500
    height: 200
    modal: true
    padding: 0
    closePolicy: Popup.NoAutoClose

    background: Rectangle{
        anchors.fill: parent
        // color: "#b9d9fa"
        color: "#F5F5F7"
        border.color: "black"
        border.width: 2
    }

    Image{
        id: infoImage
        width: height = 50
        anchors {
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 20
        }
        source: "qrc:/images/infoImage.png"
        fillMode: Image.PreserveAspectFit
        smooth: true
    }

    Text {
        id: confirmText

        anchors{
            top: infoImage.bottom
            topMargin: 20
            horizontalCenter: parent.horizontalCenter
        }

        width: parent.width * 3 / 4

        text: qsTr("STR_Please confirm that all Settings will be reset to default")
        font {
            // bold: true
            pointSize: 14
        }
        wrapMode: Text.WordWrap
    }

    Row{
        width:parent.width
        height: 40
        anchors.bottom: parent.bottom
        MyButton{
            id: yesBubtton
            width: parent.width / 2
            textShow: qsTr("STR_Yes")
            onClickButton: {
                SettingController.reset();
                messagePop.close()
            }
        }
        MyButton{
            id: cancelBubtton
            width: parent.width / 2
            textShow: qsTr("STR_Cancel")
            onClickButton: {
                messagePop.close()
            }
        }
    }
}
