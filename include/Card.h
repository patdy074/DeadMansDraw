#ifndef CARD_H
#define CARD_H

#include "CardType.h"
#include <string>

namespace dmd {

    class Game;
    class Player;

    /* Base class for all cards in the game.
     This is an abstract class — each card type like Sword, Map, etc. inherits from this.
     */
    class Card {
    public:
        
        Card(int value, CardType type);

       
        //Even though nothing is destroyed here, it's good practice in base classes.
        
        virtual ~Card();

        
        //Each card will define its own effect during play.
        virtual void play(Game& game, Player& player) = 0;

       
        //String representation like "Sword(6)" — useful for printing.
        virtual std::string str() const = 0;

        /*Optional effect for when a card is banked(used in Chest + Key logic).
         Only some cards override this — most don’t need to.
         */
        virtual void willAddToBank(Game& game, Player& player) {}

        int getValue() const;
        CardType getType() const;

    protected:
        int _value;      // The card's numeric value
        CardType _type;  // The suit/type of the card
    };

} // namespace dmd

#endif // CARD_H
