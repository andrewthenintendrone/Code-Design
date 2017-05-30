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
    myTree.insert(10);
    myTree.insert(5);
    myTree.insert(3);
    myTree.insert(7);
    myTree.insert(15);
    myTree.insert(12);

    myTree.remove(12);

    return false;
}