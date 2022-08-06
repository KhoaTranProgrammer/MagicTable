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

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-18-2022                                               *
 *        Initial version supports: position/state/move/draw object *
 * 1.1.0: Aug-06-2022                                               *
 *        Supports animation time setting                           *
 *******************************************************************/

#include "MT_Object.h"

enum MT_OBJECT_STATE : short
{
    MT_OBJECT_INIT,
    MT_OBJECT_DRAWING,
    MT_OBJECT_STARTPOSITION,
    MT_OBJECT_NEWPOSITION
};

MT_Object::MT_Object()
{
    this->_state = MT_OBJECT_INIT;
    this->_animationtime = 0;
}

MT_Object::MT_Object(MT_Position& pos)
{
    this->_state = MT_OBJECT_INIT;
    this->_pos = &pos;
    this->_animationtime = 0;
}

mt_void MT_Object::updatePosition(MT_Position &pos)
{
    if (this->_state == MT_OBJECT_INIT || isDraw == false)
    {
        this->_pos = &pos;
        this->_state = MT_OBJECT_STARTPOSITION;
    }
    else
    {
        this->_nextpos = &pos;
        this->_state = MT_OBJECT_NEWPOSITION;
    }
}

mt_void MT_Object::drawObject()
{
    // Default method that is needed to override
}

mt_void MT_Object::move()
{
    // Default method that is needed to override
}

mt_void MT_Object::draw()
{
    if (this->_state == MT_OBJECT_STARTPOSITION)
    {
        this->drawObject();
        this->_state = MT_OBJECT_DRAWING;
        this->isDraw = true;
    }
    else if (this->_state == MT_OBJECT_NEWPOSITION)
    {
        this->move();
        this->_state = MT_OBJECT_DRAWING;
    }
}

MT_Position* MT_Object::getCurPosition()
{
    return this->_pos;
}

MT_Position* MT_Object::getNextPosition()
{
    return this->_nextpos;
}

mt_void MT_Object::setAnimationTime(mt_uint64 animationtime)
{
    this->_animationtime = animationtime;
}

mt_uint64 MT_Object::getAnimationTime()
{
    return this->_animationtime;
}
