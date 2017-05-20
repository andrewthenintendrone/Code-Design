#include <iostream>
#include "linkedList.h"
#include "sumTo.h"
#include "aieLog.h"
#include "aieException.h"
#include <Windows.h>

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

int main()
{
    try
    {
        int n = sumTo(100);
        std::cout << n << std::endl;

        g_exeFolder = getExecutableFolder();

        // Specify an ASCII log file for our application to use. This will be called
        // "log.txt" and will write itself into the executable's folder.
        aie::Log::instance().setLog(g_exeFolder + "\\log.txt");

        // Enable logging for all aie exceptions. When enabled, aie exceptions will
        // also record full details into the log.
        aie::Exception::enableLogging(true);

        aieLOG("Application started");

        List<char> myList;

        std::cout << "List is " << (myList.isEmpty() ? "empty" : "not empty") << std::endl;

        myList.pushBack('A');
        myList.pushBack('n');
        myList.pushBack('d');
        myList.pushBack('r');
        myList.pushBack('e');
        myList.pushBack('w');

        std::cout << "List is " << (myList.isEmpty() ? "empty" : "not empty") << std::endl;
        for (auto iter = myList.begin(); iter != myList.end(); iter++)
        {
            std::cout << iter.getNode()->value;
        }
        std::cout << std::endl;

        myList.popBack();
        myList.popBack();
        myList.popBack();
        myList.popBack();
        myList.popBack();
        myList.popBack();

        aieASSERT(myList.isEmpty());
        std::cout << "List is " << (myList.isEmpty() ? "empty" : "not empty") << std::endl;
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