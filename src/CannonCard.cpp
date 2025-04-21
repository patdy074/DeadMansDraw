#include "CannonCard.h"
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <algorithm>

namespace dmd {

    CannonCard::CannonCard(int value)
        : Card(value, CardType::Cannon) {
    }

    void CannonCard::play(Game& game, Player& player) {
        // Get a pointer to the opponent of the current player
        Player* opponent = game.getOpponent(&player);
        if (!opponent) return;

        auto& bank = opponent->getBank();

        // If opponent has no cards in bank, there's nothing to destroy
        if (bank.empty()) {
            std::cout << "No cards in other player's Bank. Play continues.\n";
            return;
        }

        // Loop through the opponent's bank to find the highest-value card
        std::shared_ptr<Card> highestCard = nullptr;
        int highestValue = -1;
        size_t cardIndex = 0;
        size_t indexToRemove = 0;

        for (const auto& card : bank) {
            if (card->getValue() > highestValue) {
                highestValue = card->getValue();
                highestCard = card;
                indexToRemove = cardIndex;
            }
            cardIndex++;
        }

        // If a card was found, remove it from the opponent's bank and discard it
        if (highestCard) {
            std::cout << "[CannonCard] Effect triggered. "
                << "Removed " << highestCard->str() << " from opponent's Bank.\n";

            opponent->getBank().erase(opponent->getBank().begin() + indexToRemove);

            // Send the removed card to the shared discard pile
            game.getDiscardPile().push_back(highestCard);
        }
    }

    std::string CannonCard::str() const {
        return "Cannon(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
