#ifndef MT_CHESS_QML_H
#define MT_CHESS_QML_H

#include <QQuickItem>
#include <QtQuick/QQuickPaintedItem>
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
#include <iostream>

#include "MT_Chess_QMLObject.h"
#include "MT_Chess_QMLPositionObject.h"
#include "MT_Chess_QMLEvalObject.h"
#include "MT_Chess.h"

class MT_Chess_QML : public QQuickPaintedItem
{
    Q_OBJECT
    QML_ELEMENT
    Q_DISABLE_COPY(MT_Chess_QML)
public:
    MT_Chess_QML(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;
    ~MT_Chess_QML() override;

public slots:
    void createTable(int col, int row);
    void createPieces();
    void drawData();
    void addReviewData(QString filename);
    void addReviewDataWithTimeFormat(QString filename);
    void review();
    bool isGameFinish();
    QString getWhitePlayerName();
    QString getBlackPlayerName();
    QString getResult();
    QString getInformation();
    QString getWhiteImage();
    QString getBlackImage();
    QString getStepNumber();
    QString getWhiteStep();
    QString getBlackStep();
    void setWhitePrison(QQuickItem *item);
    void setBlackPrison(QQuickItem *item);
    QString getWhiteClockTime();
    QString getBlackClockTime();
    QString getWhiteElo();
    QString getBlackElo();
    void accessPGNFolder(QString folderPath);
    QString getNextPGN();
    void reset();
    QString getMoveEval();

private:
    QQmlEngine* _mt_engine;
    MT_Chess* _mt_chess = NULL;
    QString _information = "";
    QString _blackPlayer = "";
    QString _whitePlayer = "";
    QString _whiteImage = "";
    QString _blackImage = "";
    QString _whiteElo = "";
    QString _blackElo = "";
    QQuickItem *_whitePrison = NULL;
    QQuickItem *_blackPrison = NULL;
    QString _FEN = "";
    QStringList _PGN_files;
    int _games = 0;

    void readChessPlayerInfor();
    string getPieceNameFromCharacter(char c);
};

#endif // MT_CHESS_QML_H
