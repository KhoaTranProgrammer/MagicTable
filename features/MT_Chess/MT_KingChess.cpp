#include "MT_KingChess.h"

mt_int getColumnNumber(char numinchar)
{
    switch (numinchar)
    {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default: return -1;
    }
}

mt_int getRowNumber(char numinchar)
{
    switch (numinchar)
    {
        case '8': return 0;
        case '7': return 1;
        case '6': return 2;
        case '5': return 3;
        case '4': return 4;
        case '3': return 5;
        case '2': return 6;
        case '1': return 7;
        default: return -1;
    }
}

MT_KingChess::MT_KingChess() {}

vector<string> MT_KingChess::splitString(const string& str, char delimiter)
{
    vector<string> tokens;
    size_t start = 0, end;

    while ((end = str.find(delimiter, start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(str.substr(start)); // Add the last token
    return tokens;
}

mt_int MT_KingChess::convertStringToSecond(const std::string &timeStr)
{
    int hours, minutes, seconds;
    char sep1, sep2;
    std::istringstream iss(timeStr);
    iss >> hours >> sep1 >> minutes >> sep2 >> seconds;
    return hours * 60 * 60 + minutes * 60 + seconds;
}

mt_void MT_KingChess::addRemarkPositions(MT_Chess_Object& oldpos, MT_Chess_Object& newpos)
{
    this->_oldPosition = &oldpos;
    this->_newPosition = &newpos;
}

mt_void MT_KingChess::addKingHighlight(MT_Chess_Object& kinghighlight)
{
    this->_kingPosition = &kinghighlight;
}

mt_void MT_KingChess::addPiece(MT_Chess_Object& piece, int col, int row)
{
    this->_mttable.addObject(piece);
    this->_listKingChessObjects.push_back(&piece);
    this->_mttable.updateObjectPosition(piece, col, row);
}

mt_void MT_KingChess::addDefaultPiece(MT_Chess_Object& obj)
{
    // cout << "MT_KingChess::addDefaultPiece " << obj.getPiece() << " " << obj.getColor() << endl;
    this->_mttable.addObject(obj);
    this->_listKingChessObjects.push_back(&obj);

    if (obj.getPiece() == "king") {
        if (obj.getColor() == "black") {
            this->_mttable.updateObjectPosition(obj, 4, 0);
        }
        else if (obj.getColor() == "white") {
            this->_mttable.updateObjectPosition(obj, 4, 7);
        }
    }

    if (obj.getPiece() == "queen") {
        if (obj.getColor() == "black") {
            this->_mttable.updateObjectPosition(obj, 3, 0);
        }
        else if (obj.getColor() == "white") {
            this->_mttable.updateObjectPosition(obj, 3, 7);
        }
    }

    if (obj.getPiece() == "rook") {
        if (obj.getColor() == "black") {
            MT_Position* objpos = this->_mttable.getPositionAt(0, 0);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 0, 0);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(7, 0);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 7, 0);
            }
        }
        else if (obj.getColor() == "white") {
            MT_Position* objpos = this->_mttable.getPositionAt(0, 7);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 0, 7);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(7, 7);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 7, 7);
            }
        }
    }

    if (obj.getPiece() == "knight") {
        if (obj.getColor() == "black") {
            MT_Position* objpos = this->_mttable.getPositionAt(1, 0);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 1, 0);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(6, 0);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 6, 0);
            }
        }
        else if (obj.getColor() == "white") {
            MT_Position* objpos = this->_mttable.getPositionAt(1, 7);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 1, 7);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(6, 7);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 6, 7);
            }
        }
    }

    if (obj.getPiece() == "bishop") {
        if (obj.getColor() == "black") {
            MT_Position* objpos = this->_mttable.getPositionAt(2, 0);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 2, 0);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(5, 0);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 5, 0);
            }
        }
        else if (obj.getColor() == "white") {
            MT_Position* objpos = this->_mttable.getPositionAt(2, 7);
            if (this->_mttable.checkFreePosition(*objpos))
            {
                this->_mttable.updateObjectPosition(obj, 2, 7);
            }
            else
            {
                MT_Position* objpos_2 = this->_mttable.getPositionAt(5, 7);
                if (this->_mttable.checkFreePosition(*objpos_2))
                    this->_mttable.updateObjectPosition(obj, 5, 7);
            }
        }
    }

    if (obj.getPiece() == "pawn") {
        if (obj.getColor() == "black") {
            if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(0, 1))))
                this->_mttable.updateObjectPosition(obj, 0, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(1, 1))))
                this->_mttable.updateObjectPosition(obj, 1, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(2, 1))))
                this->_mttable.updateObjectPosition(obj, 2, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(3, 1))))
                this->_mttable.updateObjectPosition(obj, 3, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(4, 1))))
                this->_mttable.updateObjectPosition(obj, 4, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(5, 1))))
                this->_mttable.updateObjectPosition(obj, 5, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(6, 1))))
                this->_mttable.updateObjectPosition(obj, 6, 1);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(7, 1))))
                this->_mttable.updateObjectPosition(obj, 7, 1);
        }
        else if (obj.getColor() == "white")
        {
            if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(0, 6))))
                this->_mttable.updateObjectPosition(obj, 0, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(1, 6))))
                this->_mttable.updateObjectPosition(obj, 1, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(2, 6))))
                this->_mttable.updateObjectPosition(obj, 2, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(3, 6))))
                this->_mttable.updateObjectPosition(obj, 3, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(4, 6))))
                this->_mttable.updateObjectPosition(obj, 4, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(5, 6))))
                this->_mttable.updateObjectPosition(obj, 5, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(6, 6))))
                this->_mttable.updateObjectPosition(obj, 6, 6);
            else if (this->_mttable.checkFreePosition(*(this->_mttable.getPositionAt(7, 6))))
                this->_mttable.updateObjectPosition(obj, 7, 6);
        }
    }
}

