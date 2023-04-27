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
 * This class supports Doubly LinkedList ADT Algorithm              *
 *******************************************************************/

#ifndef MT_DSA_DOUBLYLINKEDLIST_H
#define MT_DSA_DOUBLYLINKEDLIST_H

#include "MT_DSA_List.h"

class MT_DSA_DoublyLinkedList : public MT_DSA_List
{
private:
    // The first node in the list or null if empty
    MT_DSA_Object *_head;

    // The last node in the list or null if empty
    MT_DSA_Object *_tail;

public:
    MT_DSA_DoublyLinkedList();

    mt_void updateDataLocationInTable();
    mt_void updateDataLocationInverseInTable();

    // Insert() operation
    mt_void InsertHead(MT_DSA_Object &obj, int val);
    mt_void InsertTail(MT_DSA_Object &obj, int val);
    mt_void Insert(MT_DSA_Object &obj, int index, int val);

    // Remove() operation
    mt_void RemoveHead();
    mt_void RemoveTail();
    mt_void Remove(int index);
};

#endif // MT_DSA_DOUBLYLINKEDLIST_H
