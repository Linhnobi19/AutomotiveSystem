import QtQuick 2.12
import QtQuick.Controls 2.12

Item {

    Text {
        id: _position

        anchors.right: slider.left
        anchors.rightMargin: 12
        anchors.verticalCenter: slider.verticalCenter

        text:
        {
            var position = Controller.position;
            var minute = Math.floor(position / 60);
            var second = position - 60 * minute;
            minute = minute.toString();
            second = (second < 10 ? "0" : "") + second.toString();

            return minute + ":" + second;
        }

        font.pixelSize: 18
    }

    Slider
    {
        id: slider
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 0.8
        height: parent.height

        from: 0
        value: Controller.position
        to: Model.currentSong.duration


        onPressedChanged:
        {
            // console.log("Slider value:", value);
            if(!pressed) Controller.setPos(value);
        }
    }



    Text {
        id: total

        anchors.left: slider.right
        anchors.leftMargin: 12
        anchors.verticalCenter: slider.verticalCenter

        text: {
            var duration = Model.currentSong.duration;
            var minute = Math.floor(duration / 60);
            var second = duration - 60 * minute;
            minute = minute.toString();
            second = (second < 10 ? "0" : "") + second.toString();

            return minute + ":" + second;
        }
        font.pixelSize: 18

    }
}