string MT_KingChess::removeSubString(string larger, string sub)
{
    string result = larger;
    size_t pos;
    // Keep finding and erasing until no more occurrences
    while ((pos = result.find(sub)) != std::string::npos) {
        result.erase(pos, sub.size());
    }
    return result;
}

mt_void MT_KingChess::addReviewData(string filename)
{
    string data = filename;
    data = " " + data;
    regex re(" [0-9]+. "); // Matches spaces, dots, and numbers
    sregex_token_iterator it(data.begin(), data.end(), re, -1);
    sregex_token_iterator end;

    vector<string> tokens(it, end);
    for (const auto& token : tokens) {
        if (!token.empty()) {
            vector<string> steps = splitString(token, ' ');
            if (steps.size() == 2) {
                this->_move_steps_in_PGN.push_back("W" + steps[0]);
                this->_move_steps_in_PGN.push_back("B" + steps[1]);
            } else {
                this->_move_steps_in_PGN.push_back("W" + steps[0]);
            }
        }
    }
}

mt_void MT_KingChess::addReviewDataWithTimeFormat(string input)
{
    string data = input;
    data = " " + data;
    regex re(" [0-9]+. | [0-9]+... "); // Matches spaces, dots, and numbers
    sregex_token_iterator it(data.begin(), data.end(), re, -1);
    sregex_token_iterator end;

    mt_uint num_of_steps = 0;
    vector<string> tokens(it, end);
    for (const auto& token : tokens) {
        if (!token.empty()) {
            vector<string> steps = splitString(token, ' ');

            if (steps.size() == 3) {
                string timedata = steps[2];
                size_t pos = timedata.find(']');
                timedata.erase(pos, 2);
                this->_time_clock.push_back(timedata);
                // cout << steps[0] << endl;
                if (num_of_steps % 2 == 0) this->_move_steps_in_PGN.push_back("W" + steps[0]);
                else this->_move_steps_in_PGN.push_back("B" + steps[0]);
                num_of_steps++;
            } else {
                this->_move_steps_in_PGN.push_back("W" + steps[0]);
                this->_move_steps_in_PGN.push_back("B" + steps[1]);
            }
        }
    }
}

mt_bool MT_KingChess::isGameFinish()
{
    return this->isFinished;
}

string MT_KingChess::getResult()
{
    return this->_result;
}

