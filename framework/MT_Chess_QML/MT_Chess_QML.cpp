#include "MT_Chess_QML.h"
#include "MT_KingChess.h"
#include <QPainter>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
#include <QDirIterator>

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
    if (this->_FEN == "") {
        // King
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "king", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "king", "white", this->_animationTime)));

        // Queen
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "queen", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "queen", "white", this->_animationTime)));

        // Rook
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "white", this->_animationTime)));

        // Knigh
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "knight", "white", this->_animationTime)));

        // Bishop
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "bishop", "white", this->_animationTime)));

        // Pawn
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "black", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
        this->_mt_chess->addDefaultPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "pawn", "white", this->_animationTime)));
    } else {
        // this->_mt_chess->addPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, "rook", "black")), 0, 0);
        // rkbqnrnb/pppppppp/8/8/8/8/PPPPPPPP/RKBQNRNB

        QStringList FEN_list = this->_FEN.split("/");

        // White piece
        QString white_FEN_down = FEN_list[0];
        for (int i = 0; i < white_FEN_down.size(); i++) {
            string piece_name = getPieceNameFromCharacter(white_FEN_down[i].toLatin1());
            this->_mt_chess->addPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, piece_name, "white", this->_animationTime)), i, 7);
        }
        QString white_FEN_up = FEN_list[1];
        for (int i = 0; i < white_FEN_up.size(); i++) {
            string piece_name = getPieceNameFromCharacter(white_FEN_up[i].toLatin1());
            this->_mt_chess->addPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, piece_name, "white", this->_animationTime)), i, 6);
        }

        // Black piece
        QString black_FEN_down = FEN_list[FEN_list.count() - 1];
        for (int i = 0; i < black_FEN_down.size(); i++) {
            string piece_name = getPieceNameFromCharacter(black_FEN_down[i].toLatin1());
            this->_mt_chess->addPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, piece_name, "black", this->_animationTime)), i, 0);
        }
        QString black_FEN_white = FEN_list[FEN_list.count() - 2];
        for (int i = 0; i < black_FEN_white.size(); i++) {
            string piece_name = getPieceNameFromCharacter(black_FEN_white[i].toLatin1());
            this->_mt_chess->addPiece(*(new MT_Chess_QMLObject(*_mt_engine, *this, piece_name, "black", this->_animationTime)), i, 1);
        }
    }

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
}

string MT_Chess_QML::getPieceNameFromCharacter(char c)
{
    string piece_name = "";
    if (c == 'k' || c == 'K') piece_name="king";
    if (c == 'r' || c == 'R') piece_name="rook";
    if (c == 'b' || c == 'B') piece_name="bishop";
    if (c == 'q' || c == 'Q') piece_name="queen";
    if (c == 'n' || c == 'N') piece_name="knight";
    if (c == 'p' || c == 'P') piece_name="pawn";
    return piece_name;
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

    // Read file line by line
    while (!in.atEnd()) {
        QString oneline = in.readLine();
        line += " ";
        line += oneline;
    }
    line.replace("1-0", "0. Result 1-0");
    line.replace("0-1", "0. Result 0-1");
    line.replace("1/2-1/2", "0. Result 1/2-1/2");
    qDebug() << line;

    file.close();

    this->_mt_chess->addReviewData(line.toStdString());
}

void MT_Chess_QML::readChessPlayerInfor()
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

    // qDebug() << "File content:\n" << fileContent;
    QStringList players_list = fileContent.split("\n");
    for(int i = 0; i < players_list.count(); i++) {
        // qDebug() << players_list[i];
        QString player_name = players_list[i].split(", image: ")[0];
        QString image_link = players_list[i].split(", image: ")[1];

        image_link.remove("}]}");
        image_link.remove("},");
        image_link.remove("}");

        if (player_name.contains(this->_whitePlayer)) this->_whiteImage = image_link;
        if (player_name.contains(this->_blackPlayer)) this->_blackImage = image_link;
    }

    if (!_playerImages.contains(this->_whitePlayer)) {
        qDebug() << "Add image white player";
        _playerImages.insert(this->_whitePlayer, this->_whiteImage);
    }
    if (!_playerImages.contains(this->_blackPlayer)) {
        qDebug() << "Add image black player";
        _playerImages.insert(this->_blackPlayer, this->_blackImage);
    }

    qDebug() << "White Player: " << this->_whitePlayer << " - Image: " << this->_whiteImage;
    qDebug() << "Black Player: " << this->_blackPlayer << " - Image: " << this->_blackImage;
}

