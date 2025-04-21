#include "Card.h"

namespace dmd {

    Card::Card(int value, CardType type)
        : _value(value), _type(type) // Initializer list for clean initialization
    {
        // No extra logic needed
    }

    Card::~Card() {
        // Virtual destructor for safety
    }

    CardType Card::getType() const {
        return _type;
    }

    int Card::getValue() const {
        return _value;
    }

} // namespace dmd
