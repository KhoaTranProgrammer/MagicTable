import QtQuick 2.12
import QtQuick.Controls 1.4
import MT_DSA_QML 1.0

DSAControl {

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

    MT_DSA_QML {
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
        model: id_lstmod_sorting

        onActivated: {
            controlInfor()
            feature = currentText
            execute()
        }
    }

    ListModel {
        id: id_lstmod_sorting
    }

    function execute() {
        if(!isAnimation) {
            myTable.clearData()
            myTable.setFeatureSorting(feature)
            myTable.createTable(columns, rows)
            myTable.addNewDataList(datalist)
            myTable.sortDataWithMeasurement()
            measureTime = myTable.getSortMeasurementData()
            myTable.drawData()
            id_TimerDrawHistory.running = false
            controlMeasureTime()
        } else {
            id_TimerDrawHistory.running = false
            myTable.clearData()
            myTable.setFeatureSorting(feature)
            myTable.createTable(columns, rows)
            myTable.addNewDataList(datalist)
            myTable.sortDataWithHistory()
            myTable.setObjectAnimationTime(elapsetime)
            id_TimerDrawHistory.running = true
        }
    }

    Component.onCompleted: {
        var listofsorting = myTable.getFeatureSorting()
        listofsorting = listofsorting.split("-")
        for (var i = 0; i < listofsorting.length; i++) {
            id_lstmod_sorting.append({"name": listofsorting[i]})
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
