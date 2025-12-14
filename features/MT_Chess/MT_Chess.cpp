#include "MT_Chess.h"

MT_Chess::MT_Chess() {}

mt_void MT_Chess::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

mt_void MT_Chess::createWhitePrisonTable(int w, int h, int col, int row)
{
    this->_mttableWhitePrison.createTable(w, h, col, row);
}

mt_void MT_Chess::createBlackPrisonTable(int w, int h, int col, int row)
{
    this->_mttableBlackPrison.createTable(w, h, col, row);
}

mt_void MT_Chess::addPieceToPrison(MT_Chess_Object& piece)
{
    if (piece.getColor() == "white") {
        this->_mttableWhitePrison.addObject(piece);
        for (int i = 0; i < this->_mttableWhitePrison.getRow(); i++) {
            for (int j = 0; j < this->_mttableWhitePrison.getCol(); j++) {
                MT_Position* objpos = this->_mttableWhitePrison.getPositionAt(j, i);
                if (this->_mttableWhitePrison.checkFreePosition(*objpos))
                {
                    this->_mttableWhitePrison.updateObjectPosition(piece, j, i);
                    return;
                }
            }
        }
    }

    if (piece.getColor() == "black") {
        this->_mttableBlackPrison.addObject(piece);
        for (int i = 0; i < this->_mttableBlackPrison.getRow(); i++) {
            for (int j = 0; j < this->_mttableBlackPrison.getCol(); j++) {
                MT_Position* objpos = this->_mttableBlackPrison.getPositionAt(j, i);
                if (this->_mttableBlackPrison.checkFreePosition(*objpos))
                {
                    this->_mttableBlackPrison.updateObjectPosition(piece, j, i);
                    return;
                }
            }
        }
    }
}

mt_void MT_Chess::drawWhitePrison()
{
    this->_mttableWhitePrison.drawObjects();
}

mt_void MT_Chess::drawBlackPrison()
{
    this->_mttableBlackPrison.drawObjects();
}

string MT_Chess::getPiecePrisoner()
{
    return this->_piecePrisoner;
}

string MT_Chess::getColorPrisoner()
{
    return this->_colorPrisoner;
}

mt_void MT_Chess::drawData()
{
    this->_mttable.drawObjects();
}

mt_void MT_Chess::addDefaultPiece(MT_Chess_Object& piece)
{

}

mt_void MT_Chess::addReviewData(string filename)
{

}

mt_void MT_Chess::addReviewDataWithTimeFormat(string input)
{

}

mt_void MT_Chess::addEvaluationData(string data)
{

}

mt_void MT_Chess::addRemarkPositions(MT_Chess_Object& oldpos, MT_Chess_Object& newpos)
{

}

mt_void MT_Chess::addKingHighlight(MT_Chess_Object& kinghighlight)
{

}

mt_void MT_Chess::review()
{

}

mt_bool MT_Chess::isGameFinish()
{

}

string MT_Chess::getResult()
{

}

MT_Chess_Object* MT_Chess::findPieceFromMove(string piece, string color, MT_Position& pos, mt_int prev_Col, mt_int prev_Row)
{

}

vector<MT_Position*> MT_Chess::findNextMove(string piece, string color, MT_Position& pos)
{

}

mt_int MT_Chess::getStepNumber()
{
    return this->_stepNumber;
}

string MT_Chess::getWhiteStep()
{
    string result = this->_whiteStep;
    return result.erase(0, 1);
}

string MT_Chess::getBlackStep()
{
    string result = this->_blackStep;
    return result.erase(0, 1);
}

string MT_Chess::getWhiteClockTime()
{
    return this->_whiteClockTime;
}

string MT_Chess::getBlackClockTime()
{
    return this->_blackClockTime;
}

mt_void MT_Chess::addEvaluationHighlight(MT_Chess_Object& evahighlight)
{

}
