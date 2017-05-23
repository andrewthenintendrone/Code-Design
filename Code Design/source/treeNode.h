#pragma once
#include <aieException.h>

template<typename T>
class treeNode
{
public:
    // constructor
    treeNode(T newValue) : value(newValue), parent(nullptr), left(nullptr), right(nullptr) {}

    // returns the treeNodes value
    T getValue()
    {
        return value;
    }

    // returns a pointer to the parent treeNode
    treeNode* getParent()
    {
        return parent;
    }

    // returns a pointer to the left child treeNode
    treeNode* getLeft()
    {
        return left;
    }

    // returns a pointer to the right child treeNode
    treeNode* getRight()
    {
        return right;
    }

    // returns a pointer to the treeNode at the root of the tree
    treeNode* getRoot()
    {
        treeNode* root = this;

        while (root->parent != nullptr)
        {
            root = root->parent;
        }

        return root;
    }

    // returns a pointer to the only child treeNode
    treeNode* getOnlyChild()
    {
        aieASSERT(numChildren() == 1);
        return (left != nullptr ? left : right);
    }

    // maybe change this
    // returns the number of children from 0 to 2
    unsigned int numChildren()
    {
        if (left && right)
        {
            return 2;
        }
        if ((left != nullptr) ^ (right != nullptr))
        {
            return 1;
        }
        return 0;
    }


    // takes a value and finds a place to create a new treeNode for it
    void insert(T newValue)
    {
        // inserted value is lower than this treeNodes value
        if (newValue < value)
        {
            if (left)
            {
                // recur this function
                left->insert(newValue);
            }
            else
            {
                insertLeft(newValue);
            }
        }
        // inserted value is equal to or higher than this treeNodes value
        else
        {
            if (right)
            {
                // recur this function
                right->insert(newValue);
            }
            else
            {
                insertRight(newValue);
            }
        }
    }

    // creates a new treeNode and sets it as the left child
    void insertLeft(T newValue)
    {
        left = new treeNode(newValue);
        left->parent = this;
    }

    // creates a new treeNode and sets it as the right child
    void insertRight(T newValue)
    {
        right = new treeNode(newValue);
        right->parent = this;
    }

    // removes this treeNode from the tree
    void remove()
    {
        // leaf
        if (numChildren() == 0)
        {
            if (parent != nullptr)
            {
                if (this == parent->left)
                {
                    parent->left = nullptr;
                }
                else if (this == parent->right)
                {
                    parent->right = nullptr;
                }
                std::cout << "removing a node with a value of " << value << std::endl;
                delete this;
            }
        }

        // 1 child
        else if(numChildren() == 1)
        {
            if (parent != nullptr)
            {
                if (this == parent->left)
                {
                    parent->left = getOnlyChild();
                }
                else
                {
                    parent->right = getOnlyChild();
                }
                std::cout << "removing a node with a value of " << value << std::endl;
                delete this;
            }
        }

        // 2 children
        else if (numChildren() == 2)
        {
            std::cout << "removing a node with a value of " << value << std::endl;

            // find the treeNode with the smallest value larger than this treeNodes value
            treeNode* targetNode = right;

            while (targetNode->left)
            {
                targetNode = targetNode->left;
            }

            // copy that treeNodes value
            value = targetNode->value;

            // remove the target treeNode
            targetNode->remove();
        }
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