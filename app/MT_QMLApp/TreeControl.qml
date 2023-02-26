import QtQuick 2.0
import QtQuick.Controls 1.4
import MT_DSA_QML 1.0

DSAControl {

    property int key_remove: 15
    property int key_insert: 50

    Rectangle {
        id: id_rec_control
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: 30
        color: "transparent"
    }

    Rectangle {
        id: id_rec_display
        anchors {
            left: parent.left
            right: parent.right
            top: id_rec_control.bottom
            bottom: parent.bottom
        }
        color: "transparent"
    }

    MT_DSA_QMLTree {
        id: myTable
        anchors.fill: id_rec_display
    }

    ComboBox {
        id: id_cmbox_sorting
        anchors {
            top: id_rec_control.top
            left: id_rec_control.left
            bottom: id_rec_control.bottom
        }
        width: 100
        model: id_lstmod_tree

        onActivated: {
            controlInfor()
            feature = currentText
            execute()
        }
    }

    Rectangle {
        id: id_rec_remove
        anchors {
            top: id_rec_control.top
            left: id_cmbox_sorting.right
            bottom: id_rec_control.bottom
            margins: 2
        }
        width: 100
        color: "transparent"
        border.width: 1
        border.color: "white"

        Button {
            id: id_txt_remove
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                margins: 2
            }
            text: "Remove"
            onClicked: {
                if (isNaN(id_txtEdit_remove.text)) {
                    console.log(id_txtEdit_remove.text + " is not number")
                } else {
                    key_remove = parseInt(id_txtEdit_remove.text)
                }

                myTable.Remove(key_remove)
                rows = myTable.getHeight()
                columns = myTable.getColumn()
                controlResolution()
                if(!isAnimation) {
                    id_TimerDrawHistory.running = false
                    myTable.drawData()
                } else {
                    id_TimerDrawHistory.running = true
                }
            }
        }

        Rectangle {
            anchors {
                left: id_txt_remove.right
                top: parent.top
                bottom: parent.bottom
                right: parent.right
                margins: 2
            }
            TextEdit {
                id: id_txtEdit_remove
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: key_remove
                font.pointSize: 10
                color: "black"
                focus: true
            }
        }

    }

    Rectangle {
        id: id_rec_insert
        anchors {
            top: id_rec_control.top
            left: id_rec_remove.right
            bottom: id_rec_control.bottom
            margins: 2
        }
        width: 100
        color: "transparent"
        border.width: 1
        border.color: "white"

        Button {
            id: id_txt_insert
            anchors {
                left: parent.left
                verticalCenter: parent.verticalCenter
                margins: 2
            }
            text: "Insert"
            onClicked: {
                if (isNaN(id_txtEdit_insert.text)) {
                    console.log(id_txtEdit_insert.text + " is not number")
                } else {
                    key_insert = parseInt(id_txtEdit_insert.text)
                }

                myTable.insertData(key_insert)
                rows = myTable.getHeight()
                columns = myTable.getColumn()
                controlResolution()
                if(!isAnimation) {
                    id_TimerDrawHistory.running = false
                    myTable.drawData()
                } else {
                    id_TimerDrawHistory.running = true
                }
            }
        }

        Rectangle {
            anchors {
                left: id_txt_insert.right
                top: parent.top
                bottom: parent.bottom
                right: parent.right
                margins: 2
            }
            TextEdit {
                id: id_txtEdit_insert
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: key_insert
                font.pointSize: 10
                color: "black"
                focus: true
            }
        }

    }

    ListModel {
        id: id_lstmod_tree
    }

    function execute() {
        if(!isAnimation) {
            myTable.clearData()
            myTable.setFeatureTree(feature)
            myTable.createTable(columns, rows)
            myTable.insertNewDataList(datalist)
            myTable.drawData()
            id_TimerDrawHistory.running = false
            rows = myTable.getHeight()
            columns = myTable.getColumn()
            controlResolution()
        } else {
            id_TimerDrawHistory.running = false
            myTable.setFeatureTree(feature)
            myTable.createTable(columns, rows)
            myTable.setObjectAnimationTime(elapsetime)
            myTable.insertNewDataList(datalist)
            id_TimerDrawHistory.running = true
        }
    }

    Component.onCompleted: {
        var listoftree = myTable.getFeatureHierarchicalTree()
        listoftree = listoftree.split("-")
        for (var i = 0; i < listoftree.length; i++) {
            id_lstmod_tree.append({"name": listoftree[i]})
        }
    }

    Timer {
        id: id_TimerDrawHistory
        interval: elapsetime; running: false; repeat: true

        onTriggered: {
            myTable.drawHistoryOneByOne()
        }
    }
}
