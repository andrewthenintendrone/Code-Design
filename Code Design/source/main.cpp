#include <iostream>
#include "linkedList.h"
#include "treeNode.h"
#include "HashTable.h"
#include "sumTo.h"
#include "digitalRoot.h"
#include <aieLog.h>
#include <aieException.h>
#include <Windows.h>
#include <string>

std::string g_exeFolder;

/*******************************************************************************
This function returns the full path to the folder that contains the current
executable. Note that there is NO trailing backslash.
********************************************************************************/
std::string getExecutableFolder()
{
    char buffer[MAX_PATH];
    GetModuleFileName(NULL, buffer, MAX_PATH);
    char *pos;
    if (pos = strrchr(buffer, '\\'))
    {
        *pos = 0;
    }

    return buffer;
}

int letterToNumber(char letter)
{
    if (letter >= 'a' && letter <= 'z')
    {
        return (int)(letter - 'a' + 1);
    }
    else if (letter >= 'A' && letter <= 'Z')
    {
        return (int)(letter - 'A' + 1);
    }
    else
    {
        return 0;
    }
}

template<typename dataType>
// returns true if input is even
bool isEven(dataType input)
{
    return (input % 2 == 0);
}

int main()
{
    try
    {
        // get executable folder
        g_exeFolder = getExecutableFolder();

        // Specify an ASCII log file for our application to use. This will be called
        // "log.txt" and will write itself into the executable's folder.
        aie::Log::instance().setLog(g_exeFolder + "\\log.txt");

        // Enable logging for all aie exceptions. When enabled, aie exceptions will
        // also record full details into the log.
        aie::Exception::enableLogging(true);

        // log that the program has started
        aieLOG("Application started");

        // create a Hash Table
        HashTable<unsigned int>table(10);
        table["one"] = 1;
        table["two"] = 2;
        table["three"] = 3;
        table["four"] = 4;
        table["five"] = 5;
        table["six"] = 6;

        HashTable<unsigned int>table2(100);
        table2 = table;

        std::cout << table2["five"] << std::endl;
        std::cout << table2["four"] << std::endl;
        std::cout << table2["three"] << std::endl;
        std::cout << table2["two"] << std::endl;
        std::cout << table2["one"] << std::endl;
        std::cout << table2["six"] << std::endl;
        //treeNode<int> myTree(10);
        //myTree.insert(5);
        //myTree.insert(7);
        //myTree.insert(15);
        //myTree.insert(12);
        //myTree.insert(17);
        //myTree.insert(14);

        //std::cout << "found " << myTree.findNode(15)->getValue() << std::endl;

        //myTree.getRoot()->getRight()->remove();

        ////std::cout << std::hex << HashFunction::default<char*>((char*)"Andrew") << std::endl << std::dec;

        //// create List of int
        //List<int> myList;

        //// push some numbers onto the back
        //myList.pushBack(5);
        //myList.pushBack(6);
        //myList.pushBack(7);
        //myList.pushBack(8);

        //// push some more numbers onto the front
        //myList.pushFront(4);
        //myList.pushFront(3);
        //myList.pushFront(2);
        //myList.pushFront(1);

        //// create function pointer
        //bool(*predicate)(int);
        //predicate = isEven;

        //// remove values from list that meet the predicate
        //myList.remove(predicate);

        //// remove any 7s
        //myList.remove(7);

        //// print out each value using an iterator
        //for (auto iter = myList.begin(); iter != myList.end(); iter++)
        //{
        //    std::cout << iter.getNode()->value << " ";
        //}
        //std::cout << std::endl;

        //// print out the number of elements
        //std::cout << "There are " << myList.count() << " elements." << std::endl;

        //// clear the list
        //myList.clear();

        //aieASSERT(myList.empty());
    }
    catch (const std::exception& e)
    {
        std::cout << "\n\n\n" << e.what() << "\n\n\n";
    }

    catch (const aie::Exception& e)
    {
        std::cout << "\n\n\n" << e.reason() << "\n\n\n";
    }

    system("pause");
    return 0;
}