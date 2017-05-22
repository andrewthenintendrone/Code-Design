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

    // adds a new treeNode as the left child
    void insertLeft(T newValue)
    {
        if (left == nullptr)
        {
            left = new treeNode(newValue);
        }
    }

    // adds a new treeNode as the right child
    void insertRight(T newValue)
    {
        if (right == nullptr)
        {
            right = new treeNode(newValue);
        }
    }

private:
    T value;

    // children
    treeNode* left;
    treeNode* right;
};