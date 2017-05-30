#pragma once

// my implementations
#include "linkedList.h"
#include "BinaryTree.h"
#include "HashTable.h"

// extra includes
#include <iostream>
#include <string>

// tests that my implementations are working properly
bool runUnitTest()
{
    List<int> myList;
    for (unsigned int i = 0; i < 10; i++)
    {
        myList.pushBack(i);
    }

    for (auto iter = myList.begin(); iter != myList.end(); iter++)
    {
        std::cout << iter.getNode()->value << std::endl;
    }



    // test Linked List against
    BinaryTree<int> myTree;
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(18);

    myTree.remove(10);

    return true;
}