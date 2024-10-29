import QtQuick 2.15
import "./CommonComponent"
Item {
    CoverButton{
        id: settingBtn
        width: 540
        height: 500
        sourceImage: "qrc:/SourceImage/setttingBtn.png"
        titleBtn: qsTr("Setting")
    }
    Connections{
        target: settingBtn
        function onClickedBtn(){
            AppHome.openApp(2)
        }
    }
}
