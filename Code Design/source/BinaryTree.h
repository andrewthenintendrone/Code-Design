#pragma once
#include "aieException.h"

//################################################//
//  Tree Node Struct                              //
//################################################//
template<typename T>
class TreeNode
{
public:
    TreeNode() : parent(nullptr), left(nullptr), right(nullptr) {}
    ~TreeNode() {}

    T value;
    TreeNode<T>* parent;
    TreeNode<T>* left;
    TreeNode<T>* right;
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
        TreeNode<T>* foundNode = search(searchValue, root);
        if (foundNode != nullptr)
        {
            remove(foundNode);
        }
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
                currentNode->left->parent = currentNode;
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
                currentNode->right->parent = currentNode;
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

    // removes this treeNode from the tree
    void remove(TreeNode<T>* node)
    {
        if (node)
        {
            // 2 children
            if ((node->left) && (node->right))
            {
                std::cout << "2 children";
            }
            // 1 child
            if ((!node->left) ^ (!node->right))
            {
                
            }
            // 0 children
            if ((!node->left) && (!node->right))
            {
                node = nullptr;
                delete node;
            }
        }
    }

    TreeNode<T>* root;
};