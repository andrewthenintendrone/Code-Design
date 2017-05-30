#pragma once
#include "aieException.h"

//################################################//
//  Tree Node Struct                              //
//################################################//
template<typename T>
class TreeNode
{
public:
    TreeNode() : left(nullptr), right(nullptr) {}
    ~TreeNode() {}

    T value;
    TreeNode* parent;
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
    //################################################//
    //  Constructors and Destructors                  //
    //################################################//
    BinaryTree() { root = nullptr; }
    ~BinaryTree() { destroy(); }

    //################################################//
    //  Public Methods                                //
    //################################################//

    // inserts a new value into the BinaryTree
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
            root->parent = nullptr;
        }
    }

    // returns the TreeNode with the value of searchValue
    TreeNode<T>* search(T searchValue)
    {
        return search(searchValue, root);
    }

    // destroys the BinaryTree
    void destroy()
    {
        destroy(root);
    }

    // removes the TreeNode with the value of searchValue
    void remove(T searchValue)
    {
        remove(search(searchValue));
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
                currentNode->parent = currentNode;
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
                currentNode->parent = currentNode;
            }
        }
    }

    // destroys everything under the given leaf
    void destroy(TreeNode<T>* currentNode)
    {
        if (currentNode != nullptr)
        {
            if (currentNode->left != nullptr)
            {
                destroy(currentNode->left);
            }
            if (currentNode->right)
            {
                destroy(currentNode->right);
            }
            delete currentNode;
        }
    }

    void remove(TreeNode<T>* node)
    {
        // 2 children
        if (node->left != nullptr && node != nullptr)
        {
            // find the treeNode with the smallest value larger than this treeNodes value
            TreeNode<T>* targetNode = node->right;

            while (targetNode->left != nullptr)
            {
                targetNode = targetNode->left;
            }

            // copy that treeNodes value
            node->value = targetNode->value;

            // remove the target treeNode
            remove(targetNode);
        }
        // 1 child
        else if ((node->left != nullptr) ^ (node->right != nullptr))
        {
            if (node->parent != nullptr)
            {
                TreeNode<T>* parentLink = (node == node->parent->left ? node->parent->left : node->parent->right);
                parentLink = nullptr;
                std::cout << "removing a node with a value of " << node->value << std::endl;
                delete node;
            }
        }
        // 0 children
        else if (node->left == nullptr && node->right == nullptr)
        {
            if (node->parent != nullptr)
            {
                TreeNode<T>* parentLink = (node == node->parent->left ? node->parent->left : node->parent->right);
                parentLink = nullptr;
                std::cout << "removing a node with a value of " << node->value << std::endl;
                delete node;
            }
        }
    }

    TreeNode<T>* root;
};