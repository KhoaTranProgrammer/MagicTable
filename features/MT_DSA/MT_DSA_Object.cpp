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
 * This class supports data processing for Data Structure/Algorithm *
 *******************************************************************/

#include "MT_DSA_Object.h"

MT_DSA_Object::MT_DSA_Object() : MT_Object()
{
    this->_next = NULL;
}

MT_DSA_Object::~MT_DSA_Object()
{

}

void MT_DSA_Object::drawObject()
{

}

void MT_DSA_Object::move()
{

}

void MT_DSA_Object::setValue(int value)
{
    this->_value = value;
}

int MT_DSA_Object::getValue()
{
    return this->_value;
}

void MT_DSA_Object::setAddress(string value)
{
    this->_address = value;
}

string MT_DSA_Object::getAddress()
{
    return this->_address;
}

MT_DSA_Object *MT_DSA_Object::getNextNode()
{
    return this->_next;
}

mt_void MT_DSA_Object::setNextNode(MT_DSA_Object *node)
{
    this->_next = node;
}

MT_Position* MT_DSA_Object::getNextNodePosition()
{
    if (this->_next != NULL)
    {
        return this->_next->getPosition();
    }
    return NULL;
}
