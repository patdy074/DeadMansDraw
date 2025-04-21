#include "MermaidCard.h"
#include <iostream>

namespace dmd {

    MermaidCard::MermaidCard(int value)
        : Card(value, CardType::Mermaid) {
    }

    void MermaidCard::play(/*Game &game, Player &player*/) {
        // Mermaid bonus scoring is calculated during final scoring, not here
        std::cout << "[MermaidCard effect triggered - Bonus scoring applied later if applicable]\n";
    }

    std::string MermaidCard::str() const {
        return "Mermaid (" + std::to_string(getValue()) + ")";
    }

} // namespace dmd
