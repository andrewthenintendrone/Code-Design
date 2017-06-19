#include "GameManager.h"
#include <iostream>

GameManager* GameManager::getInstance()
{
    static GameManager instance;
    return &instance;
}

// modified GameManager for unit test
// changes to each state and updates 5 times each
bool GameManager::runUnitTests()
{
    std::cout << "changing game state to menu" << std::endl;
    STATEMANAGER->changeState(STATE::MENU);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (STATEMANAGER->getState() == STATE::MENU)
        {
            STATEMANAGER->update();
        }
        else
        {
            return false;
        }
    }

    std::cout << "changing game state to serving" << std::endl;
    STATEMANAGER->changeState(STATE::SERVING);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (STATEMANAGER->getState() == STATE::SERVING)
        {
            STATEMANAGER->update();
        }
        else
        {
            return false;
        }
    }

    std::cout << "changing game state to playing" << std::endl;
    STATEMANAGER->changeState(STATE::PLAYING);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (STATEMANAGER->getState() == STATE::PLAYING)
        {
            STATEMANAGER->update();
        }
        else
        {
            return false;
        }
    }

    std::cout << "changing game state to paused" << std::endl;
    STATEMANAGER->changeState(STATE::PAUSED);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (STATEMANAGER->getState() == STATE::PAUSED)
        {
            STATEMANAGER->update();
        }
        else
        {
            return false;
        }
    }

    std::cout << "changing game state to won" << std::endl;
    STATEMANAGER->changeState(STATE::WON);
    for (unsigned int i = 0; i < 5; i++)
    {
        if (STATEMANAGER->getState() == STATE::WON)
        {
            STATEMANAGER->update();
        }
        else
        {
            return false;
        }
    }

    std::cout << "Game State tests passed" << std::endl;
    return true;
}

#pragma region update functions

// update while at the menu
void GameManager::updateMenu()
{
    std::cout << "Current state is menu" << std::endl;
    Sleep(100);
}

// update while serving
void GameManager::updateServing()
{
    std::cout << "Current state is serving" << std::endl;
    Sleep(100);
}

// update while thye game is paused
void GameManager::updatePaused()
{
    std::cout << "Current state is paused" << std::endl;
    Sleep(100);
}

// update while playing the game
void GameManager::updatePlaying()
{
    std::cout << "Current state is playing" << std::endl;
    Sleep(100);
}

// update after the player has won
void GameManager::updateWon()
{
    std::cout << "Current state is won" << std::endl;
    Sleep(100);
}

#pragma endregion