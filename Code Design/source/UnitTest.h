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

    std::cout << "LinkedList successfully cleared" << std::endl << std::endl;
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
    std::cout << "TreeNode was successfully removed" << std::endl << std::endl << std::endl;

    system("pause");

    //################################################//
    //  HashTable Tests                               //
    //################################################//
    system("cls");
    std::cout << "Creating HashTable" << std::endl;
    HashTable<int> myHashTable(5);
    std::cout << "HashTable successfully created" << std::endl << std::endl;


    std::cout << "Adding Items To HashTable" << std::endl;
    myHashTable["Hydrogen"] = 1;
    myHashTable["Helium"] = 2;
    myHashTable["Lithium"] = 3;
    myHashTable["Beryllium"] = 4;
    myHashTable["Boron"] = 5;
    myHashTable["Carbon"] = 6;
    myHashTable["Nitrogen"] = 7;
    myHashTable["Oxygen"] = 8;
    myHashTable["Fluorine"] = 9;
    myHashTable["Neon"] = 10;
    myHashTable["Sodium"] = 11;
    myHashTable["Magnesium"] = 12;
    myHashTable["Aluminum"] = 13;
    myHashTable["Silicon"] = 14;
    myHashTable["Phosphorus"] = 15;
    myHashTable["Sulfur"] = 16;
    myHashTable["Chlorine"] = 17;
    myHashTable["Argon"] = 18;
    myHashTable["Potassium"] = 19;
    myHashTable["Calcium"] = 20;
    myHashTable["Scandium"] = 21;
    myHashTable["Titanium"] = 22;
    myHashTable["Vanadium"] = 23;
    myHashTable["Chromium"] = 24;
    myHashTable["Manganese"] = 25;
    myHashTable["Iron"] = 26;
    myHashTable["Cobalt"] = 27;
    myHashTable["Nickel"] = 28;
    myHashTable["Copper"] = 29;
    myHashTable["Zinc"] = 30;
    myHashTable["Gallium"] = 31;
    myHashTable["Germanium"] = 32;
    myHashTable["Arsenic"] = 33;
    myHashTable["Selenium"] = 34;
    myHashTable["Bromine"] = 35;
    myHashTable["Krypton"] = 36;
    myHashTable["Rubidium"] = 37;
    myHashTable["Strontium"] = 38;
    myHashTable["Yttrium"] = 39;
    myHashTable["Zirconium"] = 40;
    myHashTable["Niobium"] = 41;
    myHashTable["Molybdenum"] = 42;
    myHashTable["Technetium"] = 43;
    myHashTable["Ruthenium"] = 44;
    myHashTable["Rhodium"] = 45;
    myHashTable["Palladium"] = 46;
    myHashTable["Silver"] = 47;
    myHashTable["Cadmium"] = 48;
    myHashTable["Indium"] = 49;
    myHashTable["Tin"] = 50;
    myHashTable["Antimony"] = 51;
    myHashTable["Tellurium"] = 52;
    myHashTable["Iodine"] = 53;
    myHashTable["Xenon"] = 54;
    myHashTable["Cesium"] = 55;
    myHashTable["Barium"] = 56;
    myHashTable["Lanthanum"] = 57;
    myHashTable["Cerium"] = 58;
    myHashTable["Praseodymium"] = 59;
    myHashTable["Neodymium"] = 60;
    myHashTable["Promethium"] = 61;
    myHashTable["Samarium"] = 62;
    myHashTable["Europium"] = 63;
    myHashTable["Gadolinium"] = 64;
    myHashTable["Terbium"] = 65;
    myHashTable["Dysprosium"] = 66;
    myHashTable["Holmium"] = 67;
    myHashTable["Erbium"] = 68;
    myHashTable["Thulium"] = 69;
    myHashTable["Ytterbium"] = 70;
    myHashTable["Lutetium"] = 71;
    myHashTable["Hafnium"] = 72;
    myHashTable["Tantalum"] = 73;
    myHashTable["Tungsten"] = 74;
    myHashTable["Rhenium"] = 75;
    myHashTable["Osmium"] = 76;
    myHashTable["Iridium"] = 77;
    myHashTable["Platinum"] = 78;
    myHashTable["Gold"] = 79;
    myHashTable["Mercury"] = 80;
    myHashTable["Thallium"] = 81;
    myHashTable["Lead"] = 82;
    myHashTable["Bismuth"] = 83;
    myHashTable["Polonium"] = 84;
    myHashTable["Astatine"] = 85;
    myHashTable["Radon"] = 86;
    myHashTable["Francium"] = 87;
    myHashTable["Radium"] = 88;
    myHashTable["Actinium"] = 89;
    myHashTable["Thorium"] = 90;
    myHashTable["Protactinium"] = 91;
    myHashTable["Uranium"] = 92;
    myHashTable["Neptunium"] = 93;
    myHashTable["Plutonium"] = 94;
    myHashTable["Americium"] = 95;
    myHashTable["Curium"] = 96;
    myHashTable["Berkelium"] = 97;
    myHashTable["Californium"] = 98;
    myHashTable["Einsteinium"] = 99;
    myHashTable["Fermium"] = 100;
    myHashTable["Mendelevium"] = 101;
    myHashTable["Nobelium"] = 102;
    myHashTable["Lawrencium"] = 103;
    myHashTable["Rutherfordium"] = 104;
    myHashTable["Dubnium"] = 105;
    myHashTable["Seaborgium"] = 106;
    myHashTable["Bohrium"] = 107;
    myHashTable["Hassium"] = 108;
    myHashTable["Meitnerium"] = 109;
    myHashTable["Darmstadtium"] = 110;
    myHashTable["Roentgenium"] = 111;
    myHashTable["Ununbium"] = 112;
    myHashTable["Ununtrium"] = 113;
    myHashTable["Ununquadium"] = 114;
    myHashTable["Ununpentium"] = 115;
    myHashTable["Ununhexium"] = 116;
    myHashTable["Ununseptium"] = 117;
    myHashTable["Ununoctium"] = 118;
    myHashTable["Andrewnium"] = 119;

    std::cout << std::endl << "All items added to HashTable" << std::endl << std::endl;

    std::string chosenElement;
    bool validElement = false;
    while (validElement == false)
    {
        // get an element from the user
        std::cout << "Input an element from the periodic table: ";
        std::cin >> chosenElement;
        for (char & c : chosenElement)
        {
            c = (c == chosenElement[0] ? toupper(c) : tolower(c));
        }
        std::cout << "Element ";
        if (myHashTable[chosenElement] != 0)
        {
            validElement = true;
            std::cout << myHashTable[chosenElement] << " (also known as " << chosenElement << ") ";
            if (myHashTable.remove(chosenElement))
            {
                std::cout << " was successfully removed" << std::endl;
            }
        }
        else
        {
            std::cout << chosenElement << " could not be found." << std::endl;
        }
    }

    system("pause");


    return true;
}