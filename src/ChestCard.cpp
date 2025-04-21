#include "ChestCard.h"
#include <iostream>

namespace dmd {

    ChestCard::ChestCard(int value)
        : Card(value, CardType::Chest) {
    }

    void ChestCard::play(/*Game &game, Player &player*/) {
        // Combo effect with KeyCard will be handled during banking in Player or Game
        std::cout << "[ChestCard effect triggered - Combo logic with KeyCard will apply when banked]\n";
    }

    std::string ChestCard::str() const {
        return "Chest (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
