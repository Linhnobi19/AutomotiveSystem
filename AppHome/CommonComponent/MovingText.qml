import QtQuick 2.15

Rectangle {
    id: container
    color: "transparent"
    clip: true
    property bool isRunning: false
    property string textShow

    signal complete();
    signal next();
    signal trigger();

    onTrigger: {
        isRunning = true;
        timer.restart();
    }

    onIsRunningChanged: {
        if(!isRunning){
            if(scrollAnimation.running){
                scrollAnimation.stop();
            }

            // scrollAnimation.complete()
            scrollingText.x = 0;
            scrollingText.elide = Text.ElideRight  // Hiển thị lại dấu "..."
            scrollingText.horizontalAlignment = Text.AlignHCenter
        }
        else{
            scrollingText.elide = Text.ElideNone
        }
    }

    onTextShowChanged: {
        if(parent.width > scrollingText.implicitWidth){
            // isRunning = false
            scrollAnimation.stop()
        }
        else if(parent.width > scrollingText.implicitWidth && !isRunning) {
            trigger();
        }
    }

    Text {
        id: scrollingText
        text: textShow
        font.pixelSize: 25
        // width: parent.width
        elide: Text.ElideRight
        horizontalAlignment: Text.AlignHCenter
        // anchors.horizontalCenter: isRunning ? null : container.horizontalCenter
        // width: isRunning ? implicitWidth : parent.width
        width: {
            if(implicitWidth <= parent.width){
                return parent.width;
            }
            else {
                return isRunning ? implicitWidth : parent.width
            }
        }

        NumberAnimation {
            id: scrollAnimation
            target: scrollingText
            property: "x"
            from: parent.width / 3
            duration: scrollingText.implicitWidth * 40
            running: false

            onStopped: {
                // console.log("come to finished")
                scrollingText.x = 0;
                scrollingText.horizontalAlignment = Text.AlignHCenter
                scrollingText.elide = Text.ElideRight  // Hiển thị lại dấu "..."
                isRunning = false;
                next();
            }
        }

    }

    Timer{
        id: timer
        repeat: false
        interval: 50
        running: {
            if(!isRunning){
                if(scrollAnimation.running){
                    scrollAnimation.pause();
                }
                scrollingText.x = 0;
                scrollingText.elide = Text.ElideRight  // Hiển thị lại dấu "..."
            }
            return false;
        }

        onTriggered: {
            if(scrollingText.implicitWidth > container.width){
                scrollAnimation.to = -scrollingText.implicitWidth
                // console.log("Mouse entered")
                scrollingText.elide = Text.ElideNone  // Loại bỏ dấu "..." khi hover
                scrollAnimation.restart()  // Bắt đầu cuộn nếu văn bản dài hơn vùng chứa
            }
            else {
                scrollingText.horizontalAlignment = Text.AlignHCenter
                next()
            }
        }
    }
}
