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

    // Read first line of event
    QString event = in.readLine();
    event.remove("[Event \"");
    event.remove("\"]");
    this->_description = event + " - Leaderboard";

    // Read file line by line
    while (!in.atEnd()) {
        QString oneline = in.readLine();
        QStringList data_list = oneline.split(",");
        vector<float> points;
        for (int i = 3; i < data_list.count(); i++) {
            if (data_list[i].contains("1/2")) points.push_back(0.5);
            else if (data_list[i].contains("1")) points.push_back(1);
            else points.push_back(0);
        }
        this->_result.insert(data_list[0], points);
        this->_resultTotal.insert(data_list[0], 0);
    }

    // Set total round
    this->_totalRound = this->_result.first().size();

    // Create table
    this->_mttable.createTable((int)this->width(), (int)this->height(), 1, this->_result.count());

    // Read data
    readChessPlayerInfor();

    QMapIterator<QString, vector<float>> i(this->_result);
    int init_pos = 0;
    while (i.hasNext()) {
        i.next();
        MT_SummaryTable_QML_Object* obj = new MT_SummaryTable_QML_Object(*_mt_engine, *this, i.key(), 0,
                                                                         this->_playerImage[i.key()], this->_totalRound);
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

void MT_SummaryTable_QML::getNext()
{
    if (this->_round < this->_result.first().size()) {
        // Get data at current round
        QMapIterator<QString, vector<float>> i(this->_result);

        while (i.hasNext()) {
            i.next();
            this->_resultTotal[i.key()] += i.value().at(this->_round);
            for (int index = 0; index < this->_listObjects.size(); index++) {
                if (this->_listObjects.at(index)->getPlayerName() == i.key())
                    this->_listObjects.at(index)->setPoint(this->_resultTotal[i.key()]);
            }
        }
        this->_round++;
    }

    sortPlayerByPoint();
    for (int index = 0; index < this->_listObjects.size(); index++) {
        this->_mttable.updateObjectPosition(*this->_listObjects.at(index), 0, index);
    }
}

void MT_SummaryTable_QML::sortPlayerByPoint()
{
    // The flag are used for swapping
    bool isSwapped;
    // The number of elements will be sorted. This value will be decreased when complete sort for one element
    mt_int unsortedElements = this->_listObjects.size();
    do
    {
        // This value will be true in case 2 elements need to be swapped
        isSwapped = false;

        // Loop the array's element
        for(mt_int i = 0; i < unsortedElements - 1; ++i)
        {
            if(this->_listObjects.at(i)->getPoint() < this->_listObjects.at(i+1)->getPoint())
            {
                MT_SummaryTable_QML_Object* temp = this->_listObjects.at(i);
                this->_listObjects.at(i) = this->_listObjects.at(i+1);
                this->_listObjects.at(i+1) = temp;
                isSwapped = true;
            }
        }

        --unsortedElements;
    }
    // In case the array is not complete sorted, this value is false
    while(isSwapped);
}

void MT_SummaryTable_QML::readChessPlayerInfor()
{
    // Example: Raw GitHub file URL (must be the "raw" link)
    QUrl url("https://github.com/KhoaTranProgrammer/Common_Topics/blob/main/Chess_Players.json");

    // Network manager for HTTP request
    QNetworkAccessManager manager;
    QNetworkRequest request(url);

    // Send GET request
    QNetworkReply *reply = manager.get(request);

    // Use event loop to wait for the request to finish (synchronous for simplicity)
    QEventLoop loop;
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    // Read file content
    QByteArray data = reply->readAll();
    QString fileContent = QString::fromUtf8(data);

    // Basic split by comma
    fileContent = fileContent.split("rawLines")[1];
    fileContent = fileContent.split("stylingDirectives")[0];
    fileContent.remove('\\');
    fileContent.remove("\"");
    fileContent.replace(":[{,", "{");
    fileContent.replace(":[,", ":[");
    fileContent.replace("},],}],", "}]}");
    fileContent.replace(",,", ",\n");

    reply->deleteLater();

    QStringList players_list = fileContent.split("\n");
    for(int i = 0; i < players_list.count(); i++) {
        QString player_name = players_list[i].split(", image: ")[0];
        QString image_link = players_list[i].split(", image: ")[1];

        player_name.remove("    {name: ");
        image_link.remove("}]}");
        image_link.remove("},");
        image_link.remove("}");

        addImagePlayer(player_name, image_link);
    }
}

void MT_SummaryTable_QML::addImagePlayer(QString player, QString imagelink)
{
    QMapIterator<QString, vector<float>> i(this->_result);

    while (i.hasNext()) {
        i.next();
        // Check if player in list
        bool isAvailable = true;

        QStringList playerinlist;
        if (player.contains(", "))
            playerinlist = player.split(", ");
        else
            playerinlist = player.split(" ");
        for (int l = 0; l < playerinlist.count(); l++) {
            if (!i.key().contains(playerinlist[l])) isAvailable = false;
        }

        if (isAvailable == true) {
            _playerImage.insert(i.key(), imagelink);
            return;
        }
    }
}

QString MT_SummaryTable_QML::getDescription()
{
    return this->_description;
}

int MT_SummaryTable_QML::getRound()
{
    return this->_round;
}

QString MT_SummaryTable_QML::getEventImage()
{
    QString result = "";
    if (this->_description.contains("Titled Tuesday")) {
        result = "Titled_Tuesday.png";
    }
    return result;
}
