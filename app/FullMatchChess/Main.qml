import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_Chess_QML 1.0

Window {
    visibility: Window.FullScreen
    // width: 1280
    // height: 720
    visible: true
    title: qsTr("Hello World")

    property string whiteStepEval: ""
    property string blackStepEval: ""
    property bool isLoaded: false
    property bool isMatchComplete: false
    property string whiteStatus: ""
    property string blackStatus: ""

    Component.onCompleted: {

    }

    SoundEffect {
        id: id_soundEffect_victory
        source: Qt.resolvedUrl("res/end_game.wav")
        volume: 0.8
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"

        Background {
            anchors.fill: parent
        }
    }

    FolderDialog {
        id: id_fod_folderDialog
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        selectedFolder: viewer.folder

        onAccepted: {
            id_gs_gamescreen.mt_chess_qml.accessPGNFolder(id_fod_folderDialog.selectedFolder)
            isLoaded = true
            id_txt_event.text = id_gs_gamescreen.mt_chess_qml.getDescription()
            id_img_winplayer.source = id_gs_gamescreen.mt_chess_qml.findChampion()
            id_img_event.source = Qt.resolvedUrl("icon/" + id_gs_gamescreen.mt_chess_qml.getEventImage())
            if (id_gs_gamescreen.mt_chess_qml.getNumberOfPlayers() > 2) {
                id_pl.addItem(
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer()
                )
                id_pl.addItem(
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer()
                )
                id_pl.addItem(
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer(),
                    id_gs_gamescreen.mt_chess_qml.getNextPlayer()
                )
            } else {
                id_img_oppplayer.source = id_gs_gamescreen.mt_chess_qml.getNextPlayer()
            }
        }
    }

    GameScreen {
        id: id_gs_gamescreen
        anchors.fill: id_root

        onGameComplete: {
            console.log("Game is complete!!!")
            id_gs_gamescreen.newGame()
        }

        onMatchComplete: {
            console.log("Match is complete!!!")
            id_gs_gamescreen.clearGame()
            console.log(id_gs_gamescreen.mt_chess_qml.getWinner())
            id_img_winner.source = id_gs_gamescreen.mt_chess_qml.getWinnerImage()
            id_winannounce.visible = true
            id_soundEffect_victory.play()
        }
    }

    Rectangle {
        id: id_logo
        anchors.top: id_root.top
        anchors.left: id_root.left
        anchors.margins: 5
        width: id_root.width * 0.05
        height: width
        color: "transparent"

        Image {
            source: Qt.resolvedUrl("icon/logo.png")
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                if (isLoaded == false) {
                    id_fod_folderDialog.open()
                } else {

                }
            }
        }
    }

    Rectangle {
        id: id_button2
        anchors.bottom: id_root.bottom
        anchors.left: id_root.left
        anchors.margins: 5
        width: id_root.width * 0.05
        height: width
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_pl.clearList()
                id_img_winplayer.visible = false
                id_img_oppplayer.visible = false
                id_img_event.visible = false
                id_txt_event.visible = false
                id_gs_gamescreen.newGame()
            }
        }
    }

    FileDialog {
        id: id_fid_des
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.txt)", "All files (*)"]

        onAccepted: {
            id_txt_event.text = id_gs_gamescreen.mt_chess_qml.readDescriptionFromFile(selectedFile)
        }
    }

    Rectangle {
        id: id_button3
        anchors.top: id_root.top
        anchors.right: id_root.right
        anchors.margins: 5
        width: id_root.width * 0.05
        height: width
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_fid_des.open()
            }
        }
    }

    Image {
        id: id_img_winner
        anchors {
            verticalCenter: id_root.verticalCenter
            horizontalCenter: id_root.horizontalCenter
        }
        height: id_root.height * 0.5
        width: height

        source: ""
        opacity: 0.0
        smooth: true

        // Sequential fade in and fade out animation
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: true

            NumberAnimation { from: 0.0; to: 1.0; duration: 2000; easing.type: Easing.InOutQuad } // Fade in
            PauseAnimation { duration: 2000 } // Stay visible
        }
    }

    Text {
        id: id_winannounce
        anchors.top: id_img_winner.bottom
        anchors.horizontalCenter: id_root.horizontalCenter
        anchors.margins: 10
        text: "WINNER"
        color: "yellow"
        font.pointSize: 50
        font.bold: true
        visible: false

        PropertyAnimation on opacity {
            from: 0.0
            to: 1.0
            duration: 2000
            loops: Animation.Infinite
            easing.type: Easing.InOutQuad
            running: true
        }
    }

    Text {
        id: id_txt_event
        anchors.top: id_root.top
        anchors.horizontalCenter: id_root.horizontalCenter
        anchors.margins: 10
        width: parent.width * 0.8
        text: ""
        color: "yellow"
        font.pointSize: 30
        font.bold: true
        wrapMode: Text.WordWrap
    }

    Players {
        id: id_pl
        x: id_root.width / 2 + 50
        y: id_root.height * 0.35
        width: id_root.width * 0.4
        height: id_root.height * 0.7

        Component.onCompleted: {

        }
    }

    Image {
        id: id_img_winplayer
        anchors {
            right: id_root.horizontalCenter
            top: id_pl.top
            // margins: 30
        }
        width: id_root.width * 0.25
        height: width
        source: ""
    }

    Image {
        id: id_img_oppplayer
        anchors {
            left: id_root.horizontalCenter
            top: id_img_winplayer.top
            // margins: 30
        }
        width: id_root.width * 0.25
        height: width
        source: ""
    }

    Image {
        id: id_img_event
        anchors {
            right: id_img_winplayer.left
            verticalCenter: id_root.verticalCenter
            margins: 10
        }
        width: id_img_winplayer.width * 0.6
        height: width * 0.5
        fillMode: Image.PreserveAspectFit
    }
}
