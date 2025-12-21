import QtQuick
import QtQuick.Controls

Item {
    id: id_root
    property int itemHeight: parent.height * 0.15
    property int itemWidth: parent.width * 0.9

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
                id: id_rec_round
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    margins: 2
                }
                width: parent.width * 0.4
                color: "transparent"

                Text {
                    anchors.centerIn: id_rec_round
                    color: "white"

                    text: round
                    font.family: "Helvetica"
                    font.pointSize: 10
                }
            }

            Rectangle {
                id: id_rec_whiteplayer
                anchors {
                    left: id_rec_round.right
                    top: id_rec_round.top
                    bottom: id_rec_round.bottom
                    margins: 2
                }
                width: parent.width * 0.3
                color: "transparent"

                Image {
                    id: id_img_whiteplayer
                    source: Qt.resolvedUrl(whiteplayer)
                    anchors {
                        left: parent.left
                        top: parent.top
                        bottom: parent.bottom
                    }
                    width: height
                }

                Image {
                    source: Qt.resolvedUrl("icon/" + whitestatus + ".png")
                    anchors {
                        left: id_img_whiteplayer.right
                        top: parent.top
                        bottom: parent.bottom
                    }
                    width: height
                }
            }

            Rectangle {
                id: id_rec_blackplayer
                anchors {
                    left: id_rec_whiteplayer.right
                    top: id_rec_round.top
                    bottom: id_rec_round.bottom
                    margins: 2
                }
                width: parent.width * 0.3
                color: "transparent"

                Image {
                    id: id_img_blackplayer
                    source: Qt.resolvedUrl(blackplayer)
                    anchors {
                        left: parent.left
                        top: parent.top
                        bottom: parent.bottom
                    }
                    width: height
                }

                Image {
                    source: Qt.resolvedUrl("icon/" + blackstatus + ".png")
                    anchors {
                        left: id_img_blackplayer.right
                        top: parent.top
                        bottom: parent.bottom
                    }
                    width: height
                }
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
    function addItem(round, whiteplayer, whitestatus, blackplayer, blackstatus) {
        id_characterList.append({"round": round, "whiteplayer": whiteplayer, "whitestatus": whitestatus
                                , "blackplayer": blackplayer, "blackstatus": blackstatus})

        // Force scroll to bottom
        // Qt.callLater(() => {
        //     scrollArea.contentItem.contentY = scrollArea.contentItem.contentHeight
        // })
        scrollArea.contentItem.contentY = scrollArea.contentItem.contentHeight
    }

    function clearList() {
        id_characterList.clear()
    }
}
