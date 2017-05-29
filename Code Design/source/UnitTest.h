#pragma once

// exception handling
#include <aieLog.h>
#include <aieException.h>

// Standard Template Library implementations

// my implementations
#include "linkedList.h"
#include "treeNode.h"
#include "HashTable.h"

// extra includes
#include <Windows.h>
#include <string>

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

// tests that my implementations are working properly
bool runUnitTest()
{

    return false;

    catch (const std::exception& e)
    {
        std::cout << "\n\n\n" << e.what() << "\n\n\n";
    }

    catch (const aie::Exception& e)
    {
        std::cout << "\n\n\n" << e.reason() << "\n\n\n";
    }
}