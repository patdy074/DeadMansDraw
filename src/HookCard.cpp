#include "HookCard.h"
#include "Game.h"
#include "Player.h"
#include "CardTypeUtils.h" // toString()

#include <iostream>
#include <map>
#include <limits>
#include <algorithm>

namespace dmd {

    // Constructor: HookCard always has CardType::Hook
    HookCard::HookCard(int value)
        : Card(value, CardType::Hook) {
    }

    void HookCard::play(Game& game, Player& player) {
        std::cout << "Select a highest-value card from any of the suits in your Bank:\n";

        std::map<CardType, std::string> options;

        // Build a list of all suits in the player's bank that have at least one card
        for (CardType type : {
            CardType::Cannon, CardType::Chest, CardType::Hook, CardType::Key,
                CardType::Kraken, CardType::Map, CardType::Mermaid, CardType::Oracle, CardType::Sword
        }) {
            if (player.getTopCardOfSuit(type)) {
                std::cout << "  - " << toString(type) << "\n";
                options[type] = toString(type);
            }
        }

        // Prompt the player to choose one of the available suit names
        std::string choice;
        std::cout << "Enter suit name (e.g. Sword): ";
        std::getline(std::cin, choice);

        // Match the user's input to one of the available suits
        CardType selectedType = CardType::Cannon;
        bool found = false;

        for (auto& pair : options) {
            if (choice == pair.second) {
                selectedType = pair.first;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Invalid suit selection. HookCard canceled.\n";
            return;
        }

        // Get the top card (highest value) of that suit from the player's bank
        std::shared_ptr<Card> topCard = player.getTopCardOfSuit(selectedType);

        if (!topCard) {
            std::cout << "No card of that suit found in bank.\n";
            return;
        }

        // Move the selected card from bank to play area
        player.removeCardFromBank(topCard);
        player.addToPlayArea(topCard);

        std::cout << "[HookCard] Played from bank: " << topCard->str() << "\n";

        // If the move causes a bust, clear the play area
        if (player.isBust()) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            game.moveToDiscard(player.getPlayArea());
            player.discardPlayArea();
        }
        else {
            // Otherwise, trigger the effect of the newly added card
            topCard->play(game, player);
        }
    }

    // Returns a string representation of the card (e.g., "Hook (5)")
    std::string HookCard::str() const {
        return "Hook (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
