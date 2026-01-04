#ifndef MT_SUMMARYTABLE_QML_H
#define MT_SUMMARYTABLE_QML_H

#include <QtQuick/QQuickPaintedItem>
#include <QQuickItem>
#include <QColor>
#include <QPainter>
#include <QQuickItemGrabResult>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QTextStream>
#include <QObject>
#include <QQmlComponent>
#include <QQmlEngine>

#include "MT_Table.h"
#include "MT_SummaryTable_QML_Object.h"

using namespace std;

class MT_SummaryTable_QML : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(MT_SummaryTable_QML)
public:
    MT_SummaryTable_QML(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~MT_SummaryTable_QML() override;

public slots:
    void addTableData(QString filename);
    void drawData();

private:
    QQmlEngine* _mt_engine;
    MT_Table _mttable;
    vector<MT_SummaryTable_QML_Object*> _listObjects;

    // Store database read from file
    QMap<QString, vector<float>> _result;
};

#endif // MT_SUMMARYTABLE_QML_H
