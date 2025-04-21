
#ifndef CANNONCARD_H
#define CANNONCARD_H

#include "Card.h"
#include <memory>

namespace dmd {

    class CannonCard : public Card {
    public:
        explicit CannonCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // CANNONCARD_H
