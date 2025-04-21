#ifndef CANNONCARD_H
#define CANNONCARD_H

#include "Card.h"

namespace dmd {

    class CannonCard : public Card {
    public:
        //The point value of the Cannon card (e.g., 2–7)
        explicit CannonCard(int value);

        //Executes the Cannon effect: remove top card of a suit from opponent's bank.
        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // CANNONCARD_H
