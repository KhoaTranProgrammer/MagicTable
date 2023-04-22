/*
 * MIT License
 *
 * Copyright (c) 2022 KhoaTran Programmer
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/********************************************************************
 * PURPOSE                                                          *
 ********************************************************************
 * This class desmontrates for how to work with Object in Magic     *
 * Table                                                            *
 *******************************************************************/

#ifndef MT_OBJECT_H
#define MT_OBJECT_H

#include "MT_Atom.h"
#include "MT_Position.h"

enum MT_OBJECT_STATE : short;

class MT_Object : public MT_Atom
{
private:
    MT_Position* _pos; // Current position
    MT_Position* _nextpos; // Next position
    mt_bool isDraw = false;

    MT_OBJECT_STATE _state;

    mt_bool _isDrawWithAnimation;
    mt_uint64 _animationtime; // Time (ms) use when performing animation on object

public:
    MT_Object();
    MT_Object(MT_Position& pos);
    virtual ~MT_Object();

    mt_void updatePosition(MT_Position& pos);

    MT_Position* getCurPosition();
    MT_Position* getNextPosition();
    MT_Position* getPosition();

    mt_void draw(); // Normal draw without animation
    mt_void drawWithAnimation(); // Draw with animation
    virtual mt_void drawObject();
    virtual mt_void move();

    mt_void setAnimationTime(mt_uint64 animationtime);
    mt_uint64 getAnimationTime();
    mt_bool getDrawAnimationStatus(); // True: animation - False: without animation
};

#endif // MT_OBJECT_H
