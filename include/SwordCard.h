#ifndef SWORDCARD_H
#define SWORDCARD_H

#include "Card.h"
#include <memory>

namespace dmd {


    class SwordCard : public Card {
    public:
        SwordCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // SWORDCARD_H
