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
 * This class supports LinkedList ADT Algorithm                     *
 *******************************************************************/

#include "MT_DSA_LinkedList.h"

MT_DSA_LinkedList::MT_DSA_LinkedList() : MT_DSA_List()
{
    this->_head = NULL;
    this->_tail = NULL;
}

mt_void MT_DSA_LinkedList::InsertHead(MT_DSA_Object &obj, int val)
{
    // Create a new Node
    ostringstream oss;
    oss << &obj;
    string address_a = oss.str();
    obj.setAddress(address_a);
    obj.setValue(val);
    this->_mttable.addObject(obj);
    this->_listObjects.insert(this->_listObjects.begin(), &obj);

    // The current Head will no longer become a Head
    // so the Next pointer of the new Node will
    // point to the current Head
    obj.setNextNode(this->_head);

    // The new Node now become the Head
    this->_head = &obj;

    // If the linked list is empty
    // The Tail is also the Head
    if(this->_count == 0)
        this->_tail = this->_head;

    // One element is added
    this->_count++;
}

mt_void MT_DSA_LinkedList::InsertTail(MT_DSA_Object &obj, int val)
{
    // If the linked list is empty,
    // just simply invoke InsertHead()
    if(this->_count == 0)
    {
        InsertHead(obj, val);
        return;
    }

    // Create a new Node
    ostringstream oss;
    oss << &obj;
    string address_a = oss.str();
    obj.setAddress(address_a);
    obj.setValue(val);
    this->_mttable.addObject(obj);
    this->_listObjects.push_back(&obj);

    // The current Tail will no longer become a Tail
    // so the Next pointer of the current Tail will
    // point to the new node
    this->_tail->setNextNode(&obj);

    // The new Node now become the Tail
    this->_tail = &obj;

    // One element is added
    this->_count++;
}

mt_void MT_DSA_LinkedList::Insert(MT_DSA_Object &obj, int index, int val)
{
    // Check if the index is out of bound
    if(index < 0 || index > this->_count)
        return;

    // If inserting a new Head
    if(index == 0)
    {
        InsertHead(obj, val);
        return;
    }
    // If inserting a new Tail
    else if(index == this->_count)
    {
        InsertTail(obj, val);
        return;
    }

    // Start to find previous node
    // from the Head
    MT_DSA_Object *prevNode = this->_head;

    // Traverse the elements until
    // the selected index is found
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->getNextNode();
    }

    // Create the next node which is
    // the element after previous node
    MT_DSA_Object *nextNode = prevNode->getNextNode();

    // Create a new node
    ostringstream oss;
    oss << &obj;
    string address_a = oss.str();
    obj.setAddress(address_a);
    obj.setValue(val);
    this->_mttable.addObject(obj);
    this->_listObjects.insert(this->_listObjects.begin() + index, &obj);

    // Insert this new node between
    // the previous node and the next node
    obj.setNextNode(nextNode);
    prevNode->setNextNode(&obj);

    // One element is added
    this->_count++;
}

mt_void MT_DSA_LinkedList::updateDataLocationInTable()
{
    this->_mttable.clearHistory();
    for(int i = 0; i < this->_listObjects.size(); i++)
    {
        if ((i / this->_mttable.getCol()) % 2 == 0)
        {
            this->_mttable.updateObjectPosition(*this->_listObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getCol());
        }
        else
        {
            this->_mttable.updateObjectPosition(*this->_listObjects.at(i), this->_mttable.getCol() - (i % this->_mttable.getCol()) - 1, i / this->_mttable.getCol());
        }
    }
}

mt_void MT_DSA_LinkedList::updateDataLocationInverseInTable()
{
    this->_mttable.clearHistory();
    for(int i = this->_listObjects.size() - 1; i >= 0 ; i--)
    {
        if ((i / this->_mttable.getCol()) % 2 == 0)
        {
            this->_mttable.updateObjectPosition(*this->_listObjects.at(i), i % this->_mttable.getCol(), i / this->_mttable.getCol());
        }
        else
        {
            this->_mttable.updateObjectPosition(*this->_listObjects.at(i), this->_mttable.getCol() - (i % this->_mttable.getCol()) - 1, i / this->_mttable.getCol());
        }
    }
}

mt_void MT_DSA_LinkedList::Remove(int index)
{
    // Do nothing if list is empty
    if(this->_count == 0)
        return;

    // Do nothing if index is out of bound
    if(index < 0 || index >= this->_count)
        return;

    // If removing the current Head
    if(index == 0)
    {
        RemoveHead();
        return;
    }
    // If removing the current Tail
    else if(index == this->_count - 1)
    {
        RemoveTail();
        return;
    }

    // Start to traverse the list
    // from the Head
    MT_DSA_Object *prevNode = this->_head;

    // Find the element before
    // the selected index
    for(int i = 0; i < index - 1; ++i)
    {
        prevNode = prevNode->getNextNode();
    }

    // The removed element is after
    // the prevNode
    MT_DSA_Object *node = prevNode->getNextNode();

    // The nextNode will be the neighbor of
    // prevNode if the node is removed
    MT_DSA_Object *nextNode = node->getNextNode();

    // Link the prevNode to nextNode
    prevNode->setNextNode(nextNode);

    // It's now safe to remove
    // the selected index element
    this->_mttable.removeObject(node);
    this->_listObjects.erase(this->_listObjects.begin() + index);

    // One element is removed
    this->_count--;
}

mt_void MT_DSA_LinkedList::RemoveHead()
{
    // Do nothing if list is empty
    if(this->_count == 0)
        return;

    // Save the current Head
    // to a new node
    MT_DSA_Object *node = this->_head;

    // Point the Head Pointer
    // to the element next to the current Head
    this->_head = this->_head->getNextNode();

    // Now it's safe to remove
    // the first element
    this->_mttable.removeObject(node);
    this->_listObjects.erase(this->_listObjects.begin());

    // One element is removed
    this->_count--;
}

mt_void MT_DSA_LinkedList::RemoveTail()
{
    // Do nothing if list is empty
    if(this->_count == 0)
        return;

    // If List element is only one
    // just simply call RemoveHead()
    if(this->_count == 1)
    {
        RemoveHead();
        return;
    }

    // Start to find previous node
    // from the Head
    MT_DSA_Object *prevNode = this->_head;

    // This is the candidate of
    // removed items which is
    // the element next to the prevNode
    MT_DSA_Object *node = this->_head->getNextNode();

    // Traverse the elements until
    // the last element
    while(node->getNextNode() != NULL)
    {
        prevNode = prevNode->getNextNode();
        node = node->getNextNode();
    }

    // the prevNode now becomes the Tail
    // so the Next pointer of the prevNode
    // point to NULL
    prevNode->setNextNode(NULL);
    this->_tail = prevNode;

    // Now it's safe to remove
    // the last element
    this->_mttable.removeObject(node);
    this->_listObjects.pop_back();

    // One element is removed
    this->_count--;
}
