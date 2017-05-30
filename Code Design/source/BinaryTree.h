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
    BinaryTree() : root = nullptr; {}
    ~BinaryTree() { destroyTree(); }

    void insert(T key);
    TreeNode* search(T key);
    void destroy();

private:
    TreeNode* search(T key, TreeNode* leaf);

    void insert(T key, TreeNode* leaf)
    {
        if (key < leaf->value)
        {
            if (leaf->left != nullptr)
            {
                insert()
            }
        }
    }

    // destroys everything under the given leaf
    void destroy(TreeNode* leaf)
    {
        if (leaf != nullptr)
        {
            destroyTree(leaf->left);
            destroyTree(leaf->right);
            delete leaf;
        }
    }
    TreeNode* root;
};