#ifndef MAPCARD_H
#define MAPCARD_H

#include "Card.h"

namespace dmd {

    /*MapCard allows the player to draw 3 cards from the discard pile
     and play one of them — a strategic way to reuse discarded cards.
     */
    class MapCard : public Card {
    public:
        explicit MapCard(int value);

        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // MAPCARD_H
