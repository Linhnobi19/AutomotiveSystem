import QtQuick 2.12
import QtQuick.Controls 2.12
import "commonItem"


Rectangle
{
    width: parent.width
    height: parent.height

    ListView
    {
        id: songListLV


        width: parent.width
        height: parent.height

        clip: true
        model: Model
        headerPositioning: ListView.OverlayHeader
        // currentIndex: Model.currentSong.index

        header: Rectangle
        {
            width: songListLV.width
            height: songListLV.height / 6
            z: 2

            Row
            {
                width: parent.width
                height: parent.height
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    Text {
                        id: title

                        anchors.centerIn: parent

                        text: qsTr("FileName")
                        font.pixelSize: 25

                    }
                }
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    Text {
                        id: path

                        anchors.centerIn: parent

                        text: qsTr("Title")
                        font.pixelSize: 25

                    }
                }
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    Text {
                        id: artist

                        anchors.centerIn: parent

                        text: qsTr("Artist")
                        font.pixelSize: 25
                    }
                }
            }
        }

        delegate:Rectangle
        {
            width: songListLV.width
            height: songListLV.height / 6

            Row
            {
                width: parent.width
                height: parent.height
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    ScrollingText
                    {
                        id: _filename

                        width: parent.width
                        height: parent.height

                        isRunning: index === Model.currentSong.index

                        onAnimationFinished :
                        {
                            _title.isRunning = true;
                            _filename.isRunning = false;
                        }

                        fontWeight: Font.Normal
                        sColor: index === Model.currentSong.index? "red" : "black"
                        sText: fileName


                    }
                }
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    ScrollingText {
                        id: _title

                        width: parent.width - 10
                        height: parent.height


                        onAnimationFinished :
                        {
                            _artist.isRunning = true;
                            _title.isRunning = false;
                        }

                        fontWeight: Font.Normal
                        sColor: index === Model.currentSong.index? "red" : "black"
                        sText: title


                    }
                }
                Rectangle
                {
                    width: parent.width / 3
                    height: parent.height

                    border.width: 1
                    ScrollingText
                    {
                        id: _artist
                        width: parent.width - 10
                        height: parent.height

                        onAnimationFinished :
                        {
                            _filename.isRunning = true;
                            _artist.isRunning = false;
                        }


                        fontWeight: Font.Normal
                        sColor: index === Model.currentSong.index? "red" : "black"
                        sText: artist


                    }
                }
            }
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    Controller.setSong(index)
                }

            }
        }
    }
}

