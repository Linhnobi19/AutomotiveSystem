import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import "commonItem"
import Fpt.StatusBar 1.0
// import QtGraphicalEffects 1.15

Window {

    function backtoHome()
    {
        DBusHandler.returnHome()
    }
    function changelang()
    {
        Controller.next()
    }
    function up()
    {
        Controller.prev()
    }
    function down()
    {
        Controller.back()
    }
    id: root
    visible: Controller.isShow
    // visible: true
    width: 1080
    height: 608
    title: qsTr("App Music")

    property int inPage: -1

    // Image{
    //     id: covertArt
    //     anchors.fill: parent
    //     source: "file://" + Model.currentSong.imagePath
    // }
    Rectangle{
        anchors.fill: parent
        color: "#9cac9c" // "#E9EFEC"//"#ffe6a5"
        opacity: 0.5
    }



    CustomStatusBar{
        id: statusBar
        width: parent.width
        height: 60
        textDirect: root.inPage === 0 ? qsTr("Music") :
                            (root.inPage === 1 ? qsTr("Music > List") :
                                qsTr("Music > Search"));

        modelListButton: []
        Component.onCompleted: {
            console.log("Status bar is created completely");
        }
    }



    Loader
    {
        id:loader
        anchors.top: statusBar.bottom
        width: parent.width
        height: parent.height - statusBar.height

        source: "MediaPlayScreen.qml"

        Component.onCompleted: {
            root.inPage = 0;
            statusBar.modelListButton = []
            statusBar.modelListButton = [
                        {
                            "textButton" : "Back",
                            "image" : "left.png",
                            "func" : function() {
                                Controller.setSearch("")
                                loader.source = "MediaPlayScreen.qml"
                            }
                        },
                        {
                            "textButton" : "Home",
                            "image" : "home.png",
                            "func" : function() {
                                console.log("click to home")
                                DBusHandler.returnHome();
                            }
                        },
                        {
                            "textButton" : "List",
                            "image" : "list.png",
                            "func" : function() {
                                loader.source = "SongListScreen.qml"
                            }
                        },
                        {
                            "textButton" : "search",
                            "image" : "search.png",
                            "func" : function() {
                                console.log("click to home")
                                loader.source = "SearchListScreen.qml"
                            }
                        }

                    ]
        }


        onSourceChanged: {
            if(loader.source == "qrc:/MediaPlayScreen.qml"){
                root.inPage = 0
                statusBar.modelListButton = []
                statusBar.modelListButton = [
                            {
                                "textButton" : "Back",
                                "image" : "left.png",
                                "func" : function() {
                                    Controller.setSearch("")
                                    loader.source = "MediaPlayScreen.qml"
                                }
                            },
                            {
                                "textButton" : "Home",
                                "image" : "home.png",
                                "func" : function() {
                                    console.log("click to home")
                                    DBusHandler.returnHome();
                                }
                            },
                            {
                                "textButton" : "List",
                                "image" : "list.png",
                                "func" : function() {
                                    console.log("click to home")
                                    loader.source = "SongListScreen.qml"
                                }
                            },
                            {
                                "textButton" : "search",
                                "image" : "search.png",
                                "func" : function() {
                                    console.log("click to home")
                                    loader.source = "SearchListScreen.qml"
                                }
                            }

                        ]
            }
            else {
                statusBar.modelListButton = []
                statusBar.modelListButton = [
                            {
                                "textButton" : "Back",
                                "image" : "left.png",
                                "func" : function() {
                                    Controller.setSearch("")
                                    loader.source = "MediaPlayScreen.qml"
                                }
                            },
                            {
                                "textButton" : "Home",
                                "image" : "home.png",
                                "func" : function() {
                                    console.log("click to home")
                                    DBusHandler.returnHome();
                                }
                            },

                        ]

                if(loader.source == "qrc:/SongListScreen.qml"){
                    root.inPage = 1
                }
                else if (loader.source == "qrc:/SearchListScreen.qml"){
                    root.inPage = 2
                }
            }
        }
    }
}
