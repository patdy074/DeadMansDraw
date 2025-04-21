#ifndef KRAKENCARD_H
#define KRAKENCARD_H

#include "Card.h"

namespace dmd {

    /* When played, the Kraken card forces the player to draw
       and play three additional cards in a row — risky!
     */
    class KrakenCard : public Card {
    public:
        // Constructor takes a value (2–7), passed to base Card
        explicit KrakenCard(int value);

        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // KRAKENCARD_H