mt_void MT_KingChess::review()
{
    // cout << "review" << endl;
    if (this->_move_steps_in_PGN.size() > 0)
    {
        this->_piecePrisoner = "";
        this->_colorPrisoner = "";

        string token = this->_move_steps_in_PGN.at(0);
        this->_move_steps_in_PGN.erase(this->_move_steps_in_PGN.begin());

        string clocktime = "";
        if (this->_time_clock.size() > 0) {
            clocktime = this->_time_clock.at(0);
            this->_time_clock.erase(this->_time_clock.begin());
        }

        if (token.find("Result") != std::string::npos) {
            this->isFinished = true;
            string result_token = this->_move_steps_in_PGN.at(0);
            this->_move_steps_in_PGN.erase(this->_move_steps_in_PGN.begin());
            if (result_token.find("B0-1") != std::string::npos) {
                this->_result = "black";
            } else if (result_token.find("B1-0") != std::string::npos) {
                this->_result = "white";
            } else {
                this->_result = "draw";
            }
        }

        mt_int w_column = -1;
        mt_int w_row = -1;
        mt_int prev_col = -1;
        mt_int prev_row = -1;
        string piece = "";
        string color = "";
        string pawnPromote = "";
        mt_bool isKingCapture = false;
        if (token.size() == 3)
        {
            w_column = getColumnNumber(token[1]);
            w_row = getRowNumber(token[2]);
            piece = "pawn";
        }
        else if (token.size() == 4)
        {
            if ((token[1] == '0' && token[2] == '-' && token[3] == '0') ||
                (token[1] == 'O' && token[2] == '-' && token[3] == 'O')) {
                if (token[0] == 'W') this->castling("kingside", "white");
                else this->castling("kingside", "black");
            } else if (token[3] == '+') {
                isKingCapture = true;
                w_column = getColumnNumber(token[1]);
                w_row = getRowNumber(token[2]);
                piece = "pawn";
            } else {
                w_column = getColumnNumber(token[2]);
                w_row = getRowNumber(token[3]);
                if (token[1] == 'N') piece = "knight";
                if (token[1] == 'B') piece = "bishop";
                if (token[1] == 'Q') piece = "queen";
                if (token[1] == 'R') piece = "rook";
                if (token[1] == 'K') piece = "king";
            }
        }
        else if (token.size() == 5)
        {
            if (token[2] == 'x') {
                if (token[1] == 'N') {
                    piece = "knight";
                }
                else if (token[1] == 'B') {
                    piece = "bishop";
                }
                else if (token[1] == 'Q') {
                    piece = "queen";
                }
                else if (token[1] == 'R') {
                    piece = "rook";
                }
                else if (token[1] == 'K') {
                    piece = "king";
                }
                else {
                    piece = "pawn";
                    prev_col = getColumnNumber(token[1]);
                }
                w_column = getColumnNumber(token[3]);
                w_row = getRowNumber(token[4]);
            } else {
                if (token[4] == '+') {
                    isKingCapture = true;
                    w_column = getColumnNumber(token[2]);
                    w_row = getRowNumber(token[3]);
                } else if (token[3] == '=') { // Wh1=Q
                    // Pawn promotion
                    w_column = getColumnNumber(token[1]);
                    w_row = getRowNumber(token[2]);
                    piece = "pawn";
                    if (token[4] == 'N') pawnPromote = "knight";
                    if (token[4] == 'B') pawnPromote = "bishop";
                    if (token[4] == 'Q') pawnPromote = "queen";
                    if (token[4] == 'R') pawnPromote = "rook";
                    if (token[4] == 'K') pawnPromote = "king";
                } else {
                    w_column = getColumnNumber(token[3]);
                    w_row = getRowNumber(token[4]);
                    prev_col = getColumnNumber(token[2]);
                    if (prev_col == -1) {
                        prev_row = getRowNumber(token[2]);
                    }
                }
                if (token[1] == 'N') piece = "knight";
                if (token[1] == 'B') piece = "bishop";
                if (token[1] == 'Q') piece = "queen";
                if (token[1] == 'R') piece = "rook";
                if (token[1] == 'K') piece = "king";
            }
        }
        else if (token.size() == 6)
        {
            if ((token[1] == '0' && token[2] == '-' && token[3] == '0' && token[4] == '-' && token[5] == '0') ||
                (token[1] == 'O' && token[2] == '-' && token[3] == 'O' && token[4] == '-' && token[5] == 'O')) {
                if (token[0] == 'W') this->castling("queenside", "white");
                else this->castling("queenside", "black");
            }
            else if (token[5] == '+') {
                isKingCapture = true;
                if (token[2] == 'x') {
                    if (token[1] == 'N') piece = "knight";
                    else if (token[1] == 'B') piece = "bishop";
                    else if (token[1] == 'Q') piece = "queen";
                    else if (token[1] == 'R') piece = "rook";
                    else if (token[1] == 'K')  piece = "king";
                    else {
                        piece = "pawn";
                        prev_col = getColumnNumber(token[1]);
                    }
                    w_column = getColumnNumber(token[3]);
                    w_row = getRowNumber(token[4]);
                } else if (token[3] == '=') { // We8=Q+
                    // Pawn promotion
                    w_column = getColumnNumber(token[1]);
                    w_row = getRowNumber(token[2]);
                    piece = "pawn";
                    if (token[4] == 'N') pawnPromote = "knight";
                    if (token[4] == 'B') pawnPromote = "bishop";
                    if (token[4] == 'Q') pawnPromote = "queen";
                    if (token[4] == 'R') pawnPromote = "rook";
                    if (token[4] == 'K') pawnPromote = "king";
                } else {
                    prev_col = getColumnNumber(token[2]);
                    w_column = getColumnNumber(token[3]);
                    w_row = getRowNumber(token[4]);
                    if (token[1] == 'N') piece = "knight";
                    if (token[1] == 'B') piece = "bishop";
                    if (token[1] == 'Q') piece = "queen";
                    if (token[1] == 'R') piece = "rook";
                    if (token[1] == 'K') piece = "king";
                }
            }
            else {
                w_column = getColumnNumber(token[4]);
                w_row = getRowNumber(token[5]);
                prev_col = getColumnNumber(token[2]);
                if (token[1] == 'N') piece = "knight";
                if (token[1] == 'B') piece = "bishop";
                if (token[1] == 'Q') piece = "queen";
                if (token[1] == 'R') piece = "rook";
                if (token[1] == 'K') piece = "king";
            }
        }
        else if (token.size() == 7) // WRexd5+
        {
            if (token[6] == '+') {
                isKingCapture = true;
                w_column = getColumnNumber(token[4]);
                w_row = getRowNumber(token[5]);
                prev_col = getColumnNumber(token[2]);
            }
            if (token[1] == 'N') piece = "knight";
            if (token[1] == 'B') piece = "bishop";
            if (token[1] == 'Q') piece = "queen";
            if (token[1] == 'R') piece = "rook";
            if (token[1] == 'K') piece = "king";
        }
        else if (token.size() == 8 && token[7] == '+' && token[5] == '=') // Bcxd1=Q+
        {
            isKingCapture = true;
            w_column = getColumnNumber(token[3]);
            w_row = getRowNumber(token[4]);
            prev_col = getColumnNumber(token[1]);
            piece = "pawn";
            if (token[6] == 'N') pawnPromote = "knight";
            if (token[6] == 'B') pawnPromote = "bishop";
            if (token[6] == 'Q') pawnPromote = "queen";
            if (token[6] == 'R') pawnPromote = "rook";
            if (token[6] == 'K') pawnPromote = "king";
        }

        if (token[0] == 'W') {
            this->_stepNumber++;
            this->_whiteStep = token;
            this->_blackStep = "";
            this->_whiteClockTime = clocktime;
            color = "white";
        }
        else {
            this->_blackStep = token;
            this->_blackClockTime = clocktime;
            color = "black";
        }

        if (w_column != -1 and w_row != -1 and piece != "" and color != "")
        {
            MT_Position* w_pos = this->_mttable.getPositionAt(w_column, w_row);

            // Remove captured object
            mt_int left = -1;
            mt_int right = -1;
            mt_int top = -1;
            mt_int bottom = -1;
            mt_int remove_index = -1;
            for(mt_uint index = 0; index < this->_listKingChessObjects.size(); index++)
            {
                MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(index);
                MT_Position *cur_pie_pos = cur_pie->getCurPosition();
                if (cur_pie_pos->getColumn() == w_pos->getColumn() && cur_pie_pos->getRow() == w_pos->getRow())
                {
                    remove_index = index;
                    // this->_mttable.removeObject(cur_pie);
                    break;
                }
            }

            MT_Chess_Object *w_pie = this->findPieceFromMove(piece, color, *w_pos, prev_col, prev_row);

            // Use for specific pawn moving
            this->_prevPositionCol = w_pie->getCurPosition()->getColumn();
            this->_prevPositionRow = w_pie->getCurPosition()->getRow();

            this->_oldPosition->updatePosition(*w_pie->getCurPosition());
            this->_oldPosition->drawObject();
            this->_newPosition->updatePosition(*w_pos);
            this->_newPosition->drawObject();

            // Set evaluation data
            if (this->_evaluation.size() > 0) {
                string pattern = this->_evaluation.at(0);
                this->_evaluation.erase(this->_evaluation.begin());

                this->_evalPosition->updatePosition(*w_pos);
                this->_evalPosition->drawSpecific(pattern);
            }

            w_pie->updatePosition(*w_pos);
            if (pawnPromote != "") {
                w_pie->setPiece(pawnPromote);
                w_pie->drawSpecific();
            }

            if (remove_index != -1) {
                // Setting prisoner
                this->_piecePrisoner = this->_listKingChessObjects.at(remove_index)->getPiece();
                this->_colorPrisoner = this->_listKingChessObjects.at(remove_index)->getColor();

                this->_mttable.removeObject(this->_listKingChessObjects.at(remove_index));
                this->_listKingChessObjects.erase(this->_listKingChessObjects.begin() + remove_index);
            }

            // Set highlight for king capture
            for(mt_uint index = 0; index < this->_listKingChessObjects.size(); index++)
            {
                MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(index);
                if (isKingCapture == true) {
                    if (cur_pie->getPiece() == "king") {
                        if ((token[0] == 'W' && cur_pie->getColor() == "black") ||
                            (token[0] == 'B' && cur_pie->getColor() == "white")) {
                            this->_kingPosition->updatePosition(*cur_pie->getCurPosition());
                            this->_kingPosition->drawSpecific();
                        }
                    }
                }
            }
            if (isKingCapture == false) {
                this->_kingPosition->clearDrawing();
            }
        }

        // Use for specific pawn moving
        this->_prev_Move = token;
    }
}

