import QtQuick
import QtQuick.Effects
import QtMultimedia
import QtQuick.Controls
import QtQuick.Dialogs
import MT_SummaryTable_QML 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Component.onCompleted: {
        // id_fid_selectpgn.open()
    }

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "transparent"
    }

    MT_SummaryTable_QML {
        id: id_mt_st
        anchors.fill: id_root

        Component.onCompleted: {
            id_mt_st.addTableData("file:///F:/Project/MagicTable/Workspace/MagicTable/build/data/result_table.txt")
            id_mt_st.drawData()
        }
    }

    FileDialog {
        id: id_fid_selectpgn
        title: "Select a File"
        currentFolder: StandardPaths.standardLocations(StandardPaths.DocumentsLocation)[0]
        nameFilters: ["Text files (*.txt)", "All files (*)"]

        onAccepted: {
            console.log(selectedFile)
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

        MouseArea {
            anchors.fill: parent
            onClicked: {
                id_mt_st.getNext()
                id_mt_st.drawData()
            }
        }
    }
}
