import QtQuick 2.12
import QtQuick.Controls 1.4

Item {
    property int columns: 0
    property int rows: 0
    property string feature: ""
    property string datalist: ""
    property double elapsetime
    property bool isAnimation: false
    property double measureTime: 0.0

    // Signal to announce when control information are updated
    signal controlInfor
    signal controlMeasureTime
    signal controlResolution
}
