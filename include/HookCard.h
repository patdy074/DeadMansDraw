#ifndef HOOKCARD_H
#define HOOKCARD_H

#include "Card.h"
#include <memory>

namespace dmd {


    class HookCard : public Card {
    public:
        explicit HookCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // HOOKCARD_H
