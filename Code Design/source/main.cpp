#include <iostream>
#include <Windows.h>

// exception handling
#include <aieLog.h>
#include <aieException.h>

#include "UnitTest.h"

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

        std::cout << (runUnitTest() ? "All Unit Tests Passed!" : "Unit Tests Failed...") << std::endl;
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