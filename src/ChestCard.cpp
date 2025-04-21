#include "ChestCard.h"
#include <iostream>

namespace dmd {

    // Constructor: Initializes a ChestCard with its point value and sets its type
    ChestCard::ChestCard(int value)
        : Card(value, CardType::Chest) {
    }

    // ChestCard has no effect when drawn — its special effect is handled during banking (see Player::bankCards)
    void ChestCard::play(Game& /*game*/, Player& /*player*/) {
        std::cout << "No immediate effect. If banked with a chest, draw as many bonus cards from the Discard pile as you moved into your Bank.\n";
    }

    // Returns a string representation of the card (e.g., "Chest(5)")
    std::string ChestCard::str() const {
        return "Chest(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