MT_Chess_Object* MT_KingChess::findPieceFromMove(string piece, string color, MT_Position& pos, mt_int prev_Col, mt_int prev_Row)
{
    // cout << "findPieceFromMove: Piece: " << piece << " - Color: " << color << " - Col: " << pos.getColumn() << " - Row: " << pos.getRow() << " - Prev Col: " << prev_Col << endl;
    for(mt_uint i = 0; i < this->_listKingChessObjects.size(); i++)
    {
        MT_Chess_Object *res = this->_listKingChessObjects.at(i);
        if (res->getPiece() == piece and res->getColor() == color)
        {
            if (prev_Row != -1 && res->getCurPosition()->getRow() == prev_Row)
            {
                vector<MT_Position*> nextMoves = findNextMove(piece, color, *res->getCurPosition());
                for (mt_uint l = 0; l < nextMoves.size(); l++)
                {
                    if (nextMoves.at(l)->getColumn() == pos.getColumn() && nextMoves.at(l)->getRow() == pos.getRow())
                    {
                        return res;
                    }
                }
            }
        }
    }

    for(mt_uint i = 0; i < this->_listKingChessObjects.size(); i++)
    {
        MT_Chess_Object *res = this->_listKingChessObjects.at(i);
        if (res->getPiece() == piece and res->getColor() == color)
        {
            MT_Position *cur_pos = res->getCurPosition();
            mt_int cur_col = cur_pos->getColumn();
            mt_int cur_row = cur_pos->getRow();
            mt_int next_col = pos.getColumn();
            mt_int next_row = pos.getRow();

            if (prev_Col == -1 || res->getCurPosition()->getColumn() == prev_Col)
            {
                vector<MT_Position*> nextMoves = findNextMove(piece, color, *res->getCurPosition());
                for (mt_uint l = 0; l < nextMoves.size(); l++)
                {
                    if (nextMoves.at(l)->getColumn() == pos.getColumn() && nextMoves.at(l)->getRow() == pos.getRow())
                    {
                        return res;
                    }
                }
            }
        }
    }

    // Find the specific moving of Pawn
    if (piece == "pawn") {
        MT_Chess_Object* nextMovePie = findPawnSpecificMove(piece, color, pos);
        if (nextMovePie != NULL) {
            return nextMovePie;
        }

        MT_Chess_Object* nextMovePie2 = findPawnSpecificMove2(piece, color, pos, prev_Col);
        if (nextMovePie2 != NULL) {
            return nextMovePie2;
        }
    }
    return NULL;
}

