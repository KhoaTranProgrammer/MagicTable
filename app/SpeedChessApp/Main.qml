import QtQuick
import QtQuick.Dialogs
import MT_Chess_QML 1.0

Window {
    width: 480
    height: 640
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: {
        q_id_chesstable.addReviewDataWithTimeFormat("file:///C:/Users/admin/Downloads/Van Foreest, Jorden_vs_Jobava, Baadur_2025.11.30.pgn")
        console.log(q_id_chesstable.getWhiteImage())
        console.log(q_id_chesstable.getBlackImage())
        id_img_whitePlayerImage.source = q_id_chesstable.getWhiteImage()
        id_img_blackPlayerImage.source = q_id_chesstable.getBlackImage()
        id_txt_blackplayer.text = q_id_chesstable.getBlackPlayerName()
        id_txt_blackplayer_elo.text = "Elo: " + q_id_chesstable.getBlackElo()
        id_txt_whiteplayer.text = q_id_chesstable.getWhitePlayerName()
        id_txt_whiteplayer_elo.text = "Elo: " + q_id_chesstable.getWhiteElo()
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
        width: id_root.width * 0.9
        height: width
        anchors.centerIn: id_root
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
            q_id_chesstable.createPieces()
            q_id_chesstable.drawData()
        }
    }

    FileDialog {
        id: fileDialog
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.pgn)", "All files (*)"]

        onAccepted: {
            console.log("Selected file:", selectedFile)
        }
    }

    Rectangle {
        id: id_rec_blackplayer
        anchors {
            left: id_root.left
            bottom: id_table.top
            margins: 5
        }
        width: id_root.width * 0.2
        height: width
        color: "black"

        Image {
            id: id_img_whitePlayerImage
            source: ""
            anchors.fill: parent
            visible: true
            // fillMode: Image.PreserveAspectFit
        }
    }

    Text {
        id: id_txt_blackplayer
        anchors.left: id_rec_blackplayer.right
        anchors.top: id_rec_blackplayer.top
        anchors.margins: 2
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_blackplayer_elo
        anchors.left: id_rec_blackplayer.right
        anchors.top: id_txt_blackplayer.bottom
        anchors.margins: 2
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_blackplayer_clock
        anchors.right: id_root.right
        anchors.bottom: id_table.top
        anchors.margins: 5
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "DejaVu Sans Mono"
    }

    Rectangle {
        id: id_rec_whiteplayer
        anchors {
            left: id_root.left
            top: id_table.bottom
            margins: 5
        }
        width: id_root.width * 0.2
        height: width
        color: "black"

        Image {
            id: id_img_blackPlayerImage
            source: ""
            anchors.fill: parent
            visible: true
            // fillMode: Image.PreserveAspectFit
        }
    }

    Text {
        id: id_txt_whiteplayer
        anchors.left: id_rec_whiteplayer.right
        anchors.top: id_rec_whiteplayer.top
        anchors.margins: 2
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_whiteplayer_elo
        anchors.left: id_rec_whiteplayer.right
        anchors.top: id_txt_whiteplayer.bottom
        anchors.margins: 2
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "Helvetica"
    }

    Text {
        id: id_txt_whiteplayer_clock
        anchors.right: id_root.right
        anchors.top: id_rec_whiteplayer.top
        anchors.margins: 5
        text: ""
        color: "white"
        font.pointSize: 14
        font.bold: true
        font.family: "DejaVu Sans Mono"
    }

    Rectangle {
        id: id_button
        anchors.top: id_root.top
        anchors.right: id_root.right
        anchors.margins: 5
        width: id_root.width * 0.12
        height: width
        color: "transparent"

        Image {
            source: Qt.resolvedUrl("icon/logo.png")
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // fileDialog.open()

                q_id_chesstable.review()
                q_id_chesstable.drawData()

                if (q_id_chesstable.getBlackStep() === "") {
                    // console.log(q_id_chesstable.getStepNumber() + ": " + q_id_chesstable.getWhiteStep() + " - Clk: " + q_id_chesstable.getWhiteClockTime())
                    id_txt_whiteplayer_clock.text = q_id_chesstable.getWhiteClockTime()
                } else {
                    // console.log(q_id_chesstable.getStepNumber() + ": " + q_id_chesstable.getBlackStep() + " - Clk: " + q_id_chesstable.getBlackClockTime())
                    id_txt_blackplayer_clock.text = q_id_chesstable.getBlackClockTime()
                }
            }
        }
    }
}