void MT_Chess_QML::addReviewDataWithTimeFormat(QString filename)
{
    qDebug() << "Read file: " << filename;
    bool isHeaderComplete = false;
    QString refine_name = filename;
    refine_name.remove("file:///");

    QFile file(refine_name);

    // Try to open the file in read-only text mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cannot open file:" << file.errorString();
    }

    QTextStream in(&file);
    QString line = "";

    // Read file line by line
    while (!in.atEnd()) {
        QString oneline = in.readLine();
        if (isHeaderComplete == false) {
            if (oneline.contains("Event")) {
                this->_information = this->_information + oneline + "\n";
                this->_event = oneline;
                this->_event.remove("[Event \"");
                this->_event.remove("\"]");
            }
            if (oneline.contains("Site")) {};
            if (oneline.contains("Date")) this->_information = this->_information + oneline + "\n";
            if (oneline.contains("Round")) {
                this->_information = this->_information + oneline + "\n";
                this->_round = oneline;
                this->_round.remove("[");
                this->_round.remove("]");
                this->_round.remove("\"");
            }
            if (oneline.contains("White ")) {
                this->_whitePlayer = oneline;
                this->_whitePlayer.remove("[White \"");
                this->_whitePlayer.remove("\"]");
            }
            if (oneline.contains("Black ")) {
                this->_blackPlayer = oneline;
                this->_blackPlayer.remove("[Black \"");
                this->_blackPlayer.remove("\"]");
            }
            if (oneline.contains("WhiteElo ")) {
                this->_whiteElo = oneline;
                this->_whiteElo.remove("[WhiteElo \"");
                this->_whiteElo.remove("\"]");
            }
            if (oneline.contains("BlackElo ")) {
                this->_blackElo = oneline;
                this->_blackElo.remove("[BlackElo \"");
                this->_blackElo.remove("\"]");
            }
            if (oneline.contains("FEN")) {
                //[FEN "rkbqnrnb/pppppppp/8/8/8/8/PPPPPPPP/RKBQNRNB w FAfa - 0 1"]
                this->_FEN = oneline;
                this->_FEN.remove("[FEN \"");
                this->_FEN = this->_FEN.split(" ")[0]; // rkbqnrnb/pppppppp/8/8/8/8/PPPPPPPP/RKBQNRNB
            }
            if (oneline.contains("Result")) {   // [Result "1/2-1/2"]
                QString refine_result = oneline.remove("[Result \"");
                refine_result.remove("\"]");
                this->addResult(refine_result);
            }

            if (oneline == "") isHeaderComplete = true;
        } else {
            if (oneline.contains("Evaluate:")) {
                oneline.remove("Evaluate:");
                this->_mt_chess->addEvaluationData(oneline.toStdString());

                // Add Evaluation Highlight
                this->_mt_chess->addEvaluationHighlight(*(new MT_Chess_QMLEvalObject(*_mt_engine, *this)));
            } else {
                if (oneline != "") {
                    if (line != "") line += " ";
                    line += oneline;
                }
            }
        }
    }
    line.replace("1-0", "0. Result 1-0");
    line.replace("0-1", "0. Result 0-1");
    line.replace("1/2-1/2", "0. Result 1/2-1/2");

    // qDebug() << this->_information;
    // qDebug() << line;

    this->_mt_chess->addReviewDataWithTimeFormat(line.toStdString());

    this->readChessPlayerInfor();
}

