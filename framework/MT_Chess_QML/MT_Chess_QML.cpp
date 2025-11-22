#include "MT_Chess_QML.h"
#include "MT_KingChess.h"
#include <QPainter>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MT_Chess_QML::MT_Chess_QML(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()

    // setFlag(ItemHasContents, true);
    this->_mt_engine = new QQmlEngine;

    this->_mt_chess = new MT_KingChess();
    cout << "MT_ChessQML::MT_ChessQML" << endl;
}

void MT_Chess_QML::paint(QPainter *painter)
{

}

MT_Chess_QML::~MT_Chess_QML() {}

void MT_Chess_QML::createTable(int col, int row)
{
    if ((int)this->width() > (int)this->height())
    {
        this->_mt_chess->createTable((int)this->height(), (int)this->height(), col, row);
    }
    else
    {
        this->_mt_chess->createTable((int)this->width(), (int)this->width(), col, row);
    }
}

void MT_Chess_QML::createPieces()
{
    // King
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "king", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "king", "white")));

    // Queen
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "queen", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "queen", "white")));

    // Rook
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "white")));

    // Knigh
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "white")));

    // Bishop
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "white")));

    // Pawn
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));
    this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white")));

    // Add Remark Positions
    this->_mt_chess->addRemarkPositions(*(new MT_Chess_QMLPositionObject(*_mt_engine, *this)),
                                        *(new MT_Chess_QMLPositionObject(*_mt_engine, *this)));

    // Add King Highlight
    this->_mt_chess->addKingHighlight(*(new MT_Chess_QMLPositionObject(*_mt_engine, *this)));
}

void MT_Chess_QML::drawData()
{
    if (this->_mt_chess != NULL)
        this->_mt_chess->drawData();
    cout << "MT_Chess_QML::drawData" << endl;
}

void MT_Chess_QML::addReviewData(QString filename)
{
    QString refine_name = filename;
    refine_name.remove("file:///");

    QFile file(refine_name);

    // Try to open the file in read-only text mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cannot open file:" << file.errorString();
    }

    QTextStream in(&file);
    // in.setCodec("UTF-8"); // Ensure correct encoding

    // Read file line by line
    // while (!in.atEnd()) {
    //     QString line = in.readLine();
    //     qDebug() << line;
    // }

    QString line = in.readLine(); // Read event
    this->_information = line + "\n";
    line = in.readLine(); // Read site
    this->_information += line + "\n";
    line = in.readLine(); // Read Date
    this->_information += line + "\n";
    line = in.readLine(); // Read Round
    this->_information += line + "\n";

    line = in.readLine(); // Read White
    line.remove("[White \"");
    line.remove("\"]");
    this->_whitePlayer = line;

    line = in.readLine(); // Read Black
    line.remove("[Black \"");
    line.remove("\"]");
    this->_blackPlayer = line;

    line = in.readLine(); // Read Result
    line = in.readLine(); // Read TimeControl
    line = in.readLine(); // Read Link

    // Read white image link
    this->_whiteImage = in.readLine();
    // Read black image link
    this->_blackImage = in.readLine();

    line = in.readLine(); // Read empty line
    line = in.readLine(); // Read steps

    file.close();

    this->_mt_chess->addReviewData(line.toStdString());
}

void MT_Chess_QML::review()
{
    this->_mt_chess->review();
    if (this->_mt_chess->getPiecePrisoner() != "" && this->_mt_chess->getColorPrisoner() != "") {
        if (this->_mt_chess->getColorPrisoner() == "white") {
            this->_mt_chess->addPieceToPrison(
                *(new MT_Chess_QMLObject(*_mt_engine, *this->_whitePrison,
                                         this->_mt_chess->getPiecePrisoner(),
                                         this->_mt_chess->getColorPrisoner())));
            this->_mt_chess->drawWhitePrison();
        }

        if (this->_mt_chess->getColorPrisoner() == "black") {
            this->_mt_chess->addPieceToPrison(
                *(new MT_Chess_QMLObject(*_mt_engine, *this->_blackPrison,
                                         this->_mt_chess->getPiecePrisoner(),
                                         this->_mt_chess->getColorPrisoner())));
            this->_mt_chess->drawBlackPrison();
        }
    }
}

bool MT_Chess_QML::isGameFinish()
{
    return this->_mt_chess->isGameFinish();
}

QString MT_Chess_QML::getWhitePlayerName()
{
    return this->_whitePlayer;
}

QString MT_Chess_QML::getBlackPlayerName()
{
    return this->_blackPlayer;
}

QString MT_Chess_QML::getResult()
{
    return QString::fromStdString(this->_mt_chess->getResult());
}

QString MT_Chess_QML::getInformation()
{
    return this->_information;
}

QString MT_Chess_QML::getWhiteImage()
{
    return this->_whiteImage;
}

QString MT_Chess_QML::getBlackImage()
{
    return this->_blackImage;
}

QString MT_Chess_QML::getStepNumber()
{
    return QString::number(this->_mt_chess->getStepNumber());
}

QString MT_Chess_QML::getWhiteStep()
{
    return QString::fromStdString(this->_mt_chess->getWhiteStep());
}

QString MT_Chess_QML::getBlackStep()
{
    return QString::fromStdString(this->_mt_chess->getBlackStep());
}

void MT_Chess_QML::setWhitePrison(QQuickItem *item)
{
    this->_mt_chess->createWhitePrisonTable((int)item->width(), (int)item->height(), 8, 2);
    this->_whitePrison = item;
}

void MT_Chess_QML::setBlackPrison(QQuickItem *item)
{
    this->_mt_chess->createBlackPrisonTable((int)item->width(), (int)item->height(), 8, 2);
    this->_blackPrison = item;
}
