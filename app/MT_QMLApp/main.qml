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
 * 1.1.2: OCt-22-2022                                               *
 *        Support to select algorithm                               *
 *******************************************************************/

import QtQuick 2.12
import QtQuick.Controls 1.4
import MT_DSA_QML 1.0

Rectangle {
    id: id_root
    anchors.fill: parent
    color: "black"

    property var arr: [7, 5, 9, 1, 31, 23, 14, 2, 9, 33, 0, 99, 3]

    Rectangle {
        id: id_rec_optionarea
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: parent.height * 0.1

        Rectangle {
            id: id_rec_sorting
            anchors {
                right: parent.right
                top: parent.top
                bottom: parent.bottom
            }
            width: parent.width * 0.2
            color: "blue"
            ComboBox {
                anchors.fill: parent
                model: id_lstmod_sorting

                onActivated: {
                    console.log(currentText)
                    myTable.clearData()
                    myTable.setFeatureSorting(currentText)
                    myTable.createTable(10, 10)
                    myTable.addNewDataList("90,20,30,1")
                    myTable.sortDataWithMeasurement();
                    myTable.drawData()
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
            left: parent.left
            right: parent.right
            top: id_rec_optionarea.bottom
            bottom: parent.bottom
        }

        Component.onCompleted: {
            myTable.setObjectAnimationTime(900)
        }
    }

    Timer {
        interval: 1000; running: true; repeat: false

        onTriggered: {
            myTable.createTable(10, 10)
            myTable.addNewDataList("25,21,12,40,37,43,14,28")
            myTable.sortDataWithMeasurement()
            myTable.drawData()
            var listofsorting = myTable.getFeatureSorting()
            listofsorting = listofsorting.split("-")
            for (var i = 0; i < listofsorting.length; i++) {
                id_lstmod_sorting.append({"name": listofsorting[i]})
            }
        }
    }
}
