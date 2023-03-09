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
 * This class supports AVL ADT                                      *
 *******************************************************************/

#include "MT_DSA_AVLADT.h"

MT_DSA_AVLADT::MT_DSA_AVLADT() : MT_DSA_HierarchicalTree()
{

}

mt_int MT_DSA_AVLADT::GetHeightOfNode(MT_DSA_TreeObject * node)
{
    // Return the Height of the node
    // Return -1 if the node is NULL
    return node == NULL ? -1 : node->getHeight();
}

MT_DSA_TreeObject * MT_DSA_AVLADT::RotateLeft(MT_DSA_TreeObject * node)
{
    // The node must have a right child

    // Create a new node as a result
    // that will be a balanced node
    MT_DSA_TreeObject * balancedNode = node->_right;

    // the balanced node will replace
    // the current node
    balancedNode->_parent = node->_parent;

    // the current node will be child
    // of the balanced node
    node->_parent = balancedNode;

    // The right child of current node
    // will be balanced node's left child
    node->_right = balancedNode->_left;

    // If balanced node has left child
    // point the parent to the current node
    if (balancedNode->_left != NULL)
        balancedNode->_left->_parent = node;

    // The left child of balanced node
    // will be the current node
    balancedNode->_left = node;

    // Refresh the node's height
    node->setHeight(std::max(
        GetHeightOfNode(node->_left),
        GetHeightOfNode(node->_right)) + 1);

    // Refresh the balanced node's height
    balancedNode->setHeight(std::max(
        GetHeightOfNode(balancedNode->_left),
        GetHeightOfNode(balancedNode->_right)) + 1);

    // return balancedNode
    return balancedNode;
}

MT_DSA_TreeObject * MT_DSA_AVLADT::RotateRight(MT_DSA_TreeObject * node)
{
    // The node must have a left child

    // Create a new node as a result
    // that will be a balanced node
    MT_DSA_TreeObject * balancedNode = node->_left;

    // the balanced node will replace
    // the current node
    balancedNode->_parent = node->_parent;

    // the current node will be child
    // of the balanced node
    node->_parent = balancedNode;

    // The left child of current node
    // will be balanced node's right child
    node->_left = balancedNode->_right;

    // If balanced node has right child
    // point the parent to the current node
    if (balancedNode->_right != NULL)
        balancedNode->_right->_parent = node;

    // The right child of balanced node
    // will be the current node
    balancedNode->_right = node;

    // Refresh the node's height
    node->setHeight(std::max(
        GetHeightOfNode(node->_left),
        GetHeightOfNode(node->_right)) + 1);

    // Refresh the balanced node's height
    balancedNode->setHeight(std::max(
        GetHeightOfNode(balancedNode->_left),
        GetHeightOfNode(balancedNode->_right)) + 1);

    // return balancedNode
    return balancedNode;
}

MT_DSA_TreeObject *MT_DSA_AVLADT::Insert(MT_DSA_TreeObject *node, MT_DSA_TreeObject *obj, int key)
{
    // If AVL tree doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if (node == NULL)
    {
        node = obj;
        node->setValue(key);
        node->_left = NULL;
        node->_right = NULL;
        node->_parent = NULL;
        node->setHeight(0);
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

    // Get the balance
    int balance =
        GetHeightOfNode(node->_left) - GetHeightOfNode(node->_right);

    // If left heavy
    if (balance == 2)
    {
        // Get left subtree's height
        int balance2 =
            GetHeightOfNode(node->_left->_left) -
            GetHeightOfNode(node->_left->_right);

        if (balance2 == 1)
        {
            node = RotateRight(node);
        }
        else
        {
            node->_left = RotateLeft(node->_left);
            node = RotateRight(node);
        }
    }
    // If right heavy
    else if (balance == -2)
    {
        // Get right subtree's height
        int balance2 =
            GetHeightOfNode(node->_right->_left) -
            GetHeightOfNode(node->_right->_right);

        if (balance2 == -1)
            node = RotateLeft(node);
        else
        { // 1
            node->_right = RotateRight(node->_right);
            node = RotateLeft(node);
        }
    }

    // Refresh node's height
    node->setHeight(std::max(
        GetHeightOfNode(node->_left),
        GetHeightOfNode(node->_right)) + 1);

    // Return the updated AVL tree
    return node;
}

MT_DSA_TreeObject *MT_DSA_AVLADT::Remove(MT_DSA_TreeObject *node, int key)
{
    // The given node is
    // not found in AVL tree
    if (node == NULL)
        return NULL;

    // Target node is found
    if (node->getValue() == key)
    {
        // If the node is a leaf node
        // The node can be safely removed
        if (node->_left == NULL && node->_right == NULL)
        {
            this->_mttable.removeObject(node);
            node = NULL;
        }
        // The node have only one child at right
        else if (node->_left == NULL && node->_right != NULL)
        {
            // The only child will be connected to
            // the parent's of node directly
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
        node->_right = Remove(node->_right, key);
    // Target node's key is greater than
    // the given key then search to left
    else
        node->_left = Remove(node->_left, key);

    // Only perform rotation if node is not NULL
    if (node != NULL)
    {
        // Get the balance
        int balance =
            GetHeightOfNode(node->_left) - GetHeightOfNode(node->_right);

        // If left heavy
        if (balance == 2)
        {
            // Get left subtree's height
            int balance2 =
                GetHeightOfNode(node->_left->_left) -
                GetHeightOfNode(node->_left->_right);

            if (balance2 == 1)
            {
                node = RotateRight(node);
            }
            else
            {
                node->_left = RotateLeft(node->_left);
                node = RotateRight(node);
            }
        }
        // If right heavy
        else if (balance == -2)
        {
            // Get right subtree's height
            int balance2 =
                GetHeightOfNode(node->_right->_left) -
                GetHeightOfNode(node->_right->_right);

            if (balance2 == -1)
                node = RotateLeft(node);
            else
            { // 1
                node->_right = RotateRight(node->_right);
                node = RotateLeft(node);
            }
        }

        // Refresh node's height
        node->setHeight(std::max(
            GetHeightOfNode(node->_left),
            GetHeightOfNode(node->_right)) + 1);

    }

    // Return the updated AVL tree
    return node;
}