MT_Chess_Object* MT_KingChess::findPawnSpecificMove(string piece, string color, MT_Position& pos)
{
    mt_int left = -1;
    mt_int right = -1;
    mt_int top = -1;
    mt_int bottom = -1;
    mt_int remove_index = -1;
    MT_Chess_Object * obj = NULL;
    for(mt_uint index = 0; index < this->_listKingChessObjects.size(); index++)
    {
        MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(index);
        MT_Position *cur_pie_pos = cur_pie->getCurPosition();

        // 1 0 -> 1(r)  : find the top/right
        //   1    0 1

        // 0 1 ->   1(r) : find the top/left
        // 1      1 0

        if (piece == "pawn" && color == "black" &&
            cur_pie->getPiece() == "pawn" && cur_pie->getColor() == "white") {
            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // top
                (cur_pie_pos->getRow() + 1 == pos.getRow())) {
                top = 1;
            }
            if ((cur_pie_pos->getColumn() - 1 == pos.getColumn()) && // right
                (cur_pie_pos->getRow() == pos.getRow())) {
                right = 1;
            }
            if ((cur_pie_pos->getColumn() + 1 == pos.getColumn()) && // left
                (cur_pie_pos->getRow() == pos.getRow())) {
                left = 1;
            }
        }

        // 0  -> 0 1    : find the left/bottom
        // 1 0     0(r)

        //   0 ->  1 0  : find the bottom/right
        // 0 1     0(r)
        if (piece == "pawn" && color == "white" &&
            cur_pie->getPiece() == "pawn" && cur_pie->getColor() == "black") {
            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // bottom
                (cur_pie_pos->getRow() - 1 == pos.getRow())) {
                bottom = 1;
            }
            if ((cur_pie_pos->getColumn() - 1 == pos.getColumn()) && // right
                (cur_pie_pos->getRow() == pos.getRow())) {
                right = 1;
            }
            if ((cur_pie_pos->getColumn() + 1 == pos.getColumn()) && // left
                (cur_pie_pos->getRow() == pos.getRow())) {
                left = 1;
            }
        }
    }

    if (color == "black" && top == 1 && right == 1) {
        for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
            MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
            MT_Position *cur_pie_pos = cur_pie->getCurPosition();

            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // top
                (cur_pie_pos->getRow() + 1 == pos.getRow())) {
                remove_index = re_index;
            }

            if ((cur_pie_pos->getColumn() - 1 == pos.getColumn()) && // right
                (cur_pie_pos->getRow() + 1 == pos.getRow())) {
                obj = cur_pie;
            }
        }
    }

    if (color == "black" && top == 1 && left == 1) {
        for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
            MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
            MT_Position *cur_pie_pos = cur_pie->getCurPosition();

            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // top
                (cur_pie_pos->getRow() + 1 == pos.getRow())) {
                remove_index = re_index;
            }

            if ((cur_pie_pos->getColumn() + 1 == pos.getColumn()) && // left
                (cur_pie_pos->getRow() + 1 == pos.getRow())) {
                obj = cur_pie;
            }
        }
    }

    if (color == "white" && bottom == 1 && left == 1) {
        for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
            MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
            MT_Position *cur_pie_pos = cur_pie->getCurPosition();

            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // bottom
                (cur_pie_pos->getRow() - 1 == pos.getRow())) {
                remove_index = re_index;
            }

            if ((cur_pie_pos->getColumn() + 1 == pos.getColumn()) && // left
                (cur_pie_pos->getRow() - 1 == pos.getRow())) {
                obj = cur_pie;
            }
        }
    }

    if (color == "white" && bottom == 1 && right == 1) {
        for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
            MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
            MT_Position *cur_pie_pos = cur_pie->getCurPosition();

            if ((cur_pie_pos->getColumn() == pos.getColumn()) && // bottom
                (cur_pie_pos->getRow() - 1 == pos.getRow())) {
                remove_index = re_index;
            }

            if ((cur_pie_pos->getColumn() - 1 == pos.getColumn()) && // left
                (cur_pie_pos->getRow() - 1 == pos.getRow())) {
                obj = cur_pie;
            }
        }
    }

    if (remove_index != -1) {
        // Setting prisoner
        this->_piecePrisoner = this->_listKingChessObjects.at(remove_index)->getPiece();
        this->_colorPrisoner = this->_listKingChessObjects.at(remove_index)->getColor();

        this->_mttable.removeObject(this->_listKingChessObjects.at(remove_index));
        this->_listKingChessObjects.erase(this->_listKingChessObjects.begin() + remove_index);
    }

    return obj;
}

