#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Card.h"
#include "CardType.h"

#include <vector>
#include <memory>
#include <string>

namespace dmd {

    class Game {
    public:
        Game(const std::string& playerOneName, const std::string& playerTwoName);

        void startGame();           // Starts the main game loop
        void drawCard();            // Draw a card from the deck for the current player
        void switchPlayer();        // Switch to the other player
        bool isGameOver() const;    // Check if the game has ended
        void printFinalScores() const; // Display final scores and winner

    private:
        std::vector<std::shared_ptr<Card>> _deck;
        std::vector<std::shared_ptr<Card>> _discardPile;

        std::shared_ptr<Player> _players[2];
        int _currentPlayerIndex;

        int _roundLimit;
        int _currentRound;

        void initializeDeck();       // Set up the full deck
        void shuffleDeck();         // Shuffle the deck randomly
        std::shared_ptr<Card> dealCard(); // Take the top card from the deck
    };

} // namespace dmd

#endif // GAME_H
