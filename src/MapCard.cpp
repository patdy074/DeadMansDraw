#include "MapCard.h"
#include <iostream>

namespace dmd {

    MapCard::MapCard(int value)
        : Card(value, CardType::Map) {
    }

    void MapCard::play(/*Game &game, Player &player*/) {
        // Actual card selection from discard pile will be implemented in Game
        std::cout << "[MapCard effect triggered - Choose card from discard pile]\n";
    }

    std::string MapCard::str() const {
        return "Map (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
