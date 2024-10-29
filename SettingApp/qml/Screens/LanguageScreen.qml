import QtQuick 2.15
import "../CommonItems"
import QtQuick.Controls 2.15

LanguageGroup {
    id: groupLang
    // color: "lightgray"
    Column{
        spacing: 10
        anchors {
            left: groupLang.left
            leftMargin: 50
            top: parent.top
            topMargin: 30
        }
        LanguageItem{
            id: flagUs
            group: groupLang
            sourceImage: "qrc:/images/usFlag.png"
            textLanguage: qsTr("STR_English")
            checked: Translator.currentLanguage === "EN"
            onClicked: {
                if(!checked){
                    Translator.changeLanguage("EN")
                }
            }
        }

        LanguageItem{
            id: flagVn
            sourceImage: "qrc:/images/vnFlag.png"
            textLanguage: qsTr("STR_Vietnamese")
            group: groupLang
            checked: Translator.currentLanguage === "VN"
            onClicked: {
                if(!checked){
                    Translator.changeLanguage("VN")
                }
            }
        }
    }

}
