#pragma once
#include <time.h>
#include <Windows.h>
#include "stateManager.h"

#define GAMEMANAGER GameManager::getInstance()

class GameManager
{
public:
    static GameManager* getInstance();
    bool runUnitTests();

    void updateMenu();
    void updateServing();
    void updatePaused();
    void updatePlaying();
    void updateWon();

private:
};