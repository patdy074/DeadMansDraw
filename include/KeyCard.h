#ifndef KEYCARD_H
#define KEYCARD_H

#include "Card.h"

namespace dmd {


     /* The Key card doesn't have an immediate effect when drawn,
     but when banked together with a Chest, it triggers a bonus draw.
     */
    class KeyCard : public Card {
    public:

        explicit KeyCard(int value);

         //Has no effect during play. Logic is handled during banking if paired with a Chest.
        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // KEYCARD_H
