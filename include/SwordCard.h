#ifndef SWORDCARD_H
#define SWORDCARD_H

#include "Card.h"

namespace dmd {

    //A SwordCard allows the player to steal a card from the opponent's bank.
    class SwordCard : public Card {
    public:
       //Constructs a SwordCard with a specific point value.
         explicit SwordCard(int value);

       //Steals the highest card of a chosen suit from the opponent's bank
        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // SWORDCARD_H
