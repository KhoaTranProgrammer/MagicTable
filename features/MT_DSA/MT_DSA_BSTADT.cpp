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
 * This class supports Binary Search Tree ADT                       *
 *******************************************************************/

#include "MT_DSA_BSTADT.h"

MT_DSA_BSTADT::MT_DSA_BSTADT() : MT_DSA_HierarchicalTree()
{

}

MT_DSA_TreeObject *MT_DSA_BSTADT::Insert(MT_DSA_TreeObject *node, MT_DSA_TreeObject *obj, int key)
{
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = obj;
        node->setValue(key);
        this->_mttable.addObject(*node);
    }
    // If the given key is greater than
    // node's key then go to right subtree
    else if(node->getValue() < key)
    {
        node->_right = Insert(node->_right, obj, key);
        node->_right->_parent = node;
    }
    // If the given key is smaller than
    // node's key then go to left subtree
    else
    {
        node->_left = Insert(node->_left, obj, key);
        node->_left->_parent = node;
    }

    return node;
}

MT_DSA_TreeObject *MT_DSA_BSTADT::Remove(MT_DSA_TreeObject *node, int key)
{
    // The given node is not found in BST
    if (node == NULL)
        return NULL;

    // Target node is found
    if (node->getValue() == key)
    {
        // If the node is a leaf node. The node can be safely removed
        if (node->_left == NULL && node->_right == NULL)
        {
            this->_mttable.removeObject(node);
            node = NULL;
        }
        // The node have only one child at right
        else if (node->_left == NULL && node->_right != NULL)
        {
            // The only child will be connected to the parent's of node directly
            node->_right->_parent = node->_parent;

            // Bypass node
            this->_mttable.removeObject(node);
            node = node->_right;
        }
        // The node have only one child at left
        else if (node->_left != NULL && node->_right == NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
            node->_left->_parent = node->_parent;

            // Bypass node
            this->_mttable.removeObject(node);
            node = node->_left;
        }
        // The node have two children (left and right)
        else
        {
            // Find successor or predecessor to avoid quarrel
            int successorKey = Successor(key);

            // Replace node's key with successor's key
            node->setValue(successorKey);

            // Delete the old successor's key
            node->_right = Remove(node->_right, successorKey);
        }
    }
    // Target node's key is smaller than
    // the given key then search to right
    else if (node->getValue() < key)
    {
        node->_right = Remove(node->_right, key);
    }
    // Target node's key is greater than
    // the given key then search to left
    else
    {
        node->_left = Remove(node->_left, key);
    }

    // Return the updated BST
    return node;
}
