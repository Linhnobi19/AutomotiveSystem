import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {

    color: "black"

    property var modelListButton: []
    property string textDirect

    Row{
        id: listButton
        width: modelButton.width
        height: parent.height
        anchors {
            left: parent.left
            leftMargin: 10
        }

        spacing: 10
        Repeater{
            id: modelButton
            width: 60 * modelListButton.length - 5
            model: modelListButton
            delegate: MyButton{
                width: 50
                height: 50
                sourceImage: modelData.image
                anchors.verticalCenter: parent.verticalCenter
                textShow: {
                    if(modelButton.count == 0){
                        return ""
                    }
                    else
                        return modelData.textButton
                }
                myFunc: {
                    modelListButton[index].func
                }
            }
        }

    }

    Text {
        id:  textDirection
        anchors{
            left: listButton.right
            leftMargin: 10
            verticalCenter: parent.verticalCenter
        }
        font {
            bold: true
            pointSize: 13
        }
        color: "white"
        text: textDirect
    }

    Text{
        id: time
        anchors.centerIn: parent
        color: "white"
        font.pointSize: 15
        font.bold: true
        text: DateShow.time === "" ? "" : DateShow.time
    }

    Text{
        id: date
        anchors {
            left: time.right
            leftMargin: 10
            baseline: time.baseline
        }
        color: "white"
        font.pointSize: 12
        text: DateShow.date === "" ? "" : DateShow.date

    }
}