MT_Chess_Object* MT_KingChess::findPawnSpecificMove2(string piece, string color, MT_Position& pos, mt_int prev_Col)
{
    cout << "MT_KingChess::findPawnSpecificMove2" << endl;
    MT_Chess_Object * obj = NULL;

    mt_int prev_column = this->_prevPositionCol;
    mt_int prev_row = this->_prevPositionRow;

    cout << "Prev move: " << this->_prev_Move << endl;
    cout << "prev_column: " << prev_column << " - prev_row: " << prev_row << endl;
    cout << "curr_column: " << pos.getColumn() << " - curr_row: " << pos.getRow() << endl;

    if (color == "white") {
        if (pos.getColumn() == prev_column &&
            pos.getRow() - 1 == prev_row) {

            for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
                MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
                MT_Position *cur_pie_pos = cur_pie->getCurPosition();

                if ((cur_pie_pos->getColumn() == prev_Col) &&
                    (cur_pie_pos->getRow() == getRowNumber(this->_prev_Move[2]))) {
                    obj = cur_pie;
                }
            }
        }
    } else {
        if (pos.getColumn() == prev_column &&
            pos.getRow() + 1 == prev_row) {

            for(mt_uint re_index = 0; re_index < this->_listKingChessObjects.size(); re_index++) {
                MT_Chess_Object *cur_pie = this->_listKingChessObjects.at(re_index);
                MT_Position *cur_pie_pos = cur_pie->getCurPosition();

                if ((cur_pie_pos->getColumn() == prev_Col) &&
                    (cur_pie_pos->getRow() == getRowNumber(this->_prev_Move[2]))) {
                    obj = cur_pie;
                }
            }
        }
    }

    return obj;
}

