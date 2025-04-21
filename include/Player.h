#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include "Game.h"
#include <string>
#include <vector>
#include <memory>

namespace dmd {

    class Game;

    class Player {
    public:
        Player(); // Assigns a random name to the player

        void addToPlayArea(std::shared_ptr<Card> card); // Adds a card to the player's temporary play area
        void addToBank(std::shared_ptr<Card> card);     // Adds a card directly to the player's bank (used in bonuses)

        bool isBust() const; // Returns true if the play area contains duplicate card suits

        void discardPlayArea(); // Discards all cards from play area (used when busting)

        void bankCards(Game& game); // Transfers cards from play area to bank (includes Chest+Key logic)

        int score() const; // Calculates score based on the highest card of each suit in the bank
        std::string getName() const; // Returns the player’s name

        void printPlayArea() const; // Prints all cards in the play area
        void printBank() const;     // Prints all cards in the bank with score
        void printCardGroups(const std::vector<std::shared_ptr<Card>>& cards) const; // Helper to group & sort cards when printing

        std::shared_ptr<Card> stealTopBankCard(); // Allows opponent to steal the highest value card from one suit in the bank
        bool discardTopBankCard();                // Discards the top card from one suit in the bank

        std::shared_ptr<Card> getTopCardOfSuit(CardType type); // Finds the highest value card of a given suit in the bank
        bool removeCardFromBank(const std::shared_ptr<Card>& card); // Removes a specific card from the bank if it exists

        std::vector<std::shared_ptr<Card>>& getPlayArea(); // Grants access to modify play area externally (e.g., from Game or Card)
        std::vector<std::shared_ptr<Card>>& getBank();      // Grants access to modify bank externally

        void bankCrads(Game& game); // ⚠️ Typo: should be bankCards(), may be duplicate or unused


    private:
        std::string _name; // The player's randomly assigned name
        std::vector<std::shared_ptr<Card>> _playArea; // Cards drawn this turn (reset if bust)
        std::vector<std::shared_ptr<Card>> _bank;     // Safe, banked cards used for scoring
    };

} // namespace dmd

#endif // PLAYER_H
