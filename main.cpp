#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Game_Title.h"

// Include all card types
#include "SwordCard.h"
#include "CannonCard.h"
#include "HookCard.h"
#include "KrakenCard.h"
#include "KeyCard.h"
#include "ChestCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "MermaidCard.h"

int main() {
    // Game title (from Game_Title.h)
    std::cout << GAME_TITLE << std::endl;

    // This ensures we get different results each time the game is run
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // Created a Game object and start the game loop
    // This handles player turns, card drawing, effects, and win/loss conditions
    dmd::Game game;
    game.startGame();

 
    return 0;
}