vector<MT_Position*> MT_KingChess::findNextMove(string piece, string color, MT_Position& pos)
{
    // cout << "findNextMove: Piece: " << piece << " - Color: " << color << endl;
    vector<MT_Position*> positionList;
    mt_int curRow = pos.getRow();
    mt_int curCol = pos.getColumn();
    if (piece == "pawn")
    {
        if (color == "black")
        {
            if (pos.getRow() == 1)
            {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() + 1));
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() + 2));
            }
            else
            {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() + 1));
            }
            if ((pos.getColumn() > 0) && (pos.getRow() < 7) &&
                (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(pos.getColumn() - 1, pos.getRow() + 1)))) {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn() - 1, pos.getRow() + 1));
            }
            if ((pos.getColumn() < 7) && (pos.getRow() < 7) &&
                (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(pos.getColumn() + 1, pos.getRow() + 1)))) {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn() + 1, pos.getRow() + 1));
            }
        }
        else
        {
            if (pos.getRow() == 6)
            {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() - 1));
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() - 2));
            }
            else
            {
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn(), pos.getRow() - 1));
            }

            if ((pos.getColumn() > 0) && (pos.getRow() > 0) &&
                (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(pos.getColumn() - 1, pos.getRow() - 1))))
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn() - 1, pos.getRow() - 1));
            if (pos.getColumn() < 7 && pos.getRow() > 0 &&
                !this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(pos.getColumn() + 1, pos.getRow() - 1)))
                positionList.push_back(this->_mttable.getPositionAt(pos.getColumn() + 1, pos.getRow() - 1));
        }
    }
    else if (piece == "knight")
    {
        if (curRow + 2 <= 7 && curCol + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 1, curRow + 2));
        if (curRow + 2 <= 7 && curCol - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 1, curRow + 2));
        if (curRow - 2 >= 0 && curCol + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 1, curRow - 2));
        if (curRow - 2 >= 0 && curCol - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 1, curRow - 2));
        if (curRow + 1 <= 7 && curCol + 2 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 2, curRow + 1));
        if (curRow + 1 <= 7 && curCol - 2 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 2, curRow + 1));
        if (curRow - 1 >= 0 && curCol + 2 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 2, curRow - 1));
        if (curRow - 1 >= 0 && curCol - 2 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 2, curRow - 1));
    }
    else if (piece == "bishop")
    {
        for (mt_int i = 1; curCol - i >= 0; i++) {
            if (curRow - i >= 0) {
                positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow - i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow - i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            if (curRow + i <= 7) {
                positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow + i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow + i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol - i >= 0; i++) {
            if (curRow + i <= 7) {
                positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow + i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow + i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            if (curRow - i >= 0) {
                positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow - i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow - i))) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    else if (piece == "queen")
    {
        for (mt_int i = 1; curCol - i >= 0; i++) {
            if (curRow - i >= 0) {
                positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow - i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow - i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            if (curRow + i <= 7) {
                positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow + i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow + i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol - i >= 0; i++) {
            if (curRow + i <= 7) {
                positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow + i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow + i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            if (curRow - i >= 0) {
                positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow - i));
                if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow - i))) {
                    break;
                }
            } else {
                break;
            }
        }

        for (mt_int i = 1; curCol - i >= 0; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow))) {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow))) {
                break;
            }
        }

        for (mt_int i = 1; curRow - i >= 0; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow - i));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol, curRow - i))) {
                break;
            }
        }

        for (mt_int i = 1; curRow + i <= 7; i++) {
            cout << "curCol: " << curCol << " - curRow: " << curRow + i << endl;
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow + i));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol, curRow + i))) {
                break;
            }
        }
    }
    else if (piece == "rook") {
        for (mt_int i = 1; curCol - i >= 0; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol - i, curRow));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol - i, curRow))) {
                break;
            }
        }

        for (mt_int i = 1; curCol + i <= 7; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol + i, curRow));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol + i, curRow))) {
                break;
            }
        }

        for (mt_int i = 1; curRow - i >= 0; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow - i));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol, curRow - i))) {
                break;
            }
        }

        for (mt_int i = 1; curRow + i <= 7; i++) {
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow + i));
            if (!this->_mttable.checkFreePosition(*this->_mttable.getPositionAt(curCol, curRow + i))) {
                break;
            }
        }
    }
    else if (piece == "king") {
        if (curRow - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow - 1));
        if (curRow + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol, curRow + 1));
        if (curCol - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 1, curRow));
        if (curCol + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 1, curRow));
        if (curRow - 1 >= 0 && curCol - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 1, curRow - 1));
        if (curRow + 1 <= 7 && curCol + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 1, curRow + 1));
        if (curRow - 1 >= 0 && curCol + 1 <= 7)
            positionList.push_back(this->_mttable.getPositionAt(curCol + 1, curRow - 1));
        if (curRow + 1 <= 7 && curCol - 1 >= 0)
            positionList.push_back(this->_mttable.getPositionAt(curCol - 1, curRow + 1));
    }
    return positionList;
}

