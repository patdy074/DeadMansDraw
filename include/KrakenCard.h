#ifndef KRAKENCARD_H
#define KRAKENCARD_H

#include "Card.h"
#include <memory>

namespace dmd {

    class KrakenCard : public Card {
    public:
        explicit KrakenCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // KRAKENCARD_H
