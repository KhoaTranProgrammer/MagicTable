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

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-26-2022                                               *
 *        Initial version uses MT_DSA_QML to display Simple Sorting *
 * 1.0.1: Aug-04-2022                                               *
 *        Sort the list input of data                               *
 * 1.1.0: Aug-06-2022                                               *
 *        Supports animation time setting                           *
 * 1.1.1: Aug-12-2022                                               *
 *        Add property Features to select sort type from app        *
 * 1.1.2: Oct-22-2022                                               *
 *        Support to select algorithm                               *
 * 1.1.3: Oct-29-2022                                               *
 *        Input data from text                                      *
 * 1.1.4: Nov-11-2022                                               *
 *        Create switch button to select animation                  *
 *******************************************************************/

import QtQuick 2.12
import QtQuick.Controls 1.4
import MT_DSA_QML 1.0

Rectangle {
    id: id_root
    anchors.fill: parent
    color: "black"

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
            font.pointSize: 9
            color: "blue"
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
        color: "blue"

        Rectangle {
            id: id_rec_animation
            anchors {
                top: parent.top
                left: parent.left
                right: parent.right
                margins: 2
            }
            height: 40
            color: "transparent"
            border.width: 1

            Text {
                id: id_txtAnimation
                anchors {
                    top: parent.top
                    left: parent.left
                    leftMargin: 4
                }
                text: "Animation"
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

            Text {
                id: id_txt_executiontime
                anchors {
                    top: parent.top
                    left: parent.left
                    leftMargin: 4
                }
                text: "Execution Time"
                font.pointSize: 10
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
            color: "blue"
            border.width: 1

            Text {
                id: id_txt_sorting
                anchors {
                    top: parent.top
                    left: parent.left
                    leftMargin: 4
                }
                text: "Sort Algorithm"
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
                    if(!id_animationEnabled.checked) {
                        myTable.clearData()
                        myTable.setFeatureSorting(currentText)
                        myTable.createTable(15, 10)
                        myTable.addNewDataList(id_txtdata.text)
                        myTable.sortDataWithMeasurement()
                        myTable.drawData()
                        id_TimerDrawHistory.running = false
                    } else {
                        myTable.clearData()
                        myTable.setFeatureSorting(currentText)
                        myTable.createTable(15, 10)
                        myTable.addNewDataList(id_txtdata.text)
                        myTable.sortDataWithHistory()
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
        interval: 2000; running: false; repeat: true

        onTriggered: {
            myTable.drawHistoryOneByOne()
        }
    }
}
