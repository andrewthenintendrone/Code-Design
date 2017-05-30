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

    // List
    std::cout << "Creating List" << std::endl;
    LinkedList<int> myList;
    std::cout << "List successfully created" << std::endl;
    std::cout << "Adding items to list" << std::endl;

    for (int i = 1; i <= 10; i++)
    {
        myList.pushBack(i);
        std::cout << i << " ";
    }

    std::cout << "\nAll items added to List" << std::endl;

    // test Linked List against
    BinaryTree<int> myTree;
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(18);

    myTree.remove(10);

    return true;
}