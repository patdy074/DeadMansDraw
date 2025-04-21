#include "OracleCard.h"
#include "Game.h"       // Required to use Game methods
#include "Card.h"       // Required for std::shared_ptr<Card>
#include <iostream>
#include <memory>

namespace dmd {

    OracleCard::OracleCard(int value)
        : Card(value, CardType::Oracle) {
    }

    void OracleCard::play(Game& game, Player& player) {
        // Try to peek at the next card in the deck
        std::shared_ptr<Card> peekCard = game.peekTopCard();  // <- must exist in Game class

        if (peekCard) {
            std::cout << "The Oracle sees a " << peekCard->str() << "\n";
        }
        else {
            std::cout << "The Oracle sees nothing. The deck is empty.\n";
        }
    }

    std::string OracleCard::str() const {
        return "Oracle(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
