#ifndef KEYCARD_H
#define KEYCARD_H

#include "Card.h"
#include <memory>

namespace dmd {

    class KeyCard : public Card {
    public:
        explicit KeyCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // KEYCARD_H
