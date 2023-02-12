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

mt_void MT_DSA_HierarchicalTree::Remove(int key)
{
    this->_root = Remove(this->_root, key);
}

MT_DSA_TreeObject *MT_DSA_HierarchicalTree::Remove(MT_DSA_TreeObject *node, int key)
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
