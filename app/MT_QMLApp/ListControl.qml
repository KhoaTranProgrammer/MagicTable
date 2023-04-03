import QtQuick 2.12
import QtQuick.Controls 1.4
import MT_DSA_QML 1.0

DSAControl {

    property int key_remove: 2
    property int key_insertindex: 3
    property int key_insertvalue: 10

    Rectangle {
        id: id_rec_control
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: 40
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

    ComboBox {
        id: id_cmbox_sorting
        anchors {
            top: id_rec_control.top
            left: id_rec_control.left
            bottom: id_rec_control.bottom
            margins: 5
        }
        width: 100
        model: id_lstmod_lists

        onActivated: {
            controlInfor()
            feature = currentText
            execute()
        }
    }

    ListModel {
        id: id_lstmod_lists
    }

    Rectangle {
        id: id_rec_remove
        anchors {
            top: id_rec_control.top
            left: id_cmbox_sorting.right
            bottom: id_rec_control.bottom
            margins: 5
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
            text: "Remove Index"
            onClicked: {
                if (isNaN(id_txtEdit_remove.text)) {
                    console.log(id_txtEdit_remove.text + " is not number")
                } else {
                    key_remove = parseInt(id_txtEdit_remove.text)
                }

                myTable.removeData(key_remove)
                myTable.updateDataLocationInTable()
                if(!isAnimation) {
                    id_TimerDrawHistory.running = false
                    myTable.drawData()
                } else {
                    id_TimerDrawHistory.running = true
                }
                controlMeasureTime()
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
            margins: 5
        }
        width: childrenRect.width + 5
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
            text: "Insert Index"
            onClicked: {
                if (isNaN(id_txtEdit_insertindex.text)) {
                    console.log(id_txtEdit_insertindex.text + " is not number")
                } else {
                    key_insertindex = parseInt(id_txtEdit_insertindex.text)
                }

                if (isNaN(id_txtEdit_insertvalue.text)) {
                    console.log(id_txtEdit_insertvalue.text + " is not number")
                } else {
                    key_insertvalue = parseInt(id_txtEdit_insertvalue.text)
                }

                myTable.insertData(key_insertindex, key_insertvalue)
                myTable.updateDataLocationInverseInTable()
                if(!isAnimation) {
                    id_TimerDrawHistory.running = false
                    myTable.drawData()
                } else {
                    id_TimerDrawHistory.running = true
                }
                controlMeasureTime()
            }
        }

        Rectangle {
            id: id_rec_index
            anchors {
                left: id_txt_insert.right
                top: parent.top
                bottom: parent.bottom
                margins: 2
            }
            width: 25
            TextEdit {
                id: id_txtEdit_insertindex
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                text: key_insertindex
                color: "black"
                focus: true
            }
        }

        Rectangle {
            id: id_rec_value
            anchors {
                left: id_rec_index.right
                top: parent.top
                bottom: parent.bottom
                margins: 2
            }
            width: childrenRect.width
            Text {
                id: id_txt_value
                anchors {
                    left: parent.left
                    verticalCenter: parent.verticalCenter
                    leftMargin: 2
                }
                text: "Value"
                color: "black"
            }
            TextEdit {
                id: id_txtEdit_insertvalue
                anchors {
                    verticalCenter: parent.verticalCenter
                    left: id_txt_value.right
                    leftMargin: 2
                }
                width: 25
                text: key_insertvalue
                color: "blue"
                focus: true
            }
        }

    }

    MT_DSA_QMLList {
        id: myTable
        anchors.fill: id_rec_display

    }

    function execute() {
        if(!isAnimation) {
            myTable.clearData()
            myTable.setFeatureList(feature)
            myTable.createTable(columns, rows)
            myTable.addNewDataList(datalist)
            myTable.updateDataLocationInTable()
            myTable.drawData()
            id_TimerDrawHistory.running = false
            controlMeasureTime()
        } else {
            id_TimerDrawHistory.running = false
            myTable.clearData()
            myTable.setFeatureList(feature)
            myTable.createTable(columns, rows)
            myTable.setObjectAnimationTime(elapsetime)
            myTable.addNewDataList(datalist)
            myTable.updateDataLocationInTable()
            id_TimerDrawHistory.running = true
        }
    }

    Component.onCompleted: {
        var listofsorting = myTable.getFeatureList()
        listofsorting = listofsorting.split("-")
        for (var i = 0; i < listofsorting.length; i++) {
            id_lstmod_lists.append({"name": listofsorting[i]})
        }
    }

    Timer {
        id: id_TimerDrawHistory
        interval: elapsetime; running: false; repeat: true

        onTriggered: {
            myTable.drawHistoryOneByOne(isSaveFile, savefilelocation)
        }
    }
}
