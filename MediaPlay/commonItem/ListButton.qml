import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    function play()
    {
        // Controller.theFirstPlay()
        Controller.play();
    }
    function next()
    {
        Controller.next()
    }
    function prev()
    {
        Controller.prev()
    }
    function back()
    {
        Controller.back()
    }
    function skip()
    {
        Controller.skip()
    }
    function repeat()
    {
        Controller.repeat()
    }
    function shuffle()
    {
        Controller.shuffle()
    }


    Row
    {
        width: parent.width
        height: parent.height
        spacing: 15

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1


            bPath:
                {
                if(Controller.isShuffle)
                {
                    return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/shuffle1.png";
                }
                else return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/shuffle.png";
            }
            bFunc: shuffle
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath: "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/back.png"
            bFunc:  prev
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath: "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/prev10s.png"
            bFunc:  back
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath:
            {
                if(Controller.isPause)
                {
                    return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/play.png";
                }
                else return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/pause.png";
            }
            bFunc:  play
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath: "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/skip10s.png"
            bFunc:  skip
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath: "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/next.png"
            bFunc:  next
        }

        MyButton
        {
            width: parent.width / 8
            height: parent.height
            // border.width: 1

            bPath:
            {
                if(Controller.isRepeat)
                {
                    return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/loop1.png"
                }
                else return "../build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Resource/imageButton/loop.png"
            }

            bFunc: repeat

        }



    }
}
