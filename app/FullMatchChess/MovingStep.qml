import QtQuick
import QtQuick.Controls

Item {
    id: id_root
    property int itemHeight: parent.height * 0.1
    property int itemWidth: parent.width * 0.8

    // Model
    ListModel {
        id: id_characterList
    }

    // Delegate
    Component {
        id: id_component

        Item {
            width: id_root.itemWidth
            height: id_root.itemHeight

            Rectangle {
                id: id_step
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    margins: 2
                }
                width: parent.width * 0.2
                color: "#8EA6B4"
            }
            Text {
                anchors.centerIn: id_step
                color: "black"

                text: step
                font.family: "Helvetica"
                font.pointSize: 12
            }

            Rectangle {
                id: id_whitemove
                anchors {
                    left: id_step.right
                    top: parent.top
                    bottom: parent.bottom
                    margins: 2
                }
                width: parent.width * 0.4
                color: "#8EA6B4"
            }
            Text {
                anchors.centerIn: id_whitemove
                color: "white"

                text: whitemove
                font.family: "Helvetica"
                font.pointSize: 10
            }
            Image {
                source: Qt.resolvedUrl("icon/" + whiteeval + ".png")
                anchors {
                    top: id_whitemove.top
                    right: id_whitemove.right
                }
                height: id_whitemove.height * 0.5
                width: height
            }

            Rectangle {
                id: id_blackmove
                anchors {
                    left: id_whitemove.right
                    top: parent.top
                    bottom: parent.bottom
                    margins: 2
                }
                width: parent.width * 0.4
                color: "#8EA6B4"
            }
            Text {
                anchors.centerIn: id_blackmove
                color: "black"

                text: blackmove
                font.family: "Helvetica"
                font.pointSize: 10
            }
            Image {
                source: Qt.resolvedUrl("icon/" + blackeval + ".png")
                anchors {
                    top: id_blackmove.top
                    right: id_blackmove.right
                }
                height: id_blackmove.height * 0.5
                width: height
            }
        }
    }

    // Model and delegate will be combined inside Flickable
    Flickable {
        id: id_flickable
        anchors.fill: id_root
        contentHeight: id_root.height
        contentWidth: id_root.width

        ScrollView {
            id: scrollArea
            anchors.fill: parent

            Column {
                id: layout
                anchors.fill: parent
                Repeater {
                    model: id_characterList
                    delegate: id_component
                }
            }
        }
    }

    // addItem function to add 1 character to Model
    function addItem(step, whitemove, whiteeval, blackmove, blackeval) {
        id_characterList.append({"step": step, "whitemove": whitemove, "whiteeval": whiteeval, "blackmove": blackmove, "blackeval": blackeval})

        // Force scroll to bottom
        // Qt.callLater(() => {
        //     scrollArea.contentItem.contentY = scrollArea.contentItem.contentHeight
        // })
        scrollArea.contentItem.contentY = scrollArea.contentItem.contentHeight
    }

    function updateItem(step, whitemove, whiteeval, blackmove, blackeval) {
        id_characterList.remove(id_characterList.count - 1, 1)
        id_characterList.append({"step": step, "whitemove": whitemove, "whiteeval": whiteeval, "blackmove": blackmove, "blackeval": blackeval})

        // Force scroll to bottom
        // Qt.callLater(() => {
        //     scrollArea.contentItem.contentY = scrollArea.contentItem.contentHeight
        // })
    }

    function clearList() {
        id_characterList.clear()
    }
}
