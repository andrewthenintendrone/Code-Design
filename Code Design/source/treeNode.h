#pragma once

template<typename T>
class treeNode
{
public:
    treeNode(T newValue) : value(newValue), parent(nullptr), left(nullptr), right(nullptr) {}

    // returns the treeNodes value
    T getValue()
    {
        return value;
    }

    // returns the parent
    treeNode& getParent()
    {
        return parent;
    }

    // returns the left treeNode
    treeNode& getLeft()
    {
        return left;
    }

    // returns the right treeNode
    treeNode& getRight()
    {
        return right;
    }

    // returns the number of nodes from 0 to 2
    unsigned int numNodes()
    {
        if (left && right )
        {
            return 2;
        }
        if (left ^^ right)
        {
            return 1;
        }
        return 0;
    }

    // inserts a new treeNode automatically
    void insert(T newValue)
    {
        // find place for value
        if (newValue < value)
        {
            if (left == nullptr)
            {
                insertLeft(newValue);
            }
            else
            {
                left->insert(newValue);
            }
        }
        else
        {
            if (right == nullptr)
            {
                insertRight(newValue);
            }
            else
            {
                right->insert(newValue);
            }
        }
    }

    // adds a new treeNode as the left child
    void insertLeft(T newValue)
    {
        left = new treeNode(newValue);
        left->parent = this;
    }

    // adds a new treeNode as the right child
    void insertRight(T newValue)
    {
        right = new treeNode(newValue);
        right->parent = this;
    }

private:
    // value
    T value;

    // parent
    treeNode* parent;

    // children
    treeNode* left;
    treeNode* right;
};