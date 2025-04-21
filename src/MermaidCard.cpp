#include "MermaidCard.h"
#include <iostream>

namespace dmd {

    // Constructor: sets the value and identifies this card as a Mermaid type
    MermaidCard::MermaidCard(int value)
        : Card(value, CardType::Mermaid) {
    }

    // Mermaids have no special ability when played, but are worth more points when banked
    void MermaidCard::play(Game& game, Player& player) {
        std::cout << "No effect but Mermaids are worth more.\n";
    }

    // Returns a display-friendly string like "Mermaid(6)"
    std::string MermaidCard::str() const {
        return "Mermaid(" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
