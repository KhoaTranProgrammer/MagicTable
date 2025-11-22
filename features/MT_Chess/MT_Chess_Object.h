#ifndef MT_CHESS_OBJECT_H
#define MT_CHESS_OBJECT_H

#include "MT_Object.h"

class MT_Chess_Object : public MT_Object
{
private:
    // King
    // Queen
    // Castle
    // Knigh
    // Bishop
    // Pawn
    string _piece = "";

    // Black - White
    string _color = "";

public:
    MT_Chess_Object();
    MT_Chess_Object(string piece, string color);
    ~MT_Chess_Object();

    void drawObject();
    void move();
    virtual void clearDrawing();
    virtual void drawSpecific();
    string getPiece();
    void setPiece(string pawnPromote);
    string getColor();
};

#endif // MT_CHESS_OBJECT_H
