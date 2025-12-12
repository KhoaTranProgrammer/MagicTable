#ifndef MT_CHESS_H
#define MT_CHESS_H

#include "MT_Table.h"
#include "MT_Chess_Object.h"

#if defined(Q_OS_WIN)
#include <bits/stdc++.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class MT_Chess
{
protected:
    MT_Table _mttable;
    MT_Table _mttableWhitePrison;
    MT_Table _mttableBlackPrison;
    vector<MT_RefObject*> _move_steps; // This is used for review feature
    vector<string> _move_steps_in_PGN;
    vector<string> _time_clock;
    mt_bool isFinished = false;
    string _result = "draw";
    mt_int _stepNumber = 0;
    string _whiteStep = "";
    string _whiteClockTime = "";
    string _blackStep = "";
    string _blackClockTime = "";

    // Use for prisoner
    string _piecePrisoner = "";
    string _colorPrisoner = "";

public:
    MT_Chess();

    mt_void createTable(int w, int h, int col, int row);
    mt_void createWhitePrisonTable(int w, int h, int col, int row);
    mt_void createBlackPrisonTable(int w, int h, int col, int row);
    mt_void addPieceToPrison(MT_Chess_Object& piece);
    mt_void drawWhitePrison();
    mt_void drawBlackPrison();
    mt_void drawData();
    mt_int getStepNumber();
    string getWhiteStep();
    string getBlackStep();
    string getPiecePrisoner();
    string getColorPrisoner();
    string getWhiteClockTime();
    string getBlackClockTime();

    virtual mt_void addDefaultPiece(MT_Chess_Object& piece);
    virtual mt_void addReviewData(string filename);
    virtual mt_void addReviewDataWithTimeFormat(string input);
    virtual mt_void review();
    virtual mt_bool isGameFinish();
    virtual string getResult();
    virtual mt_void addRemarkPositions(MT_Chess_Object& oldpos, MT_Chess_Object& newpos);
    virtual mt_void addKingHighlight(MT_Chess_Object& kinghighlight);
    virtual MT_Chess_Object* findPieceFromMove(string piece, string color, MT_Position& pos, mt_int prev_Col, mt_int prev_Row);
    virtual vector<MT_Position*> findNextMove(string piece, string color, MT_Position& pos);
};

#endif // MT_CHESS_H
