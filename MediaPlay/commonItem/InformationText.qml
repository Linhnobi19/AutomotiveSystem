import QtQuick 2.12

Rectangle
{
    property string sTitle: "Unknown"
    property string sArtist: "Unknown"
    property string sAlbum: "Unknown"
    color: "transparent"

    ScrollingText {
        id: titleText

        width: 200// parent.width  / 2.5
        height: parent.height / 3

        isRunning: true

        onAnimationFinished :
        {
            artistText.isRunning = true;
            isRunning = false;
        }

        sText: sTitle
        fontWeight: Font.DemiBold
        // sColor:  "white"

    }
    ScrollingText
    {
        id: artistText

        width: parent.width / 2
        height: parent.height / 3

        anchors.top: titleText.bottom

        onAnimationFinished:
        {
            albumText.isRunning = true;
            artistText.isRunning = false;
        }

        sText: sArtist
        // sColor:  "white"
    }

    ScrollingText
    {
        id: albumText
        width: parent.width / 2
        height: parent.height / 3

        anchors.top: artistText.bottom
        onAnimationFinished:
        {
            titleText.isRunning = true;
            albumText.isRunning = false;
        }

        sText: sAlbum
        fontItalic: true
        // sColor:  "white"
    }
}
