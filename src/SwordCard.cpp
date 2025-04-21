#include "SwordCard.h"
#include "Game.h"
#include "Player.h"
#include "CardTypeUtils.h"

#include <iostream>
#include <map>
#include <limits>
#include <algorithm>

namespace dmd {

    SwordCard::SwordCard(int value)
        : Card(value, CardType::Sword) {
    }

    void SwordCard::play(Game& game, Player& player) {
        // Get the opponent player object
        std::shared_ptr<Player> opponent = game.getOpponent();

        std::cout << "Steal the top card of any suit from the other player's Bank into your Play Area:\n";

        std::map<CardType, std::string> options;

        // Build a list of card suits the opponent has in their bank
        for (CardType type : {
            CardType::Cannon, CardType::Chest, CardType::Hook, CardType::Key,
                CardType::Kraken, CardType::Map, CardType::Mermaid, CardType::Oracle, CardType::Sword
        }) {
            if (opponent->getTopCardOfSuit(type)) {
                std::cout << "  - " << toString(type) << "\n";
                options[type] = toString(type);
            }
        }

        std::string choice;
        std::cout << "Enter suit name (e.g. Sword): ";
        std::getline(std::cin, choice);

        // Try to match the player's input to a valid card type
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
            std::cout << "Invalid suit selection. SwordCard canceled.\n";
            return;
        }

        // Get the highest-value card of that suit from opponent's bank
        std::shared_ptr<Card> stolenCard = opponent->getTopCardOfSuit(selectedType);

        if (!stolenCard) {
            std::cout << "No card of that suit found in opponent’s bank.\n";
            return;
        }

        // Remove the card from the opponent's bank and add it to the current player's play area
        opponent->removeCardFromBank(stolenCard);
        player.addToPlayArea(stolenCard);

        std::cout << "[SwordCard] You stole: " << stolenCard->str() << "\n";

        // After stealing, check if the player has busted
        if (player.isBust()) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            game.moveToDiscard(player.getPlayArea());
            player.discardPlayArea();
        }
        else {
            // If not busted, the stolen card's ability is executed
            stolenCard->play(game, player);
        }
    }

    std::string SwordCard::str() const {
        return "Sword (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
