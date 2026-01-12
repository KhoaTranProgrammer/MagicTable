import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_Chess_QML 1.0

Item {
    id: id_root
    anchors.fill: parent

    // Define a signal with a parameter
    signal gameComplete()
    signal matchComplete()

    property var mt_chess_qml
    property bool isStartComplete: false
    property string whiteStatus: ""
    property string blackStatus: ""

    Component.onCompleted: {
        mt_chess_qml = q_id_chesstable
    }

    SoundEffect {
        id: id_soundEffect_background
        source: Qt.resolvedUrl("res/background.wav")
        volume: 0.8
    }

    SoundEffect {
        id: id_sde_chesshitting
        source: Qt.resolvedUrl("res/move.wav")
        volume: 1.0 // Adjust volume (0.0 to 1.0)
    }

    Rectangle {
        id: id_table
        anchors.verticalCenter: id_root.verticalCenter
        anchors.horizontalCenter: id_root.horizontalCenter
        height: id_root.height * 0.98
        width: height
        color: "transparent"
        Image {
            id: id_img_table
            source: Qt.resolvedUrl("icon/table.png")
            anchors.fill: parent
            visible: false
        }
    }

    MT_Chess_QML {
        id: q_id_chesstable
        anchors.fill: id_table
        Component.onCompleted: {
            q_id_chesstable.createTable(8, 8)
            q_id_chesstable.setAnimationTime(400)
        }
    }

    Rectangle {
        id: id_blackPlayerPos
        anchors {
            right: id_table.left
            top: id_table.top
            margins: 10
        }
        height: id_root.height * 0.15
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
        color: "transparent"

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

    Image {
        id: id_img_whitewinner
        anchors {
            left: id_whitePlayerPos.right
            top: id_whitePlayerPos.top
            bottom: id_whitePlayerPos.bottom
        }
        width: height

        source: ""
        opacity: 0.0
        smooth: true

        // Sequential fade in and fade out animation
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: true

            NumberAnimation { from: 0.0; to: 1.0; duration: 200; easing.type: Easing.InOutQuad } // Fade in
            PauseAnimation { duration: 200 } // Stay visible
            NumberAnimation { from: 1.0; to: 0.0; duration: 200; easing.type: Easing.InOutQuad } // Fade out
            PauseAnimation { duration: 200 } // Stay invisible
        }
    }

    Image {
        id: id_img_blackwinner
        anchors {
            right: id_blackPlayerPos.left
            top: id_blackPlayerPos.top
            bottom: id_blackPlayerPos.bottom
        }
        width: height

        source: ""
        opacity: 0.0
        smooth: true

        // Sequential fade in and fade out animation
        SequentialAnimation on opacity {
            loops: Animation.Infinite
            running: true

            NumberAnimation { from: 0.0; to: 1.0; duration: 200; easing.type: Easing.InOutQuad } // Fade in
            PauseAnimation { duration: 200 } // Stay visible
            NumberAnimation { from: 1.0; to: 0.0; duration: 200; easing.type: Easing.InOutQuad } // Fade out
            PauseAnimation { duration: 200 } // Stay invisible
        }
    }

    Rectangle {
        id: id_whitePlayerPos
        anchors {
            left: id_table.right
            bottom: id_table.bottom
            margins: 10
        }
        height: id_root.height * 0.15
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
        color: "transparent"

        Image {
            id: id_img_whitePlayerImage
            source: ""
            anchors.fill: parent
            visible: true
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

    Rectangle {
        id: id_rec_movingsteparea
        anchors {
            left: id_table.right
            top: id_blackPlayerPos.bottom
        }
        width: id_table.width * 0.4
        height: id_table.height * 0.5
        color: "transparent"

        MovingStep {
            id: id_ctrCharacterList
            anchors.fill: parent
        }
    }

    Timer {
        id: id_tim_playgame
        interval: 800; running: false; repeat: true

        onTriggered: {
            // id_txt_infor.text = q_id_chesstable.getInformation()
            q_id_chesstable.review()
            id_sde_chesshitting.play()

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
                id_soundEffect_background.stop()

                if (q_id_chesstable.getResult() === "white") {
                    id_img_whitewinner.source = Qt.resolvedUrl("icon/winner.png")
                    whiteStatus = "winner"
                    blackStatus = "loser"
                }
                if (q_id_chesstable.getResult() === "black") {
                    id_img_blackwinner.source = Qt.resolvedUrl("icon/winner.png")
                    whiteStatus = "loser"
                    blackStatus = "winner"
                }
                if (q_id_chesstable.getResult() === "draw") {
                    id_img_whitewinner.source = Qt.resolvedUrl("icon/draw.png")
                    id_img_blackwinner.source = Qt.resolvedUrl("icon/draw.png")
                    whiteStatus = "draw"
                    blackStatus = "draw"
                }
                id_rod_rounds.addItem(q_id_chesstable.getRound(), q_id_chesstable.getWhiteImage(), whiteStatus
                                      , q_id_chesstable.getBlackImage(), blackStatus)

                id_tim_stopgame.running = true
            } else {
                q_id_chesstable.drawData()
            }
        }
    }

    Text {
        id: id_txt_infor
        anchors.top: id_root.top
        anchors.right: id_root.right
        anchors.left: id_table.right
        anchors.margins: 2
        text: ""
        color: "yellow"
        font.pointSize: 11
        font.bold: true
        wrapMode: Text.WordWrap
    }

    Text {
        id: id_txt_roundinfo
        anchors.horizontalCenter: id_root.horizontalCenter
        anchors.verticalCenter: id_blackPlayerPos.verticalCenter
        anchors.margins: 5
        text: ""
        color: "yellow"
        font.pointSize: 50
        font.bold: true
        font.family: "Helvetica"
    }

    Rectangle {
        id: id_rec_roundarea
        anchors {
            right: id_table.left
            bottom: id_table.bottom
        }
        width: id_table.width * 0.6
        height: id_table.height * 0.7
        color: "transparent"

        Rounds {
            id: id_rod_rounds
            anchors.fill: parent
        }
    }

    Timer {
        id: id_tim_startgame
        interval: 4000; running: false; repeat: true

        onTriggered: {
            console.log("id_tim_startgame onTriggered")
            if (isStartComplete === false) {
                id_img_table.visible = true

                id_rec_blackplayer.x = id_blackPlayerPos.x
                id_rec_blackplayer.y = id_blackPlayerPos.y
                id_rec_whiteplayer.x = id_whitePlayerPos.x
                id_rec_whiteplayer.y = id_whitePlayerPos.y

                id_rec_blackplayer.width = id_blackPlayerPos.width
                id_rec_blackplayer.height = id_blackPlayerPos.height
                id_rec_whiteplayer.width = id_whitePlayerPos.width
                id_rec_whiteplayer.height = id_whitePlayerPos.height

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

                id_txt_roundinfo.text = ""

                isStartComplete = true
            } else {
                id_tim_startgame.running = false
                id_tim_playgame.running = true
                q_id_chesstable.drawData()
                id_soundEffect_background.play()
            }
        }
    }

    Timer {
        id: id_tim_stopgame
        interval: 3000; running: false; repeat: false

        onTriggered: {
            id_img_whitewinner.source = ""
            id_img_blackwinner.source = ""
            id_txt_blackplayer_elo.text = ""
            id_txt_whiteplayer_elo.text = ""
            id_txt_blackplayer.text = ""
            id_txt_whiteplayer.text = ""

            id_img_blackPlayerImage.source = ""
            id_img_whitePlayerImage.source = ""

            id_rec_blackplayer.x = (id_root.width * 0.5) - (id_root.width * 0.5 * 0.1) - (id_blackPlayerPos.width * 2)
            id_rec_blackplayer.y = id_root.height * 0.3
            id_rec_blackplayer.width = id_blackPlayerPos.width * 2
            id_rec_blackplayer.height = id_blackPlayerPos.height * 2

            id_rec_whiteplayer.x = (id_root.width * 0.5) + (id_root.width * 0.5 * 0.1)
            id_rec_whiteplayer.y = id_root.height * 0.3
            id_rec_whiteplayer.width = id_whitePlayerPos.width * 2
            id_rec_whiteplayer.height = id_whitePlayerPos.height * 2

            gameComplete()
        }
    }

    function newGame() {
        var selectedFile = q_id_chesstable.getNextPGN()
        if (selectedFile === "") {
            matchComplete()
        } else {
            id_img_whitewinner.source = ""
            id_img_blackwinner.source = ""
            id_txt_blackplayer_elo.text = ""
            id_txt_whiteplayer_elo.text = ""

            id_txt_blackplayer.anchors.right = id_rec_blackplayer.right
            id_txt_blackplayer.anchors.top = id_rec_blackplayer.bottom
            id_txt_blackplayer.color = "yellow"
            id_txt_blackplayer.font.pointSize = 25

            id_txt_whiteplayer_elo.anchors.top = undefined
            id_txt_whiteplayer_elo.anchors.bottom = undefined
            id_txt_whiteplayer.anchors.top = undefined
            id_txt_whiteplayer.anchors.bottom = undefined
            id_txt_whiteplayer.anchors.left = id_rec_whiteplayer.left
            id_txt_whiteplayer.anchors.top = id_rec_whiteplayer.bottom
            id_txt_whiteplayer.color = "yellow"
            id_txt_whiteplayer.font.pointSize = 25
            id_txt_whiteplayer_elo.anchors.top = id_txt_whiteplayer.bottom

            q_id_chesstable.reset()
            id_ctrCharacterList.clearList()
            q_id_chesstable.addReviewDataWithTimeFormat(selectedFile)

            id_img_blackPlayerImage.source = q_id_chesstable.getBlackImage()
            id_img_whitePlayerImage.source = q_id_chesstable.getWhiteImage()

            id_txt_blackplayer.text = q_id_chesstable.getBlackPlayerName()
            id_txt_blackplayer_elo.text = "Elo: " + q_id_chesstable.getBlackElo()
            id_txt_whiteplayer.text = q_id_chesstable.getWhitePlayerName()
            id_txt_whiteplayer_elo.text = "Elo: " + q_id_chesstable.getWhiteElo()

            id_txt_infor.text = q_id_chesstable.getInformation()

            isStartComplete = false

            q_id_chesstable.createPieces()
            id_txt_roundinfo.text = q_id_chesstable.getRound()

            id_tim_startgame.running = true
        }
    }

    function clearGame() {
        q_id_chesstable.reset()
        id_ctrCharacterList.clearList()
        id_img_table.visible = false
        id_txt_infor.text = ""
    }
}
