import QtQuick
import QtQuick.Dialogs
import MT_Chess_QML 1.0

// Tasks:
// Select folder of match, contains all of pgn files
// Match cover page
// Introduce about the match
// Play game by game

Window {
    width: 1280
    height: 720
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: {
        q_id_chesstable.accessPGNFolder("file:///C:/Worspace/temps")
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"
    }

    FolderDialog {
        id: id_fod_folderDialog
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        selectedFolder: viewer.folder

        onAccepted: {
            console.log(id_fod_folderDialog.selectedFolder)
            q_id_chesstable.accessPGNFolder(id_fod_folderDialog.selectedFolder)
        }
    }

    Rectangle {
        id: id_table
        anchors.verticalCenter: id_root.verticalCenter
        anchors.horizontalCenter: id_root.horizontalCenter
        height: id_root.height * 0.98
        width: height
        color: "transparent"
        Image {
            source: Qt.resolvedUrl("icon/table.png")
            anchors.fill: parent
        }
    }

    MT_Chess_QML {
        id: q_id_chesstable
        anchors.fill: id_table
        Component.onCompleted: {
            q_id_chesstable.createTable(8, 8)
        }
    }

    Rectangle {
        id: id_button
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
                // id_fod_folderDialog.open()
                var selectedFile = q_id_chesstable.getNextPGN()
                console.log(q_id_chesstable.getInformation())
                console.log(selectedFile)
                if (selectedFile === "") {
                    console.log("Match is complete!")
                } else {
                    q_id_chesstable.reset()
                    id_ctrCharacterList.clearList()
                    q_id_chesstable.addReviewDataWithTimeFormat(selectedFile)
                    q_id_chesstable.createPieces()
                    q_id_chesstable.drawData()
                    id_tim_playgame.running = true
                }
            }
        }
    }

    Timer {
        id: id_tim_playgame
        interval: 1000; running: false; repeat: true

        onTriggered: {
            q_id_chesstable.review()

            // Get step
            if (q_id_chesstable.getWhiteStep() === "Result") {

            } else {
                if (q_id_chesstable.getBlackStep() === "") {
                    id_ctrCharacterList.addItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), q_id_chesstable.getBlackStep())
                } else {
                    id_ctrCharacterList.updateItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), q_id_chesstable.getBlackStep())
                }
            }

            if (q_id_chesstable.isGameFinish()) {
                id_tim_playgame.running = false

                var selectedFile = q_id_chesstable.getNextPGN()
                console.log(q_id_chesstable.getInformation())
                console.log(selectedFile)
                if (selectedFile === "") {
                    console.log("Match is complete!")
                } else {
                    q_id_chesstable.reset()
                    id_ctrCharacterList.clearList()
                    q_id_chesstable.addReviewDataWithTimeFormat(selectedFile)
                    q_id_chesstable.createPieces()
                    q_id_chesstable.drawData()
                }
                id_tim_playgame.running = true
            } else {
                q_id_chesstable.drawData()
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

        Image {
            source: Qt.resolvedUrl("icon/logo.png")
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                q_id_chesstable.review()
                q_id_chesstable.drawData()
            }
        }
    }

    Rectangle {
        id: id_rec_movingsteparea
        anchors {
            left: id_table.right
            verticalCenter: parent.verticalCenter
        }
        width: id_table.width * 0.4
        height: id_table.height * 0.6
        color: "transparent"

        MovingStep {
            id: id_ctrCharacterList
            anchors.fill: parent
        }
    }
}
