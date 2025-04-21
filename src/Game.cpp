#include "Game.h"
#include "Player.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <memory>

namespace dmd {

    Game::Game()
        : _currentPlayerIndex(0), _round(1), _turn(1)
    {
        initializePlayers();
        initializeDeck();
    }

    void Game::initializePlayers() {
        // Create two players using shared_ptr
        _players[0] = std::make_shared<Player>();
        _players[1] = std::make_shared<Player>();
    }

    void Game::initializeDeck() {
    }

    void Game::shuffleDeck() {
        // Unused: shuffle is handled in DeckFactory
    }

    void Game::startGame() {
        std::cout << "Starting Dead Man's Draw++!\n\n";

        int totalTurns = 0;
        const int maxTurns = 20;

        // Game loop: up to 20 turns or until deck is empty
        while (!isGameOver() && totalTurns < maxTurns) {
            std::cout << "--- Round " << _round << ", Turn " << _turn << " ---\n";

            auto currentPlayer = _players[_currentPlayerIndex];
            std::cout << currentPlayer->getName() << "'s turn.\n";
            currentPlayer->printBank();

            bool turnOver = false;
            bool isBusted = false;

            while (!turnOver && !isBusted) {
                std::shared_ptr<Card> drawnCard = drawCard();

                if (!drawnCard) {
                    std::cout << "The deck is empty. Ending game early...\n";
                    endGame();
                    return;
                }

                std::cout << currentPlayer->getName() << " draws a " << drawnCard->str() << "\n";

                currentPlayer->addToPlayArea(drawnCard);

                // Check for bust *before* triggering the card's ability
                if (currentPlayer->isBust()) {
                    std::cout << "BUST! " << currentPlayer->getName() << " loses all cards in play area.\n\n";
                    moveToDiscard(currentPlayer->getPlayArea());
                    currentPlayer->discardPlayArea();
                    isBusted = true;
                    break;
                }

                // Execute the card’s special effect
                drawnCard->play(*this, *currentPlayer);

                currentPlayer->printPlayArea();

                std::cout << std::endl; // spacing before prompt

                std::string input;
                std::cout << "Draw again? (y/n): ";
                std::getline(std::cin, input);

                // Player chose to stop and bank their cards
                if (input != "y" && input != "Y") {
                    std::cout << "Cards banked successfully.\n";
                    currentPlayer->bankCards(*this);
                    currentPlayer->printBank();
                    turnOver = true;
                }
            }

            switchPlayer(); // hand over to other player
            ++_round;
            ++_turn;
            ++totalTurns;
            std::cout << "\n";
        }

        endGame(); // Triggered after last turn or empty deck
    }

    std::shared_ptr<Card> Game::drawCard() {
        if (_deck.empty()) {
            return nullptr;
        }

        // Draw card from top (back of vector)
        auto card = _deck.back();
        _deck.pop_back();
        return card;
    }

    void Game::switchPlayer() {
        // Toggle between player 0 and 1
        _currentPlayerIndex = 1 - _currentPlayerIndex;
    }

    bool Game::isGameOver() const {
        return _deck.empty(); // 20-turn limit checked separately
    }

    void Game::printFinalScores() const {
        std::cout << "\n=== Final Scores ===\n";
        for (int i = 0; i < 2; ++i) {
            std::cout << _players[i]->getName() << ": " << _players[i]->score() << "\n";
        }
    }

    void Game::moveToDiscard(const std::vector<std::shared_ptr<Card>>& cards) {
        // Move a full collection of cards to the discard pile
        for (const auto& card : cards) {
            _discardPile.push_back(card);
        }
    }

    std::shared_ptr<Player> Game::getOpponent() const {
        // Get the non-active player
        return _players[(_currentPlayerIndex + 1) % 2];
    }

    std::vector<std::shared_ptr<Card>>& Game::getDiscardPile() {
        return _discardPile;
    }

    Player* Game::getOpponent(Player* current) {
        // Return pointer to the other player
        if (_players[0].get() == current) {
            return _players[1].get();
        }
        else {
            return _players[0].get();
        }
    }

    void Game::moveToDiscard(std::shared_ptr<Card> card) {
        // Unused overload; some cards may push individual cards directly
    }

    std::shared_ptr<dmd::Card> dmd::Game::peekTopCard() const {
        // OracleCard uses this to look at the next card
        if (!_deck.empty()) {
            return _deck.back();
        }
        else {
            return nullptr;
        }
    }

    void Game::endGame() {
        std::cout << "=== Game Over ===\n";

        int score1 = _players[0]->score();
        int score2 = _players[1]->score();

        std::string name1 = _players[0]->getName();
        std::string name2 = _players[1]->getName();

        std::cout << name1 << "'s Final Score: " << score1 << "\n";
        std::cout << name2 << "'s Final Score: " << score2 << "\n";

        if (score1 > score2) {
            std::cout << " " << name1 << " wins! \n";
        }
        else if (score2 > score1) {
            std::cout << " " << name2 << " wins! \n";
        }
        else {
            std::cout << "It's a tie!\n";
        }
    }

} // namespace dmd
