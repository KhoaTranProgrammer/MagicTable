#include "MT_DSA_HierarchicalTree.h"
#include <iostream>

MT_DSA_HierarchicalTree::MT_DSA_HierarchicalTree() : _root(NULL)
{

}

mt_void MT_DSA_HierarchicalTree::createTable(int w, int h, int col, int row)
{
    this->_mttable.createTable(w, h, col, row);
}

MT_DSA_TreeObject *MT_DSA_HierarchicalTree::Insert(MT_DSA_TreeObject *node, MT_DSA_TreeObject *obj, int key)
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

    printTree(this->_root, col/2, 0, h);

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

mt_void MT_DSA_HierarchicalTree::clearData()
{
    this->_mttable.clearData();
}
