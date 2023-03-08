#include "MT_DSA_HierarchicalTree.h"
#include <iostream>

MT_DSA_HierarchicalTree::MT_DSA_HierarchicalTree() : _root(NULL)
{
    _column = 0;
    _height = 0;
}

mt_void MT_DSA_HierarchicalTree::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

MT_DSA_TreeObject *MT_DSA_HierarchicalTree::Insert(MT_DSA_TreeObject *node, MT_DSA_TreeObject *obj, int key)
{
    return node;
}

void MT_DSA_HierarchicalTree::InsertWithEmptyNode(MT_DSA_TreeObject *obj, int key)
{
    _root = Insert(_root, obj, key);
}

int MT_DSA_HierarchicalTree::height(MT_DSA_TreeObject *node)
{
    if(node == NULL)
    {
        return 0;
    }
    return max(height(node->_left), height(node->_right)) + 1;
}

int MT_DSA_HierarchicalTree::getcol(int h)
{
    if (h == 1)
        return 1;
    return getcol(h-1) + getcol(h-1) + 1;
}

void MT_DSA_HierarchicalTree::PreorderTraversal()
{
    this->_mttable.clearHistory();

    int h = height(this->_root);
    int col = getcol(h);

    this->_column = col;
    this->_height = h;

    this->_mttable.updateTable(col, h);
    printTree(this->_root, col / 2, 0, h);
}

void MT_DSA_HierarchicalTree::printTree(MT_DSA_TreeObject *node, int col, int row, int height)
{
    if(node == NULL)
    {
        return;
    }
    node->_row = row;
    node->_col = col;
    this->_mttable.updateObjectPosition(*node, node->_col, node->_row);

    printTree(node->_left, col - pow(2, height-2), row + 1, height - 1);
    printTree(node->_right, col + pow(2, height-2), row + 1, height - 1);
}

mt_void MT_DSA_HierarchicalTree::drawData()
{
    this->_mttable.drawObjects();
}

mt_void MT_DSA_HierarchicalTree::drawHistoryOne()
{
    this->_mttable.drawHistoryOne();
}

mt_void MT_DSA_HierarchicalTree::clearData()
{
    this->_mttable.clearData();
}

mt_void MT_DSA_HierarchicalTree::Remove(int key)
{
    this->_root = Remove(this->_root, key);
}

MT_DSA_TreeObject *MT_DSA_HierarchicalTree::Remove(MT_DSA_TreeObject *node, int key)
{
    return node;
}

mt_int MT_DSA_HierarchicalTree::Successor(int key)
{
    // Search the key's node first
    MT_DSA_TreeObject *keyNode = Search(this->_root, key);

    // Return the key.
    // If the key is not found or
    // successor is not found,
    // return -1
    return keyNode == NULL ? -1 : Successor(keyNode);
}

mt_int MT_DSA_HierarchicalTree::Successor(MT_DSA_TreeObject * node)
{
    // The successor is the minimum key value
    // of right subtree
    if (node->_right != NULL)
    {
        return FindMin(node->_right);
    }
    // If no any right subtree
    else
    {
        MT_DSA_TreeObject *parentNode = node->_parent;
        MT_DSA_TreeObject *currentNode = node;

        // If currentNode is not root and
        // currentNode is its right children
        // continue moving up
        while ((parentNode != NULL) && (currentNode == parentNode->_right))
        {
            currentNode = parentNode;
            parentNode = currentNode->_parent;
        }

        // If parentNode is not NULL
        // then the key of parentNode is
        // the successor of node
        return parentNode == NULL ? -1 : parentNode->getValue();
    }
}

mt_int MT_DSA_HierarchicalTree::FindMin(MT_DSA_TreeObject *node)
{
    if(node == NULL)
        return -1;
    else if(node->_left == NULL)
        return node->getValue();
    else
        return FindMin(node->_left);
}

mt_int MT_DSA_HierarchicalTree::FindMin()
{
    return FindMin(this->_root);
}

MT_DSA_TreeObject *MT_DSA_HierarchicalTree::Search(MT_DSA_TreeObject *node, int key)
{
    // The given key is not found in BST
    if (node == NULL)
        return NULL;
    // The given key is found
    else if(node->getValue() == key)
        return node;
    // The given is greater than current node's key
    else if(node->getValue() < key)
        return Search(node->_right, key);
    // The given is smaller than current node's key
    else
        return Search(node->_left, key);
}

mt_bool MT_DSA_HierarchicalTree::Search(int key)
{
    // Invoking Search() operation and passing root node
    MT_DSA_TreeObject *result = Search(this->_root, key);

    // If key is found, returns TRUE otherwise returns FALSE
    return result == NULL ? false : true;
}

mt_uint MT_DSA_HierarchicalTree::getColumn()
{
    return this->_column;
}

mt_uint MT_DSA_HierarchicalTree::getHeight()
{
    return this->_height;
}
