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
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"
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
        id: id_button
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        height: width * 0.2
        color: "transparent"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                // fileDialog.open()

                q_id_chesstable.review()
                q_id_chesstable.drawData()

                if (q_id_chesstable.getBlackStep() === "") {
                    console.log(q_id_chesstable.getStepNumber() + ": " + q_id_chesstable.getWhiteStep() + " - Clk: " + q_id_chesstable.getWhiteClockTime())
                } else {
                    console.log(q_id_chesstable.getStepNumber() + ": " + q_id_chesstable.getBlackStep() + " - Clk: " + q_id_chesstable.getBlackClockTime())
                }
            }
        }
    }
}
