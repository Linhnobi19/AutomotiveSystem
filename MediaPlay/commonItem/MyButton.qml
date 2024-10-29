import QtQuick 2.12

Rectangle
{
    property var bFunc: function() {}
    property string bPath: ""
    color: "transparent"
    radius: 90

    Image {
        // anchors.fill: parent
        width: parent.width * 0.8
        height: parent.height * 0.8
        anchors.centerIn: parent
        source: bPath
        fillMode: Image.PreserveAspectFit


    }
    MouseArea
    {
        anchors.fill: parent
        hoverEnabled: true
        onEntered:
        {
            // parent.color = "#E1D7C6"
            parent.opacity = 0.5
        }

        onExited:
        {
            // parent.color = "white"
            parent.opacity = 1.0
        }

        onPressed:
        {
            parent.scale = 1.1
        }

        onReleased:
        {
            parent.scale = 1;
            parent.bFunc();
        }


    }
}
