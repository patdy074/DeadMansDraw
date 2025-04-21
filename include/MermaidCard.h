#ifndef MERMAIDCARD_H
#define MERMAIDCARD_H

#include "Card.h"
#include <memory>

namespace dmd {

    class MermaidCard : public Card {
    public:
        explicit MermaidCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // MERMAIDCARD_H
