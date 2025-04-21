#ifndef HOOKCARD_H
#define HOOKCARD_H

#include "Card.h"

namespace dmd {

    //Inherits from the base Card class and overrides its effect.
    class HookCard : public Card {
    public:
        //Constructs a HookCard with a given value (e.g., 2–7).
        explicit HookCard(int value);

        //Triggers the Hook effect: lets player choose and replay a card from their bank.
        void play(Game& game, Player& player) override;
                
        std::string str() const override;
    };

} // namespace dmd

#endif // HOOKCARD_H
