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
 * This class stores Node data from Hierarchical Tree               *
 *******************************************************************/

#include "MT_DSA_TreeObject.h"

MT_DSA_TreeObject::MT_DSA_TreeObject() : MT_Object()
{

}

MT_DSA_TreeObject::~MT_DSA_TreeObject()
{

}

void MT_DSA_TreeObject::drawObject()
{

}

void MT_DSA_TreeObject::move()
{

}

void MT_DSA_TreeObject::setValue(int value)
{
    this->_value = value;
}

int MT_DSA_TreeObject::getValue()
{
    return this->_value;
}

void MT_DSA_TreeObject::setHeight(int value)
{
    this->_height = value;
}

int MT_DSA_TreeObject::getHeight()
{
    return this->_height;
}

MT_Position* MT_DSA_TreeObject::getParentPosition()
{
    if (this->_parent != NULL)
    {
        return this->_parent->getCurPosition();
    }
    return NULL;
}

MT_Position* MT_DSA_TreeObject::getParentNextPosition()
{
    if (this->_parent != NULL)
    {
        return this->_parent->getNextPosition();
    }
    return NULL;
}
