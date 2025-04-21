#ifndef MERMAIDCARD_H
#define MERMAIDCARD_H

#include "Card.h"

namespace dmd {

    /* Mermaid cards have no special ability when played,
     but they tend to have higher point values for scoring.
     */
    class MermaidCard : public Card {
    public:
        explicit MermaidCard(int value);

        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // MERMAIDCARD_H
