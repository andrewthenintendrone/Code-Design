#pragma once

template<typename T>
class treeNode
{
public:
    treeNode(T newValue) : value(newValue), left(nullptr), right(nullptr) {}

    // returns the treeNodes value
    T getValue()
    {
        return value;
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
    }

    // adds a new treeNode as the right child
    void insertRight(T newValue)
    {
        right = new treeNode(newValue);
    }

private:
    T value;

    // children
    treeNode* left;
    treeNode* right;
};