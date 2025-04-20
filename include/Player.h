#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>
#include <memory>

namespace dmd {

    class Player {
    public:
        Player(const std::string& name);

        // Add a drawn card to the play area
        void addToPlayArea(std::shared_ptr<Card> card);

        // Bank all cards from playArea into bank
        void bankCards();

        // Check if player has drawn a duplicate suit (bust)
        bool isBust() const;

        // Calculate the score based on highest card per suit in the bank
        int score() const;

        // Clear playArea (used on bust)
        void discardPlayArea();

        // Print cards in playArea (debug/display)
        void printPlayArea() const;

        // Print cards in bank (debug/display)
        void printBank() const;

        // Getter
        std::string getName() const;

    private:
        std::string _name;
        std::vector<std::shared_ptr<Card>> _bank;
        std::vector<std::shared_ptr<Card>> _playArea;
    };

} // namespace dmd

#endif // PLAYER_H
