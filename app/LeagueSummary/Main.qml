import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_SummaryTable_QML 1.0

Window {
    width: 720 / 2
    height: 1280 / 2
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: {
        id_fid_selectpgn.open()
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"

        Background {
            anchors.fill: parent
        }
    }

    MT_SummaryTable_QML {
        id: id_mt_st
        anchors {
            left: id_root.left
            right: id_root.right
            verticalCenter: id_root.verticalCenter
        }
        height: id_root.height * 0.7

        Component.onCompleted: {

        }
    }

    Text {
        id: id_txt_infor
        anchors.bottom: id_mt_st.top
        anchors.left: id_root.left
        anchors.right: id_root.right
        anchors.margins: 2
        text: ""
        color: "yellow"
        font.pointSize: 20
        font.bold: true
        wrapMode: Text.WordWrap
    }

    Text {
        id: id_txt_round
        anchors.top: id_mt_st.bottom
        anchors.right: id_root.right
        anchors.margins: 2
        text: ""
        color: "yellow"
        font.pointSize: 20
        font.bold: true
        wrapMode: Text.WordWrap
    }

    FileDialog {
        id: id_fid_selectpgn
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.txt)", "All files (*)"]

        onAccepted: {
            console.log(selectedFile)
            id_mt_st.addTableData(selectedFile)
            id_mt_st.drawData()
            id_txt_infor.text = id_mt_st.getDescription()
        }
    }

    Rectangle {
        anchors {
            right: id_root.right
            top: id_table.top
            margins: 10
        }
        width: 50
        height: width
        color: "transparent"

        Image {
            source: Qt.resolvedUrl("icon/logo.png")
            anchors.fill: parent
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_tim_execution.running = true
            }
        }
    }

    Timer {
        id: id_tim_execution
        interval: 2000; running: false; repeat: true

        onTriggered: {
            id_mt_st.getNext()
            id_mt_st.drawData()
            id_txt_round.text = "Round: " + id_mt_st.getRound()
        }
    }
}
