#pragma once

// Standard Template Library implementations

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
    BinaryTree<int> myTree;
    myTree.insert(50);
    myTree.insert(92);
    myTree.insert(74);
    myTree.insert(36);
    myTree.insert(49);
    myTree.insert(28);
    myTree.insert(61);
    myTree.insert(90);
    myTree.insert(33);
    myTree.insert(36);

    if (myTree.search(36)->value == 36)
    {
        return true;
    }
    return false;
}