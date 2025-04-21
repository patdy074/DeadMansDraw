#include "Player.h"
#include "Game.h"
#include "CardTypeUtils.h"
#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <ctime>
#include <random>

namespace dmd {

    Player::Player() {
        // Assign a random name from a fixed list
        static std::string names[] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
        _name = names[rand() % 10];
    }

    std::string Player::getName() const {
        return _name;
    }

    void Player::addToPlayArea(std::shared_ptr<Card> card) {
        _playArea.push_back(card);
    }

    void Player::addToBank(std::shared_ptr<Card> card) {
        _bank.push_back(card);
    }

    bool Player::isBust() const {
        // A bust occurs if two cards of the same type are in the play area
        std::set<CardType> suits;
        for (const auto& card : _playArea) {
            if (suits.count(card->getType()) > 0) {
                return true;  // Already seen this type → bust
            }
            suits.insert(card->getType());
        }
        return false;
    }

    void Player::discardPlayArea() {
        _playArea.clear();
    }

    void Player::bankCards(Game& game) {
        bool hasChest = false;
        bool hasKey = false;

        // Check if both Chest and Key are present in play area
        for (const auto& card : _playArea) {
            if (card->getType() == CardType::Chest) {
                hasChest = true;
            }
            else if (card->getType() == CardType::Key) {
                hasKey = true;
            }
        }

        int numBanked = static_cast<int>(_playArea.size());

        // Move play area cards to bank and apply any willAddToBank logic (e.g., Chest/Key effects)
        for (auto& card : _playArea) {
            card->willAddToBank(game, *this);
            _bank.push_back(card);
        }

        _playArea.clear();

        // Bonus draw from discard pile if Chest + Key combo was played
        if (hasChest && hasKey) {
            std::cout << "Chest + Key combo! Drawing " << numBanked << " bonus card(s) from the discard...\n";
            auto& discard = game.getDiscardPile();

            if (discard.empty()) {
                std::cout << "No cards in the discard. No bonus cards added.\n";
            }
            else {
                // Shuffle discard and draw bonus cards
                std::shuffle(discard.begin(), discard.end(), std::mt19937{ std::random_device{}() });

                for (int i = 0; i < numBanked && !discard.empty(); ++i) {
                    std::shared_ptr<Card> bonusCard = discard.back();
                    discard.pop_back();
                    std::cout << "Bonus: " << bonusCard->str() << " added to bank.\n";
                    _bank.push_back(bonusCard);
                }
            }
        }
    }

    int Player::score() const {
        std::map<CardType, int> highest;

        // Track the highest value card per suit in the bank
        for (const auto& card : _bank) {
            CardType type = card->getType();
            int val = card->getValue();

            if (highest.find(type) == highest.end() || val > highest[type]) {
                highest[type] = val;
            }
        }

        int total = 0;
        for (const auto& entry : highest) {
            total += entry.second;
        }

        return total;
    }

    void Player::printCardGroups(const std::vector<std::shared_ptr<Card>>& cards) const {
        // Group cards by type
        std::map<CardType, std::vector<std::shared_ptr<Card>>> grouped;

        for (const auto& card : cards) {
            grouped[card->getType()].push_back(card);
        }

        for (auto& pair : grouped) {
            // Sort cards within each suit in descending value
            std::sort(pair.second.begin(), pair.second.end(),
                [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
                    return a->getValue() > b->getValue();
                });

            std::cout << toString(pair.first) << ": ";
            for (const auto& c : pair.second) {
                std::cout << c->str() << " ";
            }
            std::cout << "\n";
        }
    }

    void Player::printPlayArea() const {
        std::cout << _name << "'s Play Area:\n";
        printCardGroups(_playArea);
    }

    void Player::printBank() const {
        std::cout << _name << "'s Bank:\n";

        std::map<CardType, std::vector<std::shared_ptr<Card>>> grouped;

        for (const auto& card : _bank) {
            grouped[card->getType()].push_back(card);
        }

        for (auto& pair : grouped) {
            std::vector<std::shared_ptr<Card>>& cards = pair.second;

            std::sort(cards.begin(), cards.end(),
                [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
                    return a->getValue() > b->getValue();
                });

            for (const auto& card : cards) {
                std::cout << "  " << card->str() << "\n";
            }
        }

        std::cout << "| Score: " << score() << "\n\n";
    }

    std::shared_ptr<Card> Player::stealTopBankCard() {
        if (_bank.empty()) return nullptr;

        // Find and remove the highest value card from bank
        auto it = std::max_element(_bank.begin(), _bank.end(),
            [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
                return a->getValue() < b->getValue();
            });

        std::shared_ptr<Card> stolen = *it;
        _bank.erase(it);
        return stolen;
    }

    bool Player::discardTopBankCard() {
        if (_bank.empty()) return false;

        // Remove the highest value card from the bank
        auto it = std::max_element(_bank.begin(), _bank.end(),
            [](const std::shared_ptr<Card>& a, const std::shared_ptr<Card>& b) {
                return a->getValue() < b->getValue();
            });

        _bank.erase(it);
        return true;
    }

    std::vector<std::shared_ptr<Card>>& Player::getPlayArea() {
        return _playArea;
    }

    std::vector<std::shared_ptr<Card>>& Player::getBank() {
        return _bank;
    }

    std::shared_ptr<Card> Player::getTopCardOfSuit(CardType type) {
        std::shared_ptr<Card> topCard = nullptr;
        int maxValue = -1;
        for (const auto& card : _bank) {
            if (card->getType() == type && card->getValue() > maxValue) {
                maxValue = card->getValue();
                topCard = card;
            }
        }
        return topCard;
    }

    bool Player::removeCardFromBank(const std::shared_ptr<Card>& card) {
        auto it = std::find(_bank.begin(), _bank.end(), card);
        if (it != _bank.end()) {
            _bank.erase(it);
            return true;
        }
        return false;
    }

} // namespace dmd
