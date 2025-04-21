#ifndef MAPCARD_H
#define MAPCARD_H

#include "Card.h"
#include <memory>

namespace dmd {

    class MapCard : public Card {
    public:
        explicit MapCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // MAPCARD_H
