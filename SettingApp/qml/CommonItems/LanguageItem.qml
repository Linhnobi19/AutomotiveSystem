import QtQuick 2.15

Rectangle {
    id: root
    width: 200
    height: 60
    color: "Transparent"
    property string sourceImage
    property string textLanguage
    property var group: null
    property bool checked: false
    signal clicked();

    Row{
        height: parent.height
        width: parent.width
        spacing: 30
        Rectangle{
            id: outSide
            color: "transparent"
            width: 30
            height: 30
            radius: width / 2
            border.color: "black"
            anchors.verticalCenter: parent.verticalCenter
            Rectangle{
                width: 24
                height: 24
                radius: width/2
                anchors.centerIn: parent
                color: "#7695FF"
                visible: root.checked
                // border.color: "black"
            }

            Rectangle{
                id: mask
                width: height = 60
                radius: width / 2
                color: "#7695FF"
                opacity: 0.1
                anchors.centerIn: parent
                visible: false
            }

            MouseArea{
                anchors.fill: parent
                onPressed: {
                    mask.visible = true
                }

                onReleased: {
                    mask.visible = false
                }

                onClicked: {
                    if(!root.checked){
                        // checked = true
                        // if (group) {
                        //     group.selectButton(root)
                        // }
                        root.clicked()
                    }
                }
            }
        }

        Rectangle{
            width: parent.width - outSide.width
            height: parent.height
            color: "transparent"
            Image {
                id: flagItem
                width: 60
                height: 40
                source: root.sourceImage
                fillMode: Image.PreserveAspectFit
                anchors.verticalCenter: parent.verticalCenter
            }

            Text{
                text: root.textLanguage
                anchors{
                    verticalCenter: parent.verticalCenter
                }
                font.pointSize: 14
                anchors.left: flagItem.right
                anchors.leftMargin: 10
                font.bold: true
            }
        }


    }

    Component.onCompleted: {
        if(root.checked && root.group){
            group.selectButton(root)
        }
    }

}
