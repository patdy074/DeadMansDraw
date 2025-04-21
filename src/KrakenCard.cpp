#include "KrakenCard.h"
#include "Game.h"
#include "Player.h"
#include <iostream>

namespace dmd {

    KrakenCard::KrakenCard(int value)
        : Card(value, CardType::Kraken) {
        // Constructor: initializes a Kraken card with a value and type
    }

    void KrakenCard::play(Game& game, Player& player) {
        std::cout << "Draw 3 cards from the deck and play each:\n";

        for (int i = 0; i < 3; ++i) {
            std::shared_ptr<Card> drawn = game.drawCard();

            if (!drawn) {
                // Stop early if the deck is empty
                std::cout << "  No more cards in the deck.\n";
                return;
            }

            std::cout << "  " << player.getName() << " draws a " << drawn->str() << "\n";
            player.addToPlayArea(drawn);

            if (player.isBust()) {
                // If a duplicate suit is drawn, player busts immediately
                std::cout << "BUST! " << player.getName() << " loses all cards in play area.\n";
                game.moveToDiscard(player.getPlayArea());
                player.discardPlayArea();
                return;
            }

            // Play the effect of the drawn card (can trigger more draws, effects, etc.)
            drawn->play(game, player);
        }
    }

    std::string KrakenCard::str() const {
        return "Kraken(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
