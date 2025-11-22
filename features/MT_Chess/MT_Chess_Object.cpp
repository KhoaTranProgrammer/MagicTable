#include "MT_Chess_Object.h"

MT_Chess_Object::MT_Chess_Object() : MT_Object()
{

}

MT_Chess_Object::MT_Chess_Object(string piece, string color) : MT_Object()
{
    this->_piece = piece;
    this->_color = color;
}

MT_Chess_Object::~MT_Chess_Object()
{

}

void MT_Chess_Object::drawObject()
{

}

void MT_Chess_Object::move()
{

}

void MT_Chess_Object::clearDrawing()
{

}

void MT_Chess_Object::drawSpecific()
{

}

string MT_Chess_Object::getPiece()
{
    return this->_piece;
}

void MT_Chess_Object::setPiece(string pawnPromote)
{
    this->_piece = pawnPromote;
}

string MT_Chess_Object::getColor()
{
    return this->_color;
}