mt_void MT_KingChess::castling(string side, string color)
{
    // cout << "MT_KingChess::castling" << endl;
    mt_int king_index = -1;
    mt_int rook_index = -1;
    if (side == "kingside") {
        for(mt_int index = 0; index < this->_listKingChessObjects.size(); index++)
        {
            if (this->_listKingChessObjects.at(index)->getColor() == color &&
                this->_listKingChessObjects.at(index)->getPiece() == "king") {
                king_index = index;
            }
            if (this->_listKingChessObjects.at(index)->getColor() == color &&
                this->_listKingChessObjects.at(index)->getPiece() == "rook") {
                rook_index = index;
            }
        }
        MT_Position *new_king_pos = NULL;
        MT_Position *new_rook_pos = NULL;
        if (color == "white") {
            new_king_pos = this->_mttable.getPositionAt(6, 7);
            new_rook_pos = this->_mttable.getPositionAt(5, 7);
        }
        else {
            new_king_pos = this->_mttable.getPositionAt(6, 0);
            new_rook_pos = this->_mttable.getPositionAt(5, 0);
        }
        this->_listKingChessObjects.at(rook_index)->updatePosition(*new_rook_pos);
        this->_listKingChessObjects.at(king_index)->updatePosition(*new_king_pos);
    }

    if (side == "queenside") {
        for(mt_int index = this->_listKingChessObjects.size() - 1; index >= 0; index--)
        {
            if (this->_listKingChessObjects.at(index)->getColor() == color &&
                this->_listKingChessObjects.at(index)->getPiece() == "king") {
                king_index = index;
            }
            if (this->_listKingChessObjects.at(index)->getColor() == color &&
                this->_listKingChessObjects.at(index)->getPiece() == "rook") {
                rook_index = index;
            }
        }
        MT_Position *new_king_pos = NULL;
        MT_Position *new_rook_pos = NULL;
        if (color == "white") {
            new_king_pos = this->_mttable.getPositionAt(2, 7);
            new_rook_pos = this->_mttable.getPositionAt(3, 7);
        }
        else {
            new_king_pos = this->_mttable.getPositionAt(2, 0);
            new_rook_pos = this->_mttable.getPositionAt(3, 0);
        }
        this->_listKingChessObjects.at(rook_index)->updatePosition(*new_rook_pos);
        this->_listKingChessObjects.at(king_index)->updatePosition(*new_king_pos);
    }
}

mt_void MT_KingChess::addEvaluationData(string data)
{
    this->_evaluation = splitString(data, ',');
    // for(mt_uint index = 0; index < this->_evaluation.size(); index++)
    // {
    //     cout << this->_evaluation[index] << endl;
    // }
}

mt_void MT_KingChess::addEvaluationHighlight(MT_Chess_Object& evahighlight)
{
    this->_evalPosition = &evahighlight;
}

mt_void MT_KingChess::reset()
{
    cout << "MT_KingChess::reset" << endl;
    this->_listKingChessObjects.clear();
    this->_mttable.clearData();
    delete this->_oldPosition;
    this->_oldPosition = NULL;
    delete this->_newPosition;
    this->_newPosition = NULL;
    delete this->_kingPosition;
    this->_kingPosition = NULL;
    delete this->_evalPosition;
    this->_evalPosition = NULL;
    this->_prev_Move = "";
    this->_prevPositionRow = -1;
    this->_prevPositionCol = -1;

    _move_steps_in_PGN.clear();
    _time_clock.clear();
    _evaluation.clear();
    isFinished = false;
    _result = "draw";
    _stepNumber = 0;
    _whiteStep = "";
    _whiteClockTime = "";
    _blackStep = "";
    _blackClockTime = "";
    _piecePrisoner = "";
    _colorPrisoner = "";
}
