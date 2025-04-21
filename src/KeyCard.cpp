#include "KeyCard.h"
#include <iostream>

namespace dmd {

    KeyCard::KeyCard(int value)
        : Card(value, CardType::Key) {
    }

    void KeyCard::play(/*Game &game, Player &player*/) {
        // KeyCard's combo is checked during banking logic — not here
        std::cout << "[KeyCard effect triggered - Combo will be handled with ChestCard during banking]\n";
    }

    std::string KeyCard::str() const {
        return "Key (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
