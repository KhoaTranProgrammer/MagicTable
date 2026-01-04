#include <QFile>
#include <QPainter>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QDirIterator>

#include "MT_SummaryTable_QML.h"
#include "MT_SummaryTable_QML_Object.h"

MT_SummaryTable_QML::MT_SummaryTable_QML(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
    this->_mt_engine = new QQmlEngine;
}

void MT_SummaryTable_QML::paint(QPainter *painter)
{

}

MT_SummaryTable_QML::~MT_SummaryTable_QML() {}

void MT_SummaryTable_QML::addTableData(QString filename)
{
    qDebug() << "MT_SummaryTable_QML::addTableData - " << filename;
    QString refine_name = filename;
    refine_name.remove("file:///");

    QFile file(refine_name);
    // Try to open the file in read-only text mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cannot open file:" << file.errorString();
    }

    QTextStream in(&file);

    // Read file line by line
    while (!in.atEnd()) {
        QString oneline = in.readLine();
        // qDebug() << oneline;
        QStringList data_list = oneline.split(",");
        vector<float> points;
        for (int i = 3; i < data_list.count(); i++) {
            if (data_list[i].contains("1/2")) points.push_back(0.5);
            else if (data_list[i].contains("1")) points.push_back(1);
            else points.push_back(0);
        }
        this->_result.insert(data_list[0], points);
        qDebug() << data_list[0] << " - " << this->_result[data_list[0]];
    }

    // Create table
    this->_mttable.createTable((int)this->width(), (int)this->height(), 1, this->_result.count());

    QMapIterator<QString, vector<float>> i(this->_result);
    int init_pos = 0;
    while (i.hasNext()) {
        i.next();
        MT_SummaryTable_QML_Object* obj = new MT_SummaryTable_QML_Object(*_mt_engine, *this, i.key(), i.value().at(0));
        this->_mttable.addObject(*obj);
        this->_listObjects.push_back(obj);
        this->_mttable.updateObjectPosition(*obj, 0, init_pos);
        init_pos++;
    }
}

void MT_SummaryTable_QML::drawData()
{
    this->_mttable.drawObjects();
}
