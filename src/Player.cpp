#include "Player.h"
#include <iostream>
#include <map>

namespace dmd {

    Player::Player(const std::string& name)
        : _name(name) {
    }

    void Player::addToPlayArea(std::shared_ptr<Card> card) {
        _playArea.push_back(card);
    }

    void Player::bankCards() {
        for (const auto& card : _playArea) {
            _bank.push_back(card);
        }
        _playArea.clear();
    }

    bool Player::isBust() const {
        std::map<CardType, bool> seenTypes;

        for (const auto& card : _playArea) {
            CardType type = card->getType();
            if (seenTypes[type]) {
                return true; // Duplicate type found
            }
            seenTypes[type] = true;
        }

        return false;
    }

    int Player::score() const {
        std::map<CardType, int> highestPerSuit;

        for (const auto& card : _bank) {
            CardType type = card->getType();
            int value = card->getValue();

            if (highestPerSuit[type] < value) {
                highestPerSuit[type] = value;
            }
        }

        int total = 0;
        for (const auto& pair : highestPerSuit) {
            total += pair.second;
        }
        return total;
    }

    void Player::discardPlayArea() {
        _playArea.clear();
    }

    void Player::printPlayArea() const {
        std::cout << _name << "'s Play Area: ";
        for (const auto& card : _playArea) {
            std::cout << card->str() << " ";
        }
        std::cout << "\n";
    }

    void Player::printBank() const {
        std::cout << _name << "'s Bank: ";
        for (const auto& card : _bank) {
            std::cout << card->str() << " ";
        }
        std::cout << "\n";
    }

    std::string Player::getName() const {
        return _name;
    }

} // namespace dmd
