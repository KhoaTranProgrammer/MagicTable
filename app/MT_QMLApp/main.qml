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
import MT_DSA_QML 1.0

Rectangle {
    id: id_root
    anchors.fill: parent
    color: "black"

    property int rows: 10
    property int columns: 15

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
            text: "7,5,9,1,31,23,14,2,9,33,0,99,3"
            font.pointSize: 10
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
            height: 50
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
                font.pointSize: 10
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
                font.pointSize: 10
            }

            TextEdit {
                id: id_txtEdit_resolution_rows
                anchors {
                    top: id_txt_resolution.bottom
                    left: id_txt_resolution_rows.right
                    bottom: parent.bottom
                    right: parent.right
                    leftMargin: 4
                }
                text: id_root.rows
                font.pointSize: 10
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
                font.pointSize: 10
            }

            TextEdit {
                id: id_txtEdit_resolution_cols
                anchors {
                    top: id_txt_resolution_rows.bottom
                    left: id_txt_resolution_cols.right
                    bottom: parent.bottom
                    right: parent.right
                    leftMargin: 4
                }
                text: id_root.columns
                font.pointSize: 10
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
            height: 70
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
                font.pointSize: 10
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
                font.pointSize: 10
            }

            TextEdit {
                id: id_txtEdit_elapse
                anchors {
                    top: id_txt_elapse.bottom
                    left: parent.left
                    bottom: parent.bottom
                    right: parent.right
                    leftMargin: 4
                }
                text: "0.9"
                font.pointSize: 10
                color: "white"
                focus: true
            }
        }

        Rectangle {
            id: id_rec_executiontime
            anchors {
                top: id_rec_animation.bottom
                left: parent.left
                right: parent.right
                margins: 2
            }
            height: 40
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
                font.pointSize: 10
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
                font.pointSize: 10
                color: "white"
            }
        }

        Rectangle {
            id: id_rec_sorting
            anchors {
                right: parent.right
                left: parent.left
                top: id_rec_executiontime.bottom
                margins: 2
            }
            height: 50
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
                text: "Sort Algorithm"
                color: "white"
                font.pointSize: 10
            }

            ComboBox {
                anchors {
                    top: id_txt_sorting.bottom
                    left: parent.left
                    right: parent.right
                    bottom: parent.bottom
                    margins: 4
                }
                model: id_lstmod_sorting

                onActivated: {
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

                    if(!id_animationEnabled.checked) {
                        myTable.clearData()
                        myTable.setFeatureSorting(currentText)
                        myTable.createTable(id_root.columns, id_root.rows)
                        myTable.addNewDataList(id_txtdata.text)
                        myTable.sortDataWithMeasurement()
                        myTable.drawData()
                        id_TimerDrawHistory.running = false
                    } else {
                        id_TimerDrawHistory.running = false
                        myTable.clearData()
                        myTable.setFeatureSorting(currentText)
                        myTable.createTable(id_root.columns, id_root.rows)
                        myTable.addNewDataList(id_txtdata.text)
                        myTable.sortDataWithHistory()

                        if (isNaN(id_txtEdit_elapse.text)) {
                            console.log(id_txtEdit_elapse.text + " is not number")
                        } else {
                            var elapsetime = parseFloat(id_txtEdit_elapse.text) * 1000
                            console.log(elapsetime)
                            id_TimerDrawHistory.interval = elapsetime
                            myTable.setObjectAnimationTime(elapsetime)
                        }

                        id_TimerDrawHistory.running = true
                    }
                }
            }
        }
    }

    ListModel {
        id: id_lstmod_sorting
    }

    MT_DSA_QML {
        id: myTable
        anchors {
            left: id_information_area.right
            right: parent.right
            top: id_inputdata.bottom
            bottom: parent.bottom
        }

        Component.onCompleted: {
            myTable.setObjectAnimationTime(900)
        }
    }

    Timer {
        interval: 1000; running: true; repeat: false

        onTriggered: {
            myTable.clearData()
            myTable.createTable(15, 10)
            myTable.addNewDataList(id_txtdata.text)
            myTable.sortDataWithMeasurement()
            id_txtMeasureTime.text = myTable.getSortMeasurementData() + " s "
            myTable.drawData()
            var listofsorting = myTable.getFeatureSorting()
            listofsorting = listofsorting.split("-")
            for (var i = 0; i < listofsorting.length; i++) {
                id_lstmod_sorting.append({"name": listofsorting[i]})
            }
        }
    }

    Timer {
        id: id_TimerDrawHistory
        interval: 900; running: false; repeat: true

        onTriggered: {
            myTable.drawHistoryOneByOne()
        }
    }
}
