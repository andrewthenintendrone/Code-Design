#include <iostream>
#include <aieLog.h>
#include <aieException.h>

std::string g_exeFolder;

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
        HashTable<unsigned int>girlsNames(10);
        girlsNames["Emily"] = 1;
        girlsNames["Hannah"] = 2;
        girlsNames["Samantha"] = 3;
        girlsNames["Sarah"] = 4;
        girlsNames["Ashley"] = 5;
        girlsNames["Alexis"] = 6;
        girlsNames["Taylor"] = 7;
        girlsNames["Jessica"] = 8;
        girlsNames["Madison"] = 9;
        girlsNames["Elizabeth"] = 10;
        girlsNames["Alyssa"] = 11;
        girlsNames["Kayla"] = 12;
        girlsNames["Megan"] = 13;
        girlsNames["Lauren"] = 14;
        girlsNames["Rachel"] = 15;
        girlsNames["Victoria"] = 16;
        girlsNames["Brianna"] = 17;
        girlsNames["Abigail"] = 18;
        girlsNames["Amanda"] = 19;
        girlsNames["Jennifer"] = 20;
        girlsNames["Olivia"] = 21;
        girlsNames["Emma"] = 22;
        girlsNames["Morgan"] = 23;
        girlsNames["Nicole"] = 24;
        girlsNames["Brittany"] = 25;
        girlsNames["Jasmine"] = 26;
        girlsNames["Alexandra"] = 27;
        girlsNames["Sydney"] = 28;
        girlsNames["Stephanie"] = 29;
        girlsNames["Rebecca"] = 30;
        girlsNames["Anna"] = 31;
        girlsNames["Julia"] = 32;
        girlsNames["Katherine"] = 33;
        girlsNames["Destiny"] = 34;
        girlsNames["Kaitlyn"] = 35;
        girlsNames["Haley"] = 36;
        girlsNames["Amber"] = 37;
        girlsNames["Allison"] = 38;
        girlsNames["Courtney"] = 39;
        girlsNames["Natalie"] = 40;
        girlsNames["Danielle"] = 41;
        girlsNames["Jordan"] = 42;
        girlsNames["Maria"] = 43;
        girlsNames["Savannah"] = 44;
        girlsNames["Mary"] = 45;
        girlsNames["Brooke"] = 46;
        girlsNames["Gabrielle"] = 47;
        girlsNames["Sara"] = 48;
        girlsNames["Shelby"] = 49;
        girlsNames["Madeline"] = 50;

        HashTable<unsigned int>boysNames(10);
        boysNames["Michael"] = 1;
        boysNames["Jacob"] = 2;
        boysNames["Matthew"] = 3;
        boysNames["Joshua"] = 4;
        boysNames["Christopher"] = 5;
        boysNames["Nicholas"] = 6;
        boysNames["Brandon"] = 7;
        boysNames["Tyler"] = 8;
        boysNames["Andrew"] = 9;
        boysNames["Austin"] = 10;
        boysNames["Joseph"] = 11;
        boysNames["Daniel"] = 12;
        boysNames["David"] = 13;
        boysNames["William"] = 14;
        boysNames["John"] = 15;
        boysNames["Zachary"] = 16;
        boysNames["Ryan"] = 17;
        boysNames["James"] = 18;
        boysNames["Anthony"] = 19;
        boysNames["Justin"] = 20;
        boysNames["Jonathan"] = 21;
        boysNames["Alexander"] = 22;
        boysNames["Robert"] = 23;
        boysNames["Kyle"] = 24;
        boysNames["Dylan"] = 25;
        boysNames["Christian"] = 26;
        boysNames["Jordan"] = 27;
        boysNames["Samuel"] = 28;
        boysNames["Noah"] = 29;
        boysNames["Benjamin"] = 30;
        boysNames["Thomas"] = 31;
        boysNames["Kevin"] = 32;
        boysNames["Jose"] = 33;
        boysNames["Nathan"] = 34;
        boysNames["Cameron"] = 35;
        boysNames["Hunter"] = 36;
        boysNames["Aaron"] = 37;
        boysNames["Ethan"] = 38;
        boysNames["Eric"] = 39;
        boysNames["Jason"] = 40;
        boysNames["Brian"] = 41;
        boysNames["Caleb"] = 42;
        boysNames["Cody"] = 43;
        boysNames["Logan"] = 44;
        boysNames["Adam"] = 45;
        boysNames["Steven"] = 46;
        boysNames["Connor"] = 47;
        boysNames["Charles"] = 48;
        boysNames["Timothy"] = 49;
        boysNames["Sean"] = 50;

        std::string name;
        std::cin >> name;

        std::cout << name << " was the number " << boysNames[name] << " popular boys name of 1998." << std::endl;
        std::cout << "load factor is " << girlsNames.getLoadFactor() << std::endl;


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
    System("pause");
}