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

#include "MT_DSA_DoublyLinkedList.h"

MT_DSA_DoublyLinkedList::MT_DSA_DoublyLinkedList() : MT_DSA_List()
{
    this->_head = NULL;
    this->_tail = NULL;
}

mt_void MT_DSA_DoublyLinkedList::updateDataLocationInTable()
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

mt_void MT_DSA_DoublyLinkedList::updateDataLocationInverseInTable()
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

mt_void MT_DSA_DoublyLinkedList::InsertHead(MT_DSA_Object &obj, int val)
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

    // If the current Head is exist,
    // the previous pointer of the current Head
    // should point to the node
    if(this->_head != NULL)
        this->_head->setPreviousNode(&obj);

    // The new Node now become the Head
    this->_head = &obj;

    // If the linked list is empty
    // The Tail is also the Head
    if(this->_count == 0)
        this->_tail = this->_head;

    // One element is added
    this->_count++;
}

mt_void MT_DSA_DoublyLinkedList::InsertTail(MT_DSA_Object &obj, int val)
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

    // Also, the previous pointer of the new node
    // should point to the current Tail
    obj.setPreviousNode(this->_tail);

    // The new Node now become the Tail
    this->_tail = &obj;

    // One element is added
    this->_count++;
}

mt_void MT_DSA_DoublyLinkedList::Insert(MT_DSA_Object &obj, int index, int val)
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
    MT_DSA_Object * prevNode = this->_head;

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
    obj.setPreviousNode(prevNode);
    prevNode->setNextNode(&obj);
    nextNode->setPreviousNode(&obj);

    // One element is added
    this->_count++;
}

mt_void MT_DSA_DoublyLinkedList::RemoveHead()
{

}

mt_void MT_DSA_DoublyLinkedList::RemoveTail()
{

}

mt_void MT_DSA_DoublyLinkedList::Remove(int index)
{

}
