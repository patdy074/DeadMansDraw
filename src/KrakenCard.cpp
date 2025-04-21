#include "KrakenCard.h"
#include <iostream>

namespace dmd {

    KrakenCard::KrakenCard(int value)
        : Card(value, CardType::Kraken) {
    }

    void KrakenCard::play(/*Game &game, Player &player*/) {
        // The actual draw logic (draw 3 more cards) will be handled in Game class
        std::cout << "[KrakenCard effect triggered - Player must draw 3 more cards]\n";
    }

    std::string KrakenCard::str() const {
        return "Kraken (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
