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
 * This class supports Hierarchical Tree Structure Algorithm        *
 *******************************************************************/

#ifndef MT_DSA_HIERARCHICALTREE_H
#define MT_DSA_HIERARCHICALTREE_H

#include "MT_Table.h"
#include "MT_Object.h"
#include "MT_DSA_TreeObject.h"
#include <math.h>

class MT_DSA_HierarchicalTree
{
private:
    MT_DSA_TreeObject *_root;
    mt_uint _column;
    mt_uint _height;

protected:
    MT_Table _mttable;
    MT_DSA_TreeObject *Insert(MT_DSA_TreeObject *node, MT_DSA_TreeObject *obj, int key);
    void PrintTreeInOrder(MT_DSA_TreeObject *node);
    int height(MT_DSA_TreeObject *node);
    int getcol(int h);
    void printTree(MT_DSA_TreeObject *node, int col, int row, int height);
    MT_DSA_TreeObject *Remove(MT_DSA_TreeObject *node, int key);
    mt_int Successor(MT_DSA_TreeObject * node);
    mt_int FindMin(MT_DSA_TreeObject *node);
    MT_DSA_TreeObject *Search(MT_DSA_TreeObject *node, int key);

public:
    MT_DSA_HierarchicalTree();
    mt_void createTable(int w, int h, int col, int row);
    mt_void InsertWithEmptyNode(MT_DSA_TreeObject *obj, int key);
    mt_void PrintTreeInOrder();
    mt_void PreorderTraversal();
    mt_void drawData();
    mt_void clearData();
    mt_void Remove(int key);
    mt_int Successor(int key);
    mt_int FindMin();
    mt_bool Search(int key);
    mt_uint getColumn();
    mt_uint getHeight();
};

#endif // MT_DSA_HIERARCHICALTREE_H
