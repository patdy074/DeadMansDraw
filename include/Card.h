#ifndef CARD_H
#define CARD_H

#include "CardType.h"
#include <string>

namespace dmd { // Place all your code in a project namespace

    
    class Card {
    public:
        // Constructor: initialize value and type
        Card(int value, CardType type);

        // Virtual destructor (important for base classes)
        virtual ~Card();

        // Getters for card type and value (do not modify the object)
        CardType getType() const;
        int getValue() const;

        
        virtual void play(/*Game &game, Player &player*/) = 0;

        virtual std::string str() const = 0;

    protected:
        int _value;
        CardType _type;
    };

} // namespace dmd

#endif // CARD_H
