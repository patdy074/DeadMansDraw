#ifndef ORACLECARD_H
#define ORACLECARD_H

#include "Card.h"
#include <memory>

namespace dmd {


    class OracleCard : public Card {
    public:
        explicit OracleCard(int value);

        void play(/*Game &game, Player &player*/) override;
        std::string str() const override;
    };

} // namespace dmd

#endif // ORACLECARD_H
