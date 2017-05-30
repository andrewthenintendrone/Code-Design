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
    myTree.insert(7);
    myTree.insert(15);
    myTree.insert(12);
    myTree.insert(17);
    myTree.insert(14);

    myTree.remove(10);

    return false;
}