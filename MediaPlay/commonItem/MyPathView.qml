import QtQuick 2.12

PathView
{
    id: pathView

    signal currentSongChanged();

    model: Model

    pathItemCount: 3

    path: Path {
        startX: -50
        startY: 0
        PathQuad
        {
            x: pathView.width ;
            y: 0;
            controlX: pathView.width / 2
            controlY: pathView.height
        }

    }
    preferredHighlightBegin: 0.5
    preferredHighlightEnd: 0.5
    currentIndex:
    {
        //        console.log(Model.currentSong ? Model.songList.indexOf(Model.currentSong) : 0)
        return /*Model.songList.indexOf(Model.currentSong)*/ Model.currentSong.index
    }
    delegate: Rectangle
    {
        width: currentIndex == index ? 200 : 150
        height: currentIndex == index ? 200 : 150

        border.width : 1
        z: currentIndex == index ? 2 : 1
        opacity: currentIndex == index ? 1 : 0.8

        Image {
            id: image

            anchors.fill: parent

            source: "file://" + imagePath
            MouseArea
            {
                anchors.fill: parent
                onClicked:
                {
                    Controller.setSong(index);
                }
            }
        }

    }
    onCurrentIndexChanged:
    {

        Controller.setSong(currentIndex);
    }


}
