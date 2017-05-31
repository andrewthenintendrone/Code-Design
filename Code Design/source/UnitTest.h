#pragma once

// my implementations
#include "LinkedList.h"
#include "BinaryTree.h"
#include "HashTable.h"

// extra includes
#include <iostream>
#include <string>

// tests that my implementations are working properly
bool runUnitTest()
{
    //################################################//
    //  Linked List Tests                             //
    //################################################//
    std::cout << "Creating LinkedList" << std::endl;
    LinkedList<int> myList;
    std::cout << "LinkedList successfully created" << std::endl << std::endl;


    std::cout << "Adding items to LinkedList" << std::endl;
    myList.pushBack(4);
    myList.pushBack(8);
    myList.pushBack(15);
    myList.pushBack(16);
    myList.pushBack(23);
    myList.pushBack(42);
    std::cout << std::endl << "All items added to LinkedList" << std::endl << std::endl;


    std::cout << "Reading items from LinkedList" << std::endl;
    for (auto iter = myList.begin(); iter != myList.end(); iter++)
    {
        std::cout << iter.getNode()->value << " ";
    }
    std::cout << std::endl << "All items read from LinkedList" << std::endl << std::endl;


    std::cout << std::endl << "Clearing LinkedList" << std::endl;
    myList.clear();

    if (!myList.empty())
    {
        std::cout << "LinkedList failed to clear" << std::endl;
        Sleep(500);
        return false;
    }

    std::cout << "LinkedList successfully cleared" << std::endl;
    system("pause");

    //################################################//
    //  BinaryTree Tests                              //
    //################################################//
    system("cls");
    std::cout << "Creating BinaryTree" << std::endl;
    BinaryTree<int> myTree;
    std::cout << "BinaryTree successfully created" << std::endl << std::endl;


    std::cout << "Adding Items To BinaryTree" << std::endl;
    myTree.insert(60);
    myTree.insert(41);
    myTree.insert(74);
    myTree.insert(16);
    myTree.insert(53);
    myTree.insert(65);
    myTree.insert(25);
    myTree.insert(46);
    myTree.insert(55);
    myTree.insert(63);
    myTree.insert(70);
    myTree.insert(42);
    myTree.insert(62);
    myTree.insert(64);
    std::cout << std::endl << "All items added to BinaryTree" << std::endl << std::endl;


    std::cout << "Removing a TreeNode with no children" << std::endl;
    myTree.remove(42);
    if (myTree.search(42))
    {
        std::cout << "TreeNode was not successfully removed" << std::endl;
        system("pause");
        return false;
    }
    std::cout << "TreeNode was successfully removed" << std::endl << std::endl;


    std::cout << "Removing a TreeNode with one child" << std::endl;
    myTree.remove(16);
    if (myTree.search(16))
    {
        std::cout << "TreeNode was not successfully removed" << std::endl;
        system("pause");
        return false;
    }
    std::cout << "TreeNode was successfully removed" << std::endl << std::endl;


    std::cout << "Removing a TreeNode with two children" << std::endl;
    myTree.remove(60);
    if (myTree.search(60))
    {
        std::cout << "TreeNode was not successfully removed" << std::endl;
        system("pause");
        return false;
    }
    std::cout << "TreeNode was successfully removed" << std::endl << std::endl;


    return true;
}