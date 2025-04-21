#include "KeyCard.h"
#include <iostream>

namespace dmd {

    KeyCard::KeyCard(int value)
        : Card(value, CardType::Key) {
    }

    // When a KeyCard is played, it doesn't do anything immediately.
    // However, if banked together with a ChestCard, it triggers bonus logic (handled in Player::bankCards).
    void KeyCard::play(Game& /*game*/, Player& /*player*/) {
        std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
    }

    std::string KeyCard::str() const {
        return "Key(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
