import QtQuick 2.0
import "commonItem"
Item {
    width: parent.width
    height: parent.height


    InformationText
    {
        id: songInformation
        width: parent.width
        height: parent.height / 3

        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20


        sTitle:Model.currentSong.title
        sArtist: Model.currentSong.artist
        sAlbum: Model.currentSong.album


    }


    Rectangle{
        width: parent.width * 0.8
        height: parent.height / 4
        color: "#a4afa4"
        radius: 20

        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        ListButton
        {
            // anchors.bottom: _slider.top
            // anchors.bottomMargin: 10
            // anchors.left: parent.left
            // anchors.leftMargin: 50
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter

            width: parent.width // 3 * 2
            height: parent.height / 2


        }

        MySlider
        {
            id: _slider
            width: parent.width
            height: parent.height / 2

            anchors.bottom: parent.bottom
            // anchors.bottomMargin: 5
        }
    }




    MyPathView
    {
        width: parent.width / 2
        height: parent.height / 3

        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 50
    }
}
