import QtQuick
import QtQuick.Controls

Item {
    id: id_root
    property int itemHeight: parent.height * 0.2
    property int itemWidth: parent.width

    // Model
    ListModel {
        id: id_playerGroup1
    }

    // Delegate
    Component {
        id: id_component

        Item {
            width: id_root.itemWidth
            height: id_root.itemHeight

            Rectangle {
                id: id_player_1
                anchors {
                    left: parent.left
                    top: parent.top
                    bottom: parent.bottom
                    margins: 5
                }
                width: height
                color: "transparent"

                Image {
                    source: Qt.resolvedUrl(player1)
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: id_player_2
                anchors {
                    left: id_player_1.right
                    top: parent.top
                    bottom: parent.bottom
                    margins: 5
                }
                width: height
                color: "transparent"

                Image {
                    source: Qt.resolvedUrl(player2)
                    anchors.fill: parent
                }
            }

            Rectangle {
                id: id_player_3
                anchors {
                    left: id_player_2.right
                    top: parent.top
                    bottom: parent.bottom
                    margins: 5
                }
                width: height
                color: "transparent"

                Image {
                    source: Qt.resolvedUrl(player3)
                    anchors.fill: parent
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
                    model: id_playerGroup1
                    delegate: id_component
                }
            }
        }
    }

    // addItem function to add 1 character to Model
    function addItem(player1, player2, player3) {
        id_playerGroup1.append({"player1": player1, "player2": player2, "player3": player3})
    }

    function clearList() {
        id_playerGroup1.clear()
    }
}
