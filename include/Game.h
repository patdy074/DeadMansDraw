#ifndef GAME_H
#define GAME_H

// Includes Player and Card class definitions
#include "Player.h"
#include "Card.h"

#include <vector>
#include <memory>
#include <string>

namespace dmd {

    
    class Game {
    public:
        Game();

        void startGame();

        //Used when a player busts or discards bonus cards.
        void moveToDiscard(const std::vector<std::shared_ptr<Card>>& cards);

        //Useful for effects like Sword and Cannon.
        std::shared_ptr<Player> getOpponent() const;


        //Cards like Map, Chest+Key use this to interact with the discard.
        std::vector<std::shared_ptr<Card>>& getDiscardPile();

        Player* getOpponent(Player* currentPlayer);

        
        //Overloaded version of the vector-based method.
        void moveToDiscard(std::shared_ptr<Card> card);

        //Used by OracleCard to show the next card.
        std::shared_ptr<Card> peekTopCard() const;

        //Called at the start of each player's turn or by card effects.
        std::shared_ptr<Card> drawCard();

    private:
        // The shared deck of 54 shuffled cards
        std::vector<std::shared_ptr<Card>> _deck;

        // Discard pile (cards lost or used by effects)
        std::vector<std::shared_ptr<Card>> _discardPile;

        // Two players (using shared_ptr to manage ownership safely)
        std::shared_ptr<Player> _players[2];

        // Tracks whose turn it is (0 or 1)
        int _currentPlayerIndex;

        // Keeps track of the current round number
        int _round;

        // Turn counter for max-turn end condition
        int _turn;
                
        //Called once at the start of the game.
        void initializeDeck();

        void shuffleDeck();

        void initializePlayers();

        void switchPlayer();

        //@brief Checks if the game is over (deck empty or max turns reached).
        bool isGameOver() const;

        void printFinalScores() const;

        void endGame();
    };

} // namespace dmd

#endif // GAME_H
