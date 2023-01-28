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
 * This class supports Sorting Algorithm                            *
 *******************************************************************/

#include "MT_DSA_Sorting.h"

MT_DSA_Sorting::MT_DSA_Sorting()
{

}

mt_void MT_DSA_Sorting::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

mt_void MT_DSA_Sorting::addData(MT_DSA_Object& obj, int value)
{
    obj.setValue(value);
    this->_listSortObjects.push_back(&obj);
    this->_mttable.addObject(obj);
    this->sortData();
}

mt_void MT_DSA_Sorting::addDataWithoutSort(MT_DSA_Object& obj, int value)
{
    obj.setValue(value);
    this->_listSortObjects.push_back(&obj);
    this->_mttable.addObject(obj);
}

mt_void MT_DSA_Sorting::sortData()
{

}

mt_void MT_DSA_Sorting::sortDataWithHistory()
{

}

mt_void MT_DSA_Sorting::sortDataWithMeasurement()
{
    this->startMeasure();
    this->sortData();
    this->stopMeasure();
}

mt_void MT_DSA_Sorting::drawHistoryAll()
{
    this->_mttable.drawHistoryAll();
}

mt_void MT_DSA_Sorting::drawHistoryOne()
{
    this->_mttable.drawHistoryOne();
}

mt_void MT_DSA_Sorting::drawData()
{
    this->_mttable.clearHistory();
    for(int i = 0; i < this->_listSortObjects.size(); i++)
    {
        this->_mttable.updateObjectPosition(*this->_listSortObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getCol());
    }

    this->_mttable.drawObjects();
}

mt_void MT_DSA_Sorting::startMeasure()
{
    this->_startexecutiontime = clock();
}

mt_void MT_DSA_Sorting::stopMeasure()
{
    this->_stopexecutiontime = clock();
}

mt_double MT_DSA_Sorting::elapsedMicroseconds()
{
    double elapsedseconds = double(_stopexecutiontime - _startexecutiontime) / double(CLOCKS_PER_SEC);
    return elapsedseconds;
}

mt_void MT_DSA_Sorting::clearData()
{
    this->_listSortObjects.clear();
    this->_mttable.clearData();
}
