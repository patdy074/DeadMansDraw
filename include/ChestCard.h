#ifndef CHESTCARD_H
#define CHESTCARD_H

#include "Card.h"

namespace dmd {

    
    class ChestCard : public Card {
    public:
       
        explicit ChestCard(int value);

        
        void play(Game& game, Player& player) override;

        std::string str() const override;
    };

} // namespace dmd

#endif // CHESTCARD_H
