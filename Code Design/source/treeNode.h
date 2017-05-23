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
    treeNode* getParent()
    {
        return parent;
    }

    // returns the left treeNode
    treeNode* getLeft()
    {
        return left;
    }

    // returns the right treeNode
    treeNode* getRight()
    {
        return right;
    }

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

    // returns true if the treeNode is a leaf
    bool isLeaf()
    {
        return(numChildren() == 0);
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

    // removes the treeNode from the tree
    void remove()
    {
        if (isLeaf())
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
                std::cout << "Deleting a node with a value of " << value << std::endl;
                delete this;
            }
        }
        else if(numChildren() == 1)
        {
            if (parent != nullptr)
            {
                if (this == parent->left)
                {
                    if (left)
                    {
                        parent->left = left;
                    }
                    if(right)
                    {
                        parent->left = right;
                    }
                }
                if (this == parent->right)
                {
                    if (left)
                    {
                        parent->right = left;
                    }
                    if (right)
                    {
                        parent->right = right;
                    }
                }
                std::cout << "Deleting a node with a value of " << value << std::endl;
                delete this;
            }
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