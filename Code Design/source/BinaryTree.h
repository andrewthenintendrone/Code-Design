#pragma once
#include "aieException.h"

// TreeNode struct
template<typename T>
struct TreeNode
{
    T value;
    TreeNode* left;
    TreeNode* right;
};

//################################################//
//  Binary Tree Class                             //
//################################################//
template<typename T>
class BinaryTree
{
public:
    // constructors and destructors
    BinaryTree() { root = nullptr; }
    ~BinaryTree() { destroy(); }

    void insert(T newValue)
    {
        if (root != nullptr)
        {
            insert(newValue, root);
        }
        else
        {
            root = new TreeNode<T>;
            root->value = newValue;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    TreeNode<T>* search(T searchValue)
    {
        return search(searchValue, root);
    }

    void destroy()
    {
        destroy(root);
    }

private:
    TreeNode<T>*search(T searchValue, TreeNode<T>* currentNode)
    {
        if (currentNode != nullptr)
        {
            if (searchValue == currentNode->value)
            {
                return currentNode;
            }
            if (searchValue < currentNode->value)
            {
                return search(searchValue, currentNode->left);
            }
            else
            {
                return search(searchValue, currentNode->right);
            }
        }
        else
        {
            return nullptr;
        }
    }

    void insert(T newValue, TreeNode<T>* currentNode)
    {
        if (newValue < currentNode->value)
        {
            if (currentNode->left != nullptr)
            {
                insert(newValue, currentNode->left);
            }
            else
            {
                currentNode->left = new TreeNode<T>;
                currentNode->left->value = newValue;
                // new leaf has no children yet
                currentNode->left->left = nullptr;
                currentNode->left->right = nullptr;
            }
        }
        else if (newValue >= currentNode->value)
        {
            if (currentNode->right != nullptr)
            {
                insert(newValue, currentNode->right);
            }
            else
            {
                currentNode->right = new TreeNode<T>;
                currentNode->right->value = newValue;
                // new leaf has no children yet
                currentNode->right->left = nullptr;
                currentNode->right->right = nullptr;
            }
        }
    }

    // destroys everything under the given leaf
    void destroy(TreeNode<T>* currentNode)
    {
        if (currentNode != nullptr)
        {
            destroy(currentNode->left);
            destroy(currentNode->right);
            delete currentNode;
        }
    }

    TreeNode<T>* root;
};