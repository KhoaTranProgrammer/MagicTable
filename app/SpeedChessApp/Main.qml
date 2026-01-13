import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_Chess_QML 1.0

Window {
    visibility: Window.FullScreen
    // width: 720
    // height: 1544

    visible: true
    title: qsTr("Hello World")

    property bool isLoaded: false

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

    Rectangle {
        id: id_table
        anchors.verticalCenter: id_root.verticalCenter
        anchors.horizontalCenter: id_root.horizontalCenter
        width: id_root.width * 0.98
        height: width
        color: "transparent"
        Image {
            id: id_img_table
            source: Qt.resolvedUrl("icon/table.png")
            anchors.fill: parent
            visible: false
        }
    }

    Rectangle {
        id: id_rec_event
        anchors {
            bottom: id_rec_blackplayer.top
            horizontalCenter: id_root.horizontalCenter
            margins: 10
        }
        width: id_root.width * 0.5
        height: width * 0.5
        color: "transparent"
        Image {
            id: id_img_event
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
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
        id: id_blackPlayerPos
        anchors {
            left: id_root.left
            bottom: id_table.top
            margins: 10
        }
        width: id_root.width * 0.2
        height: width
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
        anchors.horizontalCenter: id_rec_blackplayer.horizontalCenter
        anchors.top: id_rec_blackplayer.bottom
        anchors.margins: 2
        text: ""
        color: "black"
        font.pointSize: 14
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
            left: id_root.left
            top: id_table.bottom
            margins: 10
        }
        width: id_root.width * 0.2
        height: width
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
        anchors.horizontalCenter: id_rec_whiteplayer.horizontalCenter
        anchors.top: id_rec_whiteplayer.bottom
        anchors.margins: 2
        text: ""
        color: "black"
        font.pointSize: 14
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
        id: id_blackwinannounce
        anchors.bottom: id_table.top
        anchors.left: id_rec_blackplayer.right
        anchors.margins: 2
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

    Text {
        id: id_whitewinannounce
        anchors.top: id_txt_whiteplayer_elo.bottom
        anchors.left: id_rec_whiteplayer.right
        anchors.margins: 2
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

    Text {
        id: id_txt_infor
        anchors.top: id_txt_whiteplayer_elo.bottom
        anchors.left: id_root.left
        anchors.right: id_root.right
        anchors.margins: 2
        width: id_root.width
        text: ""
        color: "yellow"
        font.pointSize: 35
        font.bold: true
        wrapMode: Text.WordWrap
        horizontalAlignment: Text.AlignHCenter
    }

    FileDialog {
        id: id_fid_selectpgn
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.pgn, *.txt)", "All files (*)"]

        onAccepted: {
            isLoaded = true
            q_id_chesstable.addReviewDataWithTimeFormat(selectedFile)
            q_id_chesstable.createPieces()
            q_id_chesstable.setWhitePrison(id_whitePrison)
            q_id_chesstable.setBlackPrison(id_blackPrison)
            id_img_whitePlayerImage.source = q_id_chesstable.getWhiteImage()
            id_img_blackPlayerImage.source = q_id_chesstable.getBlackImage()
            id_txt_blackplayer.text = q_id_chesstable.getBlackPlayerName()
            id_txt_blackplayer_elo.text = "Elo: " + q_id_chesstable.getBlackElo()
            id_txt_whiteplayer.text = q_id_chesstable.getWhitePlayerName()
            id_txt_whiteplayer_elo.text = "Elo: " + q_id_chesstable.getWhiteElo()

            id_txt_infor.text = q_id_chesstable.getInformation()

            console.log(q_id_chesstable.getEvent())
            id_img_event.source = Qt.resolvedUrl("icon/" + q_id_chesstable.getEventImage())
        }
    }

    Rectangle {
        id: id_button
        anchors.top: id_blackPlayerPos.top
        anchors.right: id_root.right
        anchors.margins: 5
        width: id_root.width * 0.1
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
                    id_fid_selectpgn.open()
                } else {
                    id_rec_event.visible = false
                    id_img_table.visible = true
                    q_id_chesstable.drawData()

                    id_rec_blackplayer.x = id_blackPlayerPos.x
                    id_rec_blackplayer.y = id_blackPlayerPos.y
                    id_rec_whiteplayer.x = id_whitePlayerPos.x
                    id_rec_whiteplayer.y = id_whitePlayerPos.y

                    id_rec_blackplayer.width = id_blackPlayerPos.width
                    id_rec_blackplayer.height = id_blackPlayerPos.height
                    id_rec_whiteplayer.width = id_whitePlayerPos.width
                    id_rec_whiteplayer.height = id_whitePlayerPos.height

                    id_txt_blackplayer.anchors.left = id_rec_blackplayer.right
                    id_txt_blackplayer.anchors.top = id_rec_blackplayer.top
                    id_txt_blackplayer.color = "white"
                    id_txt_blackplayer_elo.color = "white"

                    id_txt_whiteplayer.anchors.left = id_rec_whiteplayer.right
                    id_txt_whiteplayer.anchors.top = id_rec_whiteplayer.top
                    id_txt_whiteplayer.color = "white"
                    id_txt_whiteplayer_elo.color = "white"

                    id_txt_infor.anchors.top = undefined
                    id_txt_infor.anchors.bottom = id_rec_blackplayer.top
                    id_txt_infor.anchors.left = id_rec_blackplayer.left
                    id_txt_infor.font.pointSize = 10
                    id_txt_infor.font.bold = false
                    id_txt_infor.color = "yellow"

                    id_whitePrison.visible = true
                    id_blackPrison.visible = true

                    id_timer.running = true

                    // For debugging
                    // q_id_chesstable.review()
                    // q_id_chesstable.drawData()

                    // if (q_id_chesstable.getBlackStep() === "") {
                    //     id_txt_whiteplayer_clock.text = q_id_chesstable.getWhiteClockTime()
                    // } else {
                    //     id_txt_blackplayer_clock.text = q_id_chesstable.getBlackClockTime()
                    // }
                }
            }
        }
    }

    Rectangle {
        id: id_blackPrison
        anchors {
            left: id_rec_whiteplayer.right
            top: id_txt_whiteplayer_elo.bottom
        }
        width: id_table.width * 0.3
        height: width / 4
        // anchors.margins: height * 0.10
        color: "grey"
        visible: false
    }

    Rectangle {
        id: id_whitePrison
        anchors {
            left: id_rec_blackplayer.right
            top: id_txt_blackplayer_elo.bottom
        }
        width: id_table.width * 0.3
        height: width / 4
        // anchors.margins: height * 0.10
        color: "grey"
        visible: false
    }

    SoundEffect {
        id: id_sde_chesshitting
        source: Qt.resolvedUrl("res/move.wav")
        volume: 0.8 // Adjust volume (0.0 to 1.0)
    }

    Timer {
        id: id_tim_play
        interval: 800; running: false; repeat: true

        onTriggered: {
            q_id_chesstable.review()

            if (q_id_chesstable.getBlackStep() === "") {
                id_txt_whiteplayer_clock.text = q_id_chesstable.getWhiteClockTime()
            } else {
                id_txt_blackplayer_clock.text = q_id_chesstable.getBlackClockTime()
            }

            if (q_id_chesstable.isGameFinish()) {
                id_timer.running = false

                if (q_id_chesstable.getResult() === "white") {
                    id_whitewinannounce.text = "WINNER"
                }
                if (q_id_chesstable.getResult() === "black") {
                    id_blackwinannounce.text = "WINNER"
                }
                if (q_id_chesstable.getResult() === "draw") {
                    id_whitewinannounce.text = "DRAW"
                    id_blackwinannounce.text = "DRAW"
                }

                id_whitePrison.visible = false
                id_blackPrison.visible = false
                id_txt_whiteplayer_clock.text = ""
                id_txt_blackplayer_clock.text = ""
            } else {
                q_id_chesstable.drawData()
                id_sde_chesshitting.play()
            }
        }
    }

    Timer {
        id: id_timer
        interval: 2000; running: false; repeat: false

        onTriggered: {
            id_tim_play.running = true
        }
    }
}
