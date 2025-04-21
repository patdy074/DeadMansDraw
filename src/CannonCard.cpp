#include "CannonCard.h"
#include <iostream>

namespace dmd {

    CannonCard::CannonCard(int value)
        : Card(value, CardType::Cannon) {
    }

    void CannonCard::play(/*Game &game, Player &player*/) {
        // Logic to discard a card from opponent's bank would go here.
        // Placeholder until integration with Game and Player.
        std::cout << "[CannonCard effect triggered - Discard opponent's card]\n";
    }

    std::string CannonCard::str() const {
        return "Cannon (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
