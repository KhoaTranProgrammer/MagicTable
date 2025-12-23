import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_Chess_QML 1.0

Window {
    width: 1280
    height: 720
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
            console.log(id_gs_gamescreen.mt_chess_qml.getWinnerImage())
        }
    }

    Rectangle {
        id: id_logo
        anchors.top: id_root.top
        anchors.right: id_root.right
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
        anchors.top: id_root.top
        anchors.left: id_root.left
        anchors.margins: 5
        width: id_root.width * 0.05
        height: width
        color: "transparent"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_gs_gamescreen.newGame()
            }
        }
    }
}
