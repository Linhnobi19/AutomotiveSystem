import QtQuick 2.15
import "../CommonItems"

Item {
    id: root
    property string colorMask: "#e7e7e7"
    Column{
        id: formatChoosing
        anchors{
            left: parent.left
            leftMargin: 20
            top: parent.top
            topMargin: 30
        }
        width: parent.width
        height: 110
        spacing: 30
        DateBox{
            id: formatHours
            textShow: qsTr("STR_Display 24h format")
            checked: DateModel.isFormat24h
            onClickBox: {
                console.log("click to format button")
                DateModel.isFormat24h = !DateModel.isFormat24h
            }

        }
        DateBox{
            id: formatCustomTime
            textShow: qsTr("STR_Customize time")
            checked: DateModel.isCustomize
            onClickBox: {
                DateModel.isCustomize = !DateModel.isCustomize
                console.log("click to customize time")
            }
        }
    }

    Rectangle{
        id: borderChangingTime
        anchors {
            top: formatChoosing.bottom
            topMargin: 40
            horizontalCenter: parent.horizontalCenter
        }
        width: parent.width * 4 / 5
        height: (parent.height - formatChoosing.height) * 2 / 3
        color: "transparent"
        border.color: "black"
        border.width: 3
        radius: 5

        Rectangle{
            width: textShow.contentWidth + 20
            height: textShow.contentHeight + 10
            color: colorMask
            anchors{
                verticalCenter: parent.top
                left: parent.left
                leftMargin: 3
            }
            Text{
                id: textShow
                anchors.centerIn: parent
                text: qsTr("STR_Customize")
                font {
                    bold: true
                    pointSize: 18
                }
            }
        }

        Row{
            width: 430
            spacing: 20
            height: parent.height * 4 / 5
            anchors.centerIn: parent
            PathElement{
                id: pathHour
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentHour
                modelDate: DateModel.hours
                onChangeData: {
                    DateController.currentHour = currentIndex
                }
            }
            PathElement{
                id: pathMin
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentMinute
                modelDate: DateModel.minutes
                onChangeData: {
                    DateController.currentMinute = currentIndex
                }
            }
            PathElement{
                id: pathSecond
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentSecond
                modelDate: DateModel.seconds
                onChangeData: {
                    DateController.currentSecond = currentIndex
                }
            }
            PathElement{
                id: pathDay
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentDay
                modelDate: DateModel.days
                onChangeData: {
                    DateController.currentDay = currentIndex
                }
            }
            PathElement{
                id: pathMonth
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentMonth
                modelDate: DateModel.months
                onChangeData: {
                    DateController.currentMonth = currentIndex
                }
            }
            PathElement{
                id: pathYear
                width: 80
                canFlick: DateModel.isCustomize
                currentIndex: DateController.currentYear
                modelDate: DateModel.years
                onChangeData: {
                    DateController.currentYear = currentIndex
                }
            }
        }
        Rectangle{
            id: hourType
            width: 50
            height: 50
            visible: {
                if(!DateModel.isFormat24h && DateModel.isCustomize)
                    return true;
                else
                    return false;
            }
            color: "lightgray"
            border.color: "black"
            radius: 10
            anchors {
                horizontalCenter: parent.horizontalCenter
                bottom: parent.bottom
                bottomMargin: 30
            }

            property bool isPM: DateController.isPM


            Text{
                text: parent.isPM ? qsTr("PM") : qsTr("AM")
                anchors.centerIn: parent
                font.bold: true
                font.pointSize: 14
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {
                    parent.color = "#6A9AB0"
                }

                onExited: {
                    parent.color = "lightgray"
                }

                onClicked: {
                    parent.isPM = !parent.isPM
                }
            }
        }

        MyButton{
            id: buttonClick
            textShow: qsTr("Save")
            anchors {
                horizontalCenter: borderChangingTime.horizontalCenter
                top: borderChangingTime.bottom
                topMargin: 20
            }
            visible: DateModel.isCustomize

            onClickButton: {
                DateController.isPM = hourType.isPM
                DateController.storingCustomTime();
            }
        }
    }
}
