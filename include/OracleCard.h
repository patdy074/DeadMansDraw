#ifndef ORACLECARD_H
#define ORACLECARD_H

#include "Card.h"

namespace dmd {

    /* The Oracle allows the player to peek at the top card of the deck
     before deciding to draw again. Its logic is implemented in play().
     */
    class OracleCard : public Card {
    public:
        explicit OracleCard(int value);

        //Executes the Oracle's effect — peek at the top card of the deck.
        void play(Game& game, Player& player) override;

       
        std::string str() const override;
    };

} // namespace dmd

#endif // ORACLECARD_H
