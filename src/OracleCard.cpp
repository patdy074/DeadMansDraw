#include "OracleCard.h"
#include <iostream>

namespace dmd {

    OracleCard::OracleCard(int value)
        : Card(value, CardType::Oracle) {
    }

    void OracleCard::play(/*Game &game, Player &player*/) {
        // This would allow the player to peek at the next card
        // The actual logic will go in the Game class
        std::cout << "[OracleCard effect triggered - Reveal next card in deck]\n";
    }

    std::string OracleCard::str() const {
        return "Oracle (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
