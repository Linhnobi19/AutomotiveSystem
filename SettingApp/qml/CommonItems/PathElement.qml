import QtQuick 2.15

Rectangle{
    id: pathTimer
    width: 50
    height: parent.height * 4 / 5
    color: "transparent"

    property bool canFlick: true
    property alias modelDate: pathEle.model
    property alias currentIndex: pathEle.currentIndex
    signal changeData();

    clip: true
    PathView{
        id: pathEle
        anchors.fill: parent
        model: 24
        preferredHighlightBegin: 0.5
        preferredHighlightEnd: 0.5
        pathItemCount: 5
        maximumFlickVelocity: 200
        interactive: canFlick

        property int heightDelegate: 50

        onMovementEnded: {
            console.log("The path view flick end at index %1".arg(currentIndex))
            changeData();
        }

        delegate: Rectangle{
            width: parent.width
            height: parent.heightDelegate
            scale: PathView.iconScale
            color: "transparent"
            border {
                color: {
                    if(pathEle.currentIndex !== index){
                           return "transparent"
                    }
                    else if (!canFlick){
                        return "gray"
                    }
                    else return "#7695FF"
                }
            }
            radius: 10

            Text {
                id: textHour
                text: modelData
                anchors.centerIn: parent
                font {
                    pointSize: 12
                    bold: pathEle.currentIndex === index && canFlick
                }
                color: {
                    if(canFlick){
                        return "black"
                    }
                    else {
                        return "gray"
                    }
                }
            }
        }

        path: Path{
            startX: pathEle.width / 2; startY: 0
            PathAttribute{ name: "iconScale"; value: 0.7}

            PathLine{
                x: pathEle.width / 2; y: pathEle.height / 4
            }
            PathAttribute{ name: "iconScale"; value: 0.7}

            PathLine{
                x: pathEle.width / 2; y: pathEle.height / 2
            }
            PathAttribute{
                name: "iconScale"; value: 1.0
            }
            PathLine{
                x: pathEle.width / 2; y: pathEle.height * 3 / 4
            }
            PathAttribute{ name: "iconScale"; value: 0.7}
            PathLine{
                x: pathEle.width / 2; y: pathEle.height
            }
            PathAttribute{ name: "iconScale"; value: 0.7}

        }
    }
}
