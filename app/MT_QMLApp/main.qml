/*
 * MIT License
 *
 * Copyright (c) 2022 KhoaTran Programmer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/********************************************************************
 * PURPOSE                                                          *
 ********************************************************************
 * This file is the main qml of MT_QMLApp                           *
 *******************************************************************/

import QtQuick 2.12
import QtQuick.Controls 1.4
import Qt.labs.platform 1.1
import "Common.js" as Common

import QtQuick.Window 2.12

Window {
    visible: true
    visibility: "Maximized"

    Rectangle {
        id: id_root
        anchors.fill: parent
        color: "black"

        property int rows: 10
        property int columns: 15
        property var ctx

        Rectangle {
            id: id_inputdata
            anchors {
                left: parent.left
                right: parent.right
                top: parent.top
                margins: 2
            }
            height: parent.height * 0.1

            TextEdit {
                id: id_txtdata
                anchors.fill: parent
                text: "23,12,31,3,15,7,29,88,53"
                color: "black"
                focus: true
            }
        }

        Rectangle {
            id: id_information_area
            anchors {
                left: parent.left
                bottom: parent.bottom
                top: id_inputdata.bottom
            }
            width: parent.width * 0.15
            color: "black"

            Rectangle {
                id: id_rec_tableresolution
                anchors {
                    top: parent.top
                    left: parent.left
                    right: parent.right
                    margins: 2
                }
                height: childrenRect.height + 2
                color: "transparent"
                border.width: 1
                border.color: "white"

                Text {
                    id: id_txt_resolution
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Resolution"
                    color: "white"
                }

                Text
                {
                    id: id_txt_resolution_rows
                    color: "white"
                    text: "Rows"
                    anchors {
                        top: id_txt_resolution.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                }

                TextEdit {
                    id: id_txtEdit_resolution_rows
                    anchors {
                        top: id_txt_resolution.bottom
                        left: id_txt_resolution_rows.right
                        right: parent.right
                        leftMargin: 4
                    }
                    text: id_root.rows
                    color: "white"
                    focus: true
                }

                Text
                {
                    id: id_txt_resolution_cols
                    color: "white"
                    text: "Columns"
                    anchors {
                        top: id_txt_resolution_rows.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                }

                TextEdit {
                    id: id_txtEdit_resolution_cols
                    anchors {
                        top: id_txt_resolution_rows.bottom
                        left: id_txt_resolution_cols.right
                        right: parent.right
                        leftMargin: 4
                    }
                    text: id_root.columns
                    color: "white"
                    focus: true
                }
            }

            Rectangle {
                id: id_rec_animation
                anchors {
                    top: id_rec_tableresolution.bottom
                    left: parent.left
                    right: parent.right
                    margins: 2
                }
                height: childrenRect.height + 2
                color: "transparent"
                border.width: 1
                border.color: "white"

                Text {
                    id: id_txtAnimation
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Animation"
                    color: "white"
                }

                Switch {
                    id: id_animationEnabled
                    anchors {
                        top: id_txtAnimation.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                    checked: false
                }

                Text
                {
                    id: id_txt_elapse
                    color: "white"
                    text: "Elapse (second)"
                    anchors {
                        top: id_animationEnabled.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                }

                TextEdit {
                    id: id_txtEdit_elapse
                    anchors {
                        top: id_txt_elapse.bottom
                        left: parent.left
                        right: parent.right
                        leftMargin: 4
                    }
                    text: "0.5"
                    color: "white"
                    focus: true
                }
            }

            Rectangle {
                id: id_rec_savefile
                anchors {
                    top: id_rec_animation.bottom
                    left: parent.left
                    right: parent.right
                    margins: 2
                }
                height: childrenRect.height + 2
                color: "transparent"
                border.width: 1
                border.color: "white"

                Text {
                    id: id_txt_savefile
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Save File"
                    color: "white"
                }

                Switch {
                    id: id_switch_savefile
                    anchors {
                        top: id_txt_savefile.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                    checked: false
                }

                Text {
                    id: id_txt_location
                    anchors {
                        top: id_switch_savefile.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Location"
                    color: "white"
                }

                Button {
                    anchors {
                        top: id_switch_savefile.bottom
                        left: id_txt_location.right
                        leftMargin: 4
                    }
                    height: id_txt_location.height
                    text: "Select"

                    onClicked: {
                        folderDialog.open()
                    }
                }

                Text {
                    id: id_txt_locationSelected
                    anchors {
                        top: id_txt_location.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                    text: ""
                    color: "white"
                }

            }

            Rectangle {
                id: id_rec_executiontime
                anchors {
                    top: id_rec_savefile.bottom
                    left: parent.left
                    right: parent.right
                    margins: 2
                }
                height: childrenRect.height + 2
                color: "transparent"
                border.width: 1
                border.color: "white"

                Text {
                    id: id_txt_executiontime
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Execution Time"
                    color: "white"
                }

                Text {
                    id: id_txtMeasureTime
                    anchors {
                        top: id_txt_executiontime.bottom
                        left: parent.left
                        leftMargin: 4
                    }
                    text: ""
                    color: "white"
                }
            }

            Rectangle {
                id: id_rec_datastructure
                anchors {
                    right: parent.right
                    left: parent.left
                    top: id_rec_executiontime.bottom
                    margins: 2
                }
                height: childrenRect.height + 2
                color: "black"
                border.width: 1
                border.color: "white"

                Text {
                    id: id_txt_sorting
                    anchors {
                        top: parent.top
                        left: parent.left
                        leftMargin: 4
                    }
                    text: "Data Structure"
                    color: "white"
                }

                ComboBox {
                    id: id_cmbox_dsa
                    anchors {
                        top: id_txt_sorting.bottom
                        left: parent.left
                        right: parent.right
                        margins: 4
                    }
                    model: id_lstmod_dsa

                    onActivated: {
                        for (var i = 0 ; i < Common.group_sorting_algorithm.length; i+=2 ) {
                            if (Common.group_sorting_algorithm[i] === currentText) {
                                console.log(Common.group_sorting_algorithm[i+1])
                                // Setting new control
                                id_loaderControl.source = Common.group_sorting_algorithm[i+1]

                                var scene = null
                                scene = id_loaderControl.item
                                scene.parent = id_root
                                scene.anchors.fill = id_control_area

                                controlInformationUpdate()

                                scene.controlInfor.connect(controlInformationUpdate)
                                scene.controlMeasureTime.connect(updateMeasureTime)
                                scene.controlResolution.connect(updateResolution)
                                scene.execute()
                            }
                        }
                    }
                }
            }
        }

        FolderDialog {
            id: folderDialog

            onAccepted: {
                var path = folderDialog.folder.toString()
                path = path.replace(/^(file:\/{3})/, "")
                id_txt_locationSelected.text = decodeURIComponent(path)
            }
        }

        ListModel {
            id: id_lstmod_dsa
        }

        ListModel {
            id: id_lstmod_tree
        }

        // Using to open control
        Loader {
            id: id_loaderControl
        }

        Item {
            id: id_control_area

            anchors {
                left: id_information_area.right
                right: parent.right
                top: id_inputdata.bottom
                bottom: parent.bottom
            }
        }

        Timer {
            interval: 1000; running: true; repeat: false

            onTriggered: {
                for (var i = 0 ; i < Common.group_sorting_algorithm.length; i+=2 ) {
                    id_lstmod_dsa.append({"name": Common.group_sorting_algorithm[i]})
                }
                id_cmbox_dsa.currentIndex = -1
            }
        }
    }

    function controlInformationUpdate() {
        // Initialize data for new control
        var scene = null
        scene = id_loaderControl.item

        if (isNaN(id_txtEdit_resolution_rows.text)) {
            console.log(id_txtEdit_resolution_rows.text + " is not number")
        } else {
            id_root.rows = parseInt(id_txtEdit_resolution_rows.text)
        }

        if (isNaN(id_txtEdit_resolution_cols.text)) {
            console.log(id_txtEdit_resolution_cols.text + " is not number")
        } else {
            id_root.columns = parseInt(id_txtEdit_resolution_cols.text)
        }

        scene.columns = id_root.columns
        scene.rows = id_root.rows
        scene.datalist = id_txtdata.text
        scene.savefilelocation = id_txt_locationSelected.text
        scene.isSaveFile = id_switch_savefile.checked

        if(!id_animationEnabled.checked) {
            scene.isAnimation = false
        } else {
            scene.isAnimation = true
            if (isNaN(id_txtEdit_elapse.text)) {
                console.log(id_txtEdit_elapse.text + " is not number")
            } else {
                var elapsetime = parseFloat(id_txtEdit_elapse.text) * 1000
                console.log(elapsetime)
                scene.elapsetime = elapsetime
            }
        }
    }

    function updateMeasureTime() {
        var scene = null
        scene = id_loaderControl.item
        id_txtMeasureTime.text = scene.measureTime + " s "
    }

    function updateResolution() {
        var scene = null
        scene = id_loaderControl.item
        id_txtEdit_resolution_rows.text = scene.rows
        id_txtEdit_resolution_cols.text = scene.columns
    }
}
