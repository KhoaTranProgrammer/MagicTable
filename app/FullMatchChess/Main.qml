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

    Component.onCompleted: {
        // q_id_chesstable.accessPGNFolder("file:///C:/Worspace/temps")
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
            q_id_chesstable.accessPGNFolder(id_fod_folderDialog.selectedFolder)
            isLoaded = true
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
                    newGame()
                    id_txt_banner.text = q_id_chesstable.getEvent()
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
                    whiteStepEval = q_id_chesstable.getMoveEval()
                    id_ctrCharacterList.addItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), whiteStepEval, q_id_chesstable.getBlackStep(), blackStepEval)
                } else {
                    blackStepEval = q_id_chesstable.getMoveEval()
                    id_ctrCharacterList.updateItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), whiteStepEval, q_id_chesstable.getBlackStep(), blackStepEval)

                    whiteStepEval = ""
                    blackStepEval = ""
                }
            }

            if (q_id_chesstable.isGameFinish()) {
                id_tim_playgame.running = false
                id_tim_stop.running = true
                newGame()
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

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_tim_start.running = true

                id_txt_blackplayer.anchors.right = id_rec_blackplayer.right
                id_txt_blackplayer.anchors.top = id_rec_blackplayer.bottom
                id_txt_blackplayer.color = "white"
                id_txt_blackplayer_elo.color = "white"
                id_txt_blackplayer.font.pointSize = 12
                id_txt_blackplayer_elo.font.pointSize = 12

                id_txt_whiteplayer_elo.anchors.top = undefined
                id_txt_whiteplayer_elo.anchors.bottom = id_rec_whiteplayer.top
                id_txt_whiteplayer_elo.color = "white"
                id_txt_whiteplayer_elo.font.pointSize = 12
                id_txt_whiteplayer.anchors.top = undefined
                id_txt_whiteplayer.anchors.left = id_rec_whiteplayer.left
                id_txt_whiteplayer.anchors.bottom = id_txt_whiteplayer_elo.top
                id_txt_whiteplayer.color = "white"
                id_txt_whiteplayer.font.pointSize = 12

                id_txt_banner.text = ""
            }
        }
    }

    Rectangle {
        id: id_rec_movingsteparea
        anchors {
            left: id_table.right
            // verticalCenter: parent.verticalCenter
            top: id_logo.bottom
        }
        width: id_table.width * 0.4
        height: id_table.height * 0.6
        color: "transparent"

        MovingStep {
            id: id_ctrCharacterList
            anchors.fill: parent
        }
    }

    Rectangle {
        id: id_blackPlayerPos
        anchors {
            right: id_table.left
            top: id_table.top
            margins: 10
        }
        height: id_root.height * 0.2
        width: height
        color: "transparent"
    }

    Rectangle {
        id: id_rec_blackplayer
        x: (id_root.width * 0.5) - (id_root.width * 0.5 * 0.1) - (id_blackPlayerPos.width * 2)
        y: id_root.height * 0.3
        width: id_blackPlayerPos.width * 2
        height: id_blackPlayerPos.height * 2
        anchors.margins: 5
        z: 5

        Image {
            id: id_img_blackPlayerImage
            source: ""
            anchors.fill: parent
            visible: true
        }

        MultiEffect {
            source: id_img_blackPlayerImage
            anchors.fill: id_img_blackPlayerImage
            maskEnabled: true
            maskSource: id_blackmask
        }

        Item {
            id: id_blackmask
            anchors.fill: parent
            layer.enabled: true
            visible: false

            Rectangle {
                anchors.fill: parent
                radius: width * 0.3
                color: "black"
            }
        }
        // Animation for smooth movement
        Behavior on x { NumberAnimation { duration: 500 } }
        Behavior on y { NumberAnimation { duration: 500 } }
    }

    Text {
        id: id_txt_blackplayer
        anchors.right: id_rec_blackplayer.right
        anchors.top: id_rec_blackplayer.bottom
        anchors.margins: 2
        text: ""
        color: "yellow"
        font.pointSize: 25
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_blackplayer_elo
        anchors.left: id_txt_blackplayer.left
        anchors.top: id_txt_blackplayer.bottom
        anchors.margins: 2
        text: ""
        color: "black"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_blackplayer_clock
        anchors.right: id_table.right
        anchors.bottom: id_table.top
        anchors.margins: 5
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "DejaVu Sans Mono"
    }

    Rectangle {
        id: id_whitePlayerPos
        anchors {
            left: id_table.right
            bottom: id_table.bottom
            margins: 10
        }
        height: id_root.height * 0.2
        width: height
        color: "transparent"
    }

    Rectangle {
        id: id_rec_whiteplayer
        x: (id_root.width * 0.5) + (id_root.width * 0.5 * 0.1)
        y: id_root.height * 0.3
        width: id_whitePlayerPos.width * 2
        height: id_whitePlayerPos.height * 2
        anchors.margins: 5
        z: 5

        Image {
            id: id_img_whitePlayerImage
            source: ""
            anchors.fill: parent
            visible: true
            // fillMode: Image.PreserveAspectFit
        }

        MultiEffect {
            source: id_img_whitePlayerImage
            anchors.fill: id_img_whitePlayerImage
            maskEnabled: true
            maskSource: id_whitemask
        }

        Item {
            id: id_whitemask
            anchors.fill: parent
            layer.enabled: true
            visible: false

            Rectangle {
                anchors.fill: parent
                radius: width * 0.3
                color: "black"
            }
        }
        // Animation for smooth movement
        Behavior on x { NumberAnimation { duration: 500 } }
        Behavior on y { NumberAnimation { duration: 500 } }
    }

    Text {
        id: id_txt_whiteplayer
        anchors.left: id_rec_whiteplayer.left
        anchors.top: id_rec_whiteplayer.bottom
        anchors.margins: 2
        text: ""
        color: "yellow"
        font.pointSize: 25
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_whiteplayer_elo
        anchors.left: id_txt_whiteplayer.left
        anchors.top: id_txt_whiteplayer.bottom
        anchors.margins: 2
        text: ""
        color: "black"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_whiteplayer_clock
        anchors.right: id_table.right
        anchors.top: id_table.bottom
        anchors.margins: 5
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "DejaVu Sans Mono"
    }

    Text {
        id: id_txt_banner
        anchors.top: id_root.top
        anchors.left: id_table.left
        anchors.right: id_table.right
        anchors.margins: 2
        width: id_root.width
        text: ""
        color: "red"
        font.pointSize: 50
        font.bold: true
        wrapMode: Text.WordWrap
    }

    Timer {
        id: id_tim_start
        interval: 2000; running: false; repeat: false

        onTriggered: {
            id_rec_blackplayer.x = id_blackPlayerPos.x
            id_rec_blackplayer.y = id_blackPlayerPos.y
            id_rec_whiteplayer.x = id_whitePlayerPos.x
            id_rec_whiteplayer.y = id_whitePlayerPos.y

            id_rec_blackplayer.width = id_blackPlayerPos.width
            id_rec_blackplayer.height = id_blackPlayerPos.height
            id_rec_whiteplayer.width = id_whitePlayerPos.width
            id_rec_whiteplayer.height = id_whitePlayerPos.height

            // id_txt_blackplayer.text = q_id_chesstable.getBlackPlayerName()
            // id_txt_blackplayer_elo.text = "Elo: " + q_id_chesstable.getBlackElo()

            id_tim_playgame.running = true
            q_id_chesstable.drawData()
        }
    }

    Timer {
        id: id_tim_stop
        interval: 2000; running: false; repeat: false

        onTriggered: {
            // id_rec_blackplayer.x = id_blackPlayerPos.x
            // id_rec_blackplayer.y = id_blackPlayerPos.y
            // id_rec_whiteplayer.x = id_whitePlayerPos.x
            // id_rec_whiteplayer.y = id_whitePlayerPos.y

            // id_rec_blackplayer.width = id_blackPlayerPos.width
            // id_rec_blackplayer.height = id_blackPlayerPos.height
            // id_rec_whiteplayer.width = id_whitePlayerPos.width
            // id_rec_whiteplayer.height = id_whitePlayerPos.height

            id_tim_start.running = true
        }
    }

    function newGame() {
        var selectedFile = q_id_chesstable.getNextPGN()
        console.log(q_id_chesstable.getInformation())
        console.log(selectedFile)
        if (selectedFile === "") {
            console.log("Match is complete!")
        } else {
            q_id_chesstable.reset()
            id_ctrCharacterList.clearList()
            q_id_chesstable.addReviewDataWithTimeFormat(selectedFile)

            id_img_blackPlayerImage.source = q_id_chesstable.getBlackImage()
            id_img_whitePlayerImage.source = q_id_chesstable.getWhiteImage()

            id_txt_blackplayer.text = q_id_chesstable.getBlackPlayerName()
            id_txt_blackplayer_elo.text = "Elo: " + q_id_chesstable.getBlackElo()
            id_txt_whiteplayer.text = q_id_chesstable.getWhitePlayerName()
            id_txt_whiteplayer_elo.text = "Elo: " + q_id_chesstable.getWhiteElo()
            // id_txt_banner.text = q_id_chesstable.getEvent()

            q_id_chesstable.createPieces()
            // q_id_chesstable.drawData()
            // id_tim_playgame.running = true

            // id_tim_start.running = true
        }
    }
}
