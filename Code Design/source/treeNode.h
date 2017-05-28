#pragma once
#include "aieException.h"

//################################################//
//  Tree Node Class                               //
//################################################//
template<typename dataType>
class treeNode
{
public:
    /**********************************/
    /*  CONSTRUCTORS AND DESTRUCTORS  */
    /**********************************/
    treeNode(dataType newValue) : value(newValue), parent(nullptr), left(nullptr), right(nullptr) {}
    
    /*************************/
    /*  GETTERS AND SETTERS  */
    /*************************/

    // returns the treeNodes value
    dataType getValue()
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

    // returns a pointer to the treeNode with the specified value
    treeNode* findNode(dataType valueToFind)
    {
        treeNode* currentNode = getRoot();

        while (true)
        {
            if (currentNode->value == valueToFind)
            {
                return currentNode;
            }
            if(currentNode->value > valueToFind)
            {
                if (currentNode->left == nullptr)
                {
                    return nullptr;
                }
                currentNode = currentNode->left;
            }
            if (currentNode->value < valueToFind)
            {
                if (currentNode->right == nullptr)
                {
                    return nullptr;
                }
                currentNode = currentNode->right;
            }
        }
    }

    // returns a pointer to the only child treeNode
    treeNode* getOnlyChild()
    {
        aieASSERT(getNumChildren() == 1);
        return (left != nullptr ? left : right);
    }

    // returns the pointer to this treeNode from its parent
    treeNode* getParentsPointerToMe()
    {
        if (this == parent->left)
        {
            return parent->left;
        }
        else
        {
            return parent->right;
        }
    }

    // returns the number of children from 0 to 2
    unsigned int getNumChildren()
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

    /*************************/
    /*  INSERTION            */
    /*************************/

    // takes a value and finds a place to create a new treeNode for it
    void insert(dataType newValue)
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
                left = new treeNode(newValue);
                left->parent = this;
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
                right = new treeNode(newValue);
                right->parent = this;
            }
        }
    }

    /*************************/
    /*  REMOVAL              */
    /*************************/

    // removes this treeNode from the tree
    void remove()
    {
        // 0 children
        if (getNumChildren() == 0)
        {
            if (parent != nullptr)
            {
                treeNode* parentLink = getParentsPointerToMe();
                parentLink = nullptr;
                std::cout << "removing a node with a value of " << value << std::endl;
                delete this;
            }
        }

        // 1 child
        else if(getNumChildren() == 1)
        {
            if (parent != nullptr)
            {
                treeNode* parentLink = getParentsPointerToMe();
                parentLink = getOnlyChild();
                std::cout << "removing a node with a value of " << value << std::endl;
                delete this;
            }
        }

        // 2 children
        else if (getNumChildren() == 2)
        {
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
    dataType value;

    // parent
    treeNode* parent;

    // children
    treeNode* left;
    treeNode* right;
};