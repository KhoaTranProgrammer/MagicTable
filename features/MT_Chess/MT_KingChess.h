#ifndef MT_KINGCHESS_H
#define MT_KINGCHESS_H

#include "MT_Chess.h"
#include <iostream>
#include <regex>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

class MT_KingChess : public MT_Chess
{
private:
    vector<MT_Chess_Object*> _listKingChessObjects;
    MT_Chess_Object* _oldPosition = NULL;
    MT_Chess_Object* _newPosition = NULL;
    MT_Chess_Object* _kingPosition = NULL;
    MT_Chess_Object* _evalPosition = NULL;

    // Previous move
    string _prev_Move = "";
    mt_int _prevPositionRow = -1;
    mt_int _prevPositionCol = -1;

    vector<string> splitString(const string& str, char delimiter);
    mt_void castling(string side, string color);
    MT_Chess_Object* findPawnSpecificMove(string piece, string color, MT_Position& pos);
    MT_Chess_Object* findPawnSpecificMove2(string piece, string color, MT_Position& pos, mt_int prev_Col);
    string removeSubString(string larger, string sub);
    mt_int convertStringToSecond(const std::string &timeStr);

public:
    MT_KingChess();

    mt_void addDefaultPiece(MT_Chess_Object& piece);
    mt_void addRemarkPositions(MT_Chess_Object& oldpos, MT_Chess_Object& newpos);
    mt_void addKingHighlight(MT_Chess_Object& kinghighlight);
    mt_void addReviewData(string filename);
    mt_void addReviewDataWithTimeFormat(string input);
    mt_void review();
    mt_bool isGameFinish();
    string getResult();
    MT_Chess_Object* findPieceFromMove(string piece, string color, MT_Position& pos, mt_int prev_Col, mt_int prev_Row);
    vector<MT_Position*> findNextMove(string piece, string color, MT_Position& pos);
    mt_void addEvaluationData(string data);
    mt_void addEvaluationHighlight(MT_Chess_Object& evahighlight);
};

#endif // MT_KINGCHESS_H
