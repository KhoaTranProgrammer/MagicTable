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

    property bool isLoaded: false

    Component.onCompleted: {
        q_id_chesstable.setWhitePrison(id_whitePrison)
        q_id_chesstable.setBlackPrison(id_blackPrison)
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"

        Background {
            anchors.fill: parent
        }
    }

    Rectangle {
        id: id_table
        height: id_root.height * 0.98
        width: height
        anchors.centerIn: id_root
        color: "transparent"
        Image {
            source: Qt.resolvedUrl("icon/table.png")
            anchors.fill: parent
        }
    }

    Text {
        id: id_whitePlayerText
        anchors.right: id_whitePlayerPos.right
        anchors.bottom: id_whitePlayerPos.top
        anchors.margins: id_whitePlayerPos.height * 0.1
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
    }

    Text {
        id: id_textInformation
        anchors.right: id_table.left
        anchors.left: id_button.left
        anchors.verticalCenter: id_root.verticalCenter
        anchors.margins: parent.height * 0.01
        text: ""
        color: "Yellow"
        font.pointSize: 12
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignLeft
    }

    Text {
        id: id_blackPlayerText
        anchors.right: id_blackPlayerPos.right
        anchors.top: id_blackPlayerPos.bottom
        anchors.margins: id_blackPlayerPos.height * 0.1
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
    }

    Rectangle {
        id: id_whitePlayerPos
        anchors {
            bottom: id_root.bottom
            right: id_table.left
            margins: height * 0.1
        }
        height: id_root.height * 0.2
        width: height
        radius: width * 0.3
        color: "transparent"
    }

    Rectangle {
        id: id_whitePlayer
        x: (id_root.width * 0.5) + (id_root.width * 0.5 * 0.1)
        y: id_root.height * 0.3
        width: id_whitePlayerPos.width * 2
        height: id_whitePlayerPos.height * 2
        anchors.margins: height * 0.1
        radius: width * 0.3
        z: 5
        border.color: "green"  // Border color
        border.width: 10        // Border thickness

        Image {
            id: id_whitePlayerImage
            source: ""
            anchors.fill: parent
            visible: false
        }

        MultiEffect {
            source: id_whitePlayerImage
            anchors.fill: id_whitePlayerImage
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

    Rectangle {
        id: id_blackPlayerPos
        anchors {
            top: id_root.top
            right: id_table.left
            margins: height * 0.1
        }
        height: id_root.height * 0.2
        width: height
        color: "transparent"
    }

    Rectangle {
        id: id_blackPlayer
        x: (id_root.width * 0.5) - (id_root.width * 0.5 * 0.1) - (id_blackPlayerPos.width * 2)
        y: id_root.height * 0.3
        width: id_blackPlayerPos.width * 2
        height: id_blackPlayerPos.height * 2
        anchors.margins: height * 0.10
        radius: width * 0.3
        z: 5
        border.color: "green"  // Border color
        border.width: 10        // Border thickness

        Image {
            id: id_blackPlayerImage
            anchors.fill: parent
            visible: false
        }

        MultiEffect {
            source: id_blackPlayerImage
            anchors.fill: id_blackPlayerImage
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

    Rectangle {
        id: id_whitePrison
        anchors {
            left: id_table.right
            top: id_root.top
        }
        width: id_table.width * 0.3
        height: width / 4
        anchors.margins: height * 0.10
        color: "grey"
    }

    Rectangle {
        id: id_blackPrison
        anchors {
            left: id_table.right
            bottom: id_root.bottom
        }
        width: id_table.width * 0.3
        height: width / 4
        anchors.margins: height * 0.10
        color: "grey"
    }

    MT_Chess_QML {
        id: q_id_chesstable
        anchors.fill: id_table
        Component.onCompleted: {
            q_id_chesstable.createTable(8, 8)
            q_id_chesstable.createPieces()
            q_id_chesstable.drawData()
        }
    }

    Rectangle {
        id: id_winnerPos
        anchors {
            horizontalCenter: id_root.horizontalCenter
            verticalCenter: id_root.verticalCenter
            margins: height * 0.1
        }
        width: id_whitePlayerPos.width
        height: width
        radius: width * 0.3
        color: "transparent"
        z: 5
    }

    SoundEffect {
        id: soundEffect
        source: Qt.resolvedUrl("res/chess-hitting.wav")
        volume: 0.8 // Adjust volume (0.0 to 1.0)
    }

    SoundEffect {
        id: id_soundEffect_endgame
        source: Qt.resolvedUrl("res/end_game.wav")
        volume: 1.0
    }

    SoundEffect {
        id: id_soundEffect_startgame
        source: Qt.resolvedUrl("res/start_game.wav")
        volume: 1.0
    }

    Text {
        id: id_winannounce
        anchors.bottom: id_winnerPos.top
        anchors.horizontalCenter: id_root.horizontalCenter
        anchors.margins: id_blackPlayerPos.height * 0.1
        text: ""
        color: "yellow"
        font.pointSize: 50
        font.bold: true

        PropertyAnimation on opacity {
            from: 0.0
            to: 1.0
            duration: 2000
            loops: Animation.Infinite
            easing.type: Easing.InOutQuad
            running: true
        }
    }

    Timer {
        id: id_finishtimer
        interval: 3000; running: false; repeat: false
        onTriggered: {
            id_soundEffect_background.stop()
            id_soundEffect_endgame.play()

            if (q_id_chesstable.getResult() === "white") {
                id_whitePlayer.x = id_winnerPos.x
                id_whitePlayer.y = id_winnerPos.y
                id_winannounce.text = "White is winner"
            }
            if (q_id_chesstable.getResult() === "black") {
                id_blackPlayer.x = id_winnerPos.x
                id_blackPlayer.y = id_winnerPos.y
                id_winannounce.text = "Black is winner"
            }
            if (q_id_chesstable.getResult() === "draw") {
                id_winannounce.text = "Draw 1/2-1/2"
            }
        }
    }

    Timer {
        id: id_timer
        interval: 2000; running: false; repeat: true

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
                id_timer.running = false
                id_finishtimer.running = true
            } else {
                q_id_chesstable.drawData()
                soundEffect.play()
            }
        }
    }

    SoundEffect {
        id: id_soundEffect_background
        source: Qt.resolvedUrl("res/LegendofOne.wav")
        volume: 0.8
    }

    Timer {
        id: id_timetostart
        interval: 2000; running: false; repeat: false

        onTriggered: {
            id_soundEffect_background.play()
            id_timer.running = true
        }
    }

    FileDialog {
        id: fileDialog
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.pgn)", "All files (*)"]

        onAccepted: {
            console.log("Selected file:", selectedFile)
            isLoaded = true
            q_id_chesstable.addReviewData(selectedFile)
            id_blackPlayerText.text = q_id_chesstable.getBlackPlayerName()
            id_whitePlayerText.text = q_id_chesstable.getWhitePlayerName()
            id_textInformation.text = q_id_chesstable.getInformation()
            id_whitePlayerImage.source = q_id_chesstable.getWhiteImage()
            id_blackPlayerImage.source = q_id_chesstable.getBlackImage()
        }

        onRejected: {
            console.log("File selection canceled")
        }
    }

    Rectangle {
        id: id_button
        anchors.right: id_whitePlayerPos.left
        anchors.top: id_root.top
        anchors.margins: id_root.height * 0.05
        width: id_root.height * 0.1
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
                    fileDialog.open()
                } else {
                    // For debugging
                    // q_id_chesstable.review()
                    // q_id_chesstable.drawData()
                    // if (q_id_chesstable.getBlackStep() === "") {
                    //     id_ctrCharacterList.addItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), q_id_chesstable.getBlackStep())
                    // } else {
                    //     id_ctrCharacterList.updateItem(q_id_chesstable.getStepNumber(), q_id_chesstable.getWhiteStep(), q_id_chesstable.getBlackStep())
                    // }

                    // For running
                    id_soundEffect_startgame.play()

                    id_blackPlayer.x = id_blackPlayerPos.x
                    id_blackPlayer.y = id_blackPlayerPos.y
                    id_whitePlayer.x = id_whitePlayerPos.x
                    id_whitePlayer.y = id_whitePlayerPos.y

                    id_blackPlayer.width = id_blackPlayerPos.width
                    id_blackPlayer.height = id_blackPlayerPos.height
                    id_whitePlayer.width = id_whitePlayerPos.width
                    id_whitePlayer.height = id_whitePlayerPos.height

                    id_timetostart.running = true
                }
            }
        }
    }

    Rectangle {
        id: id_movingsteparea
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