void MT_Chess_QML::review()
{
    this->_mt_chess->review();
    if (this->_whitePrison != NULL && this->_blackPrison != NULL) {
        if (this->_mt_chess->getPiecePrisoner() != "" && this->_mt_chess->getColorPrisoner() != "") {
            if (this->_mt_chess->getColorPrisoner() == "white") {
                this->_mt_chess->addPieceToPrison(
                    *(new MT_Chess_QMLObject(*_mt_engine, *this->_whitePrison,
                                             this->_mt_chess->getPiecePrisoner(),
                                             this->_mt_chess->getColorPrisoner(), this->_animationTime)));
                this->_mt_chess->drawWhitePrison();
            }

            if (this->_mt_chess->getColorPrisoner() == "black") {
                this->_mt_chess->addPieceToPrison(
                    *(new MT_Chess_QMLObject(*_mt_engine, *this->_blackPrison,
                                             this->_mt_chess->getPiecePrisoner(),
                                             this->_mt_chess->getColorPrisoner(), this->_animationTime)));
                this->_mt_chess->drawBlackPrison();
            }
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

QString MT_Chess_QML::getWhiteClockTime()
{
    return QString::fromStdString(this->_mt_chess->getWhiteClockTime());
}

QString MT_Chess_QML::getBlackClockTime()
{
    return QString::fromStdString(this->_mt_chess->getBlackClockTime());
}

QString MT_Chess_QML::getWhiteElo()
{
    return this->_whiteElo;
}

QString MT_Chess_QML::getBlackElo()
{
    return this->_blackElo;
}

void MT_Chess_QML::accessPGNFolder(QString folderPath)
{
    qDebug() << folderPath;
    QString refine_folderPath = folderPath;
    refine_folderPath.remove("file:///");
    QDir dir(refine_folderPath);
    QStringList files = dir.entryList(QDir::Files);
    for (const QString &file : files) {
#if defined(Q_OS_ANDROID)
        QString path = dir.filePath(file);
        this->_PGN_files.append(path);
#else
        this->_PGN_files.append(dir.absoluteFilePath(file));
#endif
    }
    readAllPlayersData();
}

QString MT_Chess_QML::getNextPGN()
{
    QString filename = "";
    if (this->_games < this->_PGN_files.count()) {
        filename = this->_PGN_files[this->_games];
        this->_games++;
    }
    return filename;
}

void MT_Chess_QML::reset()
{
    this->_information = "";
    this->_blackPlayer = "";
    this->_whitePlayer = "";
    this->_whiteImage = "";
    this->_blackImage = "";
    this->_whiteElo = "";
    this->_blackElo = "";
    this->_FEN = "";
    this->_winner = "";
    this->_mt_chess->reset();
}

QString MT_Chess_QML::getMoveEval()
{
    return QString::fromStdString(this->_mt_chess->getMoveEval());
}

QString MT_Chess_QML::getEvent()
{
    return this->_event;
}

QString MT_Chess_QML::getRound()
{
    return this->_round;
}

void MT_Chess_QML::addResult(QString result)
{
    qDebug() << "MT_Chess_QML::addResult - " << result;
    QString white_res = result.split("-")[0];
    QString black_res = result.split("-")[1];

    float fl_white_res = 0;
    float fl_black_res = 0;

    if (white_res == "0") fl_white_res = 0;
    if (white_res == "1") fl_white_res = 1;
    if (white_res == "1/2") fl_white_res = 0.5;

    if (black_res == "0") fl_black_res = 0;
    if (black_res == "1") fl_black_res = 1;
    if (black_res == "1/2") fl_black_res = 0.5;

    if (_result.contains(this->_whitePlayer)) {
        _result[this->_whitePlayer] += fl_white_res;
    } else {
        _result.insert(this->_whitePlayer, fl_white_res);
    }

    if (_result.contains(this->_blackPlayer)) {
        _result[this->_blackPlayer] += fl_black_res;
    } else {
        _result.insert(this->_blackPlayer, fl_black_res);
    }
}

QString MT_Chess_QML::getWinner()
{
    QMapIterator<QString, float> i(_result);
    float hightest_score = 0;
    while (i.hasNext()) {
        i.next();
        if (i.value() > hightest_score) {
            hightest_score = i.value();
            _winner = i.key();
        }
    }
    return _winner;
}

QString MT_Chess_QML::getWinnerImage()
{
    return _playerImages[_winner];
}

void MT_Chess_QML::readAllPlayersData()
{
    qDebug() << "MT_Chess_QML::readAllPlayersData()";
    for(int i = 0; i < _PGN_files.count(); i++) {
        qDebug() << _PGN_files[i];
        QString refine_name = _PGN_files[i];
        refine_name.remove("file:///");

        QFile file(refine_name);

        // Try to open the file in read-only text mode
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qCritical() << "Cannot open file:" << file.errorString();
        }

        QTextStream in(&file);
        QString line = "";
        QString whiteP = "";
        QString blackP = "";

        // Read file line by line
        while (!in.atEnd()) {
            QString oneline = in.readLine();
            qDebug() << "DEBUG: " << oneline;
            if (oneline.contains("White ")) {
                oneline.remove("[White \"");
                oneline.remove("\"]");
                whiteP = oneline;
                if (!_allPlayerImages.contains(oneline)) {
                    _allPlayerImages.insert(oneline, "");
                }
            }
            if (oneline.contains("Black ")) {
                oneline.remove("[Black \"");
                oneline.remove("\"]");
                blackP = oneline;
                if (!_allPlayerImages.contains(oneline)) {
                    _allPlayerImages.insert(oneline, "");
                }
            }
            if (oneline.contains("Event")) {
                if (_description != "") {
                    this->_description = oneline;
                    this->_description.remove("[Event \"");
                    this->_description.remove("\"]");
                }
            }
            if (oneline.contains("Round")) {
                if (!_description.contains("Round")) {
                    this->_description = this->_description + "\n" + oneline;
                }
            }

            if (oneline.contains("Result")) {   // [Result "1/2-1/2"]
                QString refine_result = oneline.remove("[Result \"");
                refine_result.remove("\"]");

                QString white_res = refine_result.split("-")[0];
                QString black_res = refine_result.split("-")[1];

                float fl_white_res = 0;
                float fl_black_res = 0;

                if (white_res == "0") fl_white_res = 0;
                if (white_res == "1") fl_white_res = 1;
                if (white_res == "1/2") fl_white_res = 0.5;

                if (black_res == "0") fl_black_res = 0;
                if (black_res == "1") fl_black_res = 1;
                if (black_res == "1/2") fl_black_res = 0.5;

                if (_allPlayerResult.contains(whiteP)) {
                    _allPlayerResult[whiteP] += fl_white_res;
                } else {
                    _allPlayerResult.insert(whiteP, fl_white_res);
                }

                if (_allPlayerResult.contains(blackP)) {
                    _allPlayerResult[blackP] += fl_black_res;
                } else {
                    _allPlayerResult.insert(blackP, fl_black_res);
                }
            }
        }
    }

        // if (i.value() > hightest_score) {
        //     hightest_score = i.value();
        //     _winner = i.key();
        // }

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
        // qDebug() << players_list[i];
        QString player_name = players_list[i].split(", image: ")[0];
        QString image_link = players_list[i].split(", image: ")[1];

        image_link.remove("}]}");
        image_link.remove("},");
        image_link.remove("}");

        QMapIterator<QString, QString> item(_allPlayerImages);
        while (item.hasNext()) {
            item.next();
            if (player_name.contains(item.key())) _allPlayerImages[item.key()] = image_link;
        }
    }

    QMapIterator<QString, float> item(_allPlayerResult);
    float hightest_score = 0;
    while (item.hasNext()) {
        item.next();
        if (item.value() > hightest_score) {
            hightest_score = item.value();
            _champion = item.key();
        }
    }
}

QString MT_Chess_QML::findChampion()
{
    return _allPlayerImages[this->_champion];
}

QString MT_Chess_QML::getNextPlayer()
{
    QString res = "";
    if (this->_currentPlayer < _allPlayerImages.size()) {
        auto it = _allPlayerImages.begin();
        std::advance(it, this->_currentPlayer);
        if (it.key() != this->_champion) {
            res = it.value();
        } else {
            this->_currentPlayer++;
            auto it = _allPlayerImages.begin();
            std::advance(it, this->_currentPlayer);
            res = it.value();
        }
        this->_currentPlayer++;
    }
    return res;
}

int MT_Chess_QML::getNumberOfPlayers()
{
    return _allPlayerResult.count();
}

QString MT_Chess_QML::getDescription()
{
    return _description;
}

QString MT_Chess_QML::readDescriptionFromFile(QString filename)
{
    QString des = "";
    QString refine_name = filename;
    refine_name.remove("file:///");

    QFile file(refine_name);

    // Try to open the file in read-only text mode
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Cannot open file:" << file.errorString();
    }

    QTextStream in(&file);
    QString line = "";

    des = in.readLine();
    // Read file line by line
    while (!in.atEnd()) {
        QString oneline = in.readLine();
        des += "\n" + oneline;
    }
    return des;
}

void MT_Chess_QML::setAnimationTime(int animationtime)
{
    this->_animationTime = animationtime;
}

QString MT_Chess_QML::getEventImage()
{
    QString result = "";
    if (this->getEvent().contains("Titled Tuesday")) {
        result = "Titled_Tuesday.png";
    }
    return result;
}
