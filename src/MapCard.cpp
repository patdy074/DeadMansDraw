#include "MapCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>
#include <algorithm>
#include <random>

namespace dmd {

    MapCard::MapCard(int value)
        : Card(value, CardType::Map) {
    }

    void MapCard::play(Game& game, Player& player) {
        auto& discard = game.getDiscardPile();

        // If there's nothing to draw, exit early with a message
        if (discard.empty()) {
            std::cout << "No cards in the discard. Play continues.\n";
            return;
        }

        // Shuffle the discard pile to ensure randomness
        std::shuffle(discard.begin(), discard.end(), std::mt19937{ std::random_device{}() });

        // Draw up to 3 cards from the discard pile
        std::vector<std::shared_ptr<Card>> drawn;
        int drawCount = std::min(3, static_cast<int>(discard.size()));
        for (int i = 0; i < drawCount; ++i) {
            drawn.push_back(discard.back());
            discard.pop_back();
        }

        // Show all drawn cards to the player for selection
        std::cout << "Draw 3 cards from the discard and pick one to add to the play area:\n";
        for (size_t i = 0; i < drawn.size(); ++i) {
            std::cout << "(" << i + 1 << ") " << drawn[i]->str() << "\n";
        }

        // Get player's choice
        std::cout << "Which card do you pick? ";
        std::string input;
        std::getline(std::cin, input);
        int choice = std::stoi(input);

        // Handle invalid selection by returning all cards
        if (choice < 1 || choice > static_cast<int>(drawn.size())) {
            std::cout << "Invalid selection. All cards returned to discard.\n";
            for (auto& card : drawn)
                discard.push_back(card);
            return;
        }

        // Move selected card into play area
        std::shared_ptr<Card> selectedCard = drawn[choice - 1];
        drawn.erase(drawn.begin() + (choice - 1));

        player.addToPlayArea(selectedCard);
        std::cout << "[MapCard] You played: " << selectedCard->str() << "\n";

        // Bust check before applying card's ability
        if (player.isBust()) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
            game.moveToDiscard(player.getPlayArea());
            player.discardPlayArea();
        }
        else {
            // Trigger the selected card’s effect
            selectedCard->play(game, player);
        }

        // Return the two unused cards to the discard pile
        for (auto& card : drawn) {
            discard.push_back(card);
        }
    }

    std::string MapCard::str() const {
        return "Map(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
