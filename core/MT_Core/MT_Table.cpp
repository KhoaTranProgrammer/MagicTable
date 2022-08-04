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
 * This class describe/process for Table in Magic Table             *
 *******************************************************************/

/********************************************************************
 * VERSION HISTORY                                                  *
 ********************************************************************
 * 1.0.0: Jul-21-2022                                               *
 *        Initial version supports: Add/update/draw Object          *
 * 1.1.0: Jul-31-2022                                               *
 *        Supports process history of Object moving using           *
 *        MT_RefObject                                              *
 *        Add MT_RefObject into history inside updateObjectPosition *
 * 1.1.1: Jul-31-2022                                               *
 *        Supports draw history all and one by one                  *
 * 1.1.2: Aug-04-2022                                               *
 *        Support each index in history as list of MT_RefObject     *
 *******************************************************************/

#include "MT_Table.h"

MT_Table::MT_Table()
{
    this->_actual_width = 0;
    this->_actual_height = 0;
    this->_position_width = 0;
    this->_actual_height = 0;
}

void MT_Table::createTable(mt_uint w, mt_uint h, mt_uint col, mt_uint row)
{
    this->_index_history = 0;
    this->_actual_width = w;
    this->_actual_height = h;
    this->_row = row;
    this->_column = col;
    this->_position_width = this->_actual_width / this->_column;
    this->_position_height = this->_actual_height / this->_row;

    // Create the table with the matrix of position
    for (mt_uint row = 0; row < this->_row; row++)
    {
        for (mt_uint col = 0; col < this->_column; col++)
        {
            MT_Position* onepos = new MT_Position( col * this->_position_width, row * this->_position_height,
                                                   this->_position_width, this->_position_height,
                                                   col, row);
            this->_matrixposition.push_back(onepos);
        }
    }
}

void MT_Table::addObject(mt_uint col, mt_uint row)
{
    MT_Position* objpos = this->getPositionAt(col, row);
    MT_Object obj(*objpos);
    this->_objectlist.push_back(&obj);
}

void MT_Table::addObject(MT_Object& obj, mt_uint col, mt_uint row)
{
    MT_Position* objpos = this->getPositionAt(col, row);
    obj.updatePosition(*objpos);
    this->_objectlist.push_back(&obj);
}

void MT_Table::addObject(MT_Object& obj)
{
    this->_objectlist.push_back(&obj);
}

MT_Position* MT_Table::getPositionAt(mt_uint col, mt_uint row)
{
    return this->_matrixposition.at(static_cast<mt_uint>(row * this->_row + col));
}

void MT_Table::drawObjects()
{
    for(mt_uint i = 0; i < this->_objectlist.size(); i++)
    {
        this->_objectlist.at(i)->draw();
    }
}

bool MT_Table::updateObjectPosition(MT_Object &obj, mt_uint col, mt_uint row)
{
    if(checkValidPosition(col, row))
    {
        MT_Position* objpos = this->getPositionAt(col, row);
        obj.updatePosition(*objpos);

        vector<MT_RefObject*> listofrefobj;
        MT_RefObject* refobj = new MT_RefObject(obj, *objpos);
        listofrefobj.push_back(refobj);
        this->_history.push_back(listofrefobj);

        return true;
    }
    return false;
}

mt_uint MT_Table::getRow()
{
    return this->_row;
}

mt_uint MT_Table::getCol()
{
    return this->_column;
}

mt_bool MT_Table::checkValidPosition(mt_uint col, mt_uint row)
{
    if(col < this->_column && row < this->_row) return true;
    else return false;
}

mt_void MT_Table::clearHistory()
{
    this->_index_history = 0;
    for (mt_uint i = this->_history.size(); i > 0;)
    {
        --i;
        for (mt_uint j = this->_history.at(i).size(); j > 0;)
        {
            --j;
            delete this->_history.at(i).at(j);
            this->_history.at(i).pop_back();
        }

        this->_history.pop_back();
    }
}

mt_void MT_Table::drawHistoryAll()
{
    for(mt_uint i = 0; i < this->_history.size(); i++)
    {
        for(mt_uint j = 0; j < this->_history.at(i).size(); j++)
        {
            MT_Object* obj = this->_history.at(i).at(j)->getObject();
            obj->updatePosition(*(this->_history.at(i).at(j)->getPosition()));
            obj->draw();
        }
    }
}

mt_void MT_Table::drawHistoryOne()
{
    if (this->_index_history < this->_history.size())
    {
        for(mt_uint j = 0; j < this->_history.at(this->_index_history).size(); j++)
        {
            MT_Object* obj = this->_history.at(this->_index_history).at(j)->getObject();
            obj->updatePosition(*(this->_history.at(this->_index_history).at(j)->getPosition()));
            obj->draw();
        }
        this->_index_history++;
    }
}
