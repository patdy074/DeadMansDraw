#include "Game.h"
#include "Player.h"
#include "DeckFactory.h"

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

    // Create and assign two player objects
    void Game::initializePlayers() {
        _players[0] = std::make_shared<Player>();
        _players[1] = std::make_shared<Player>();
    }

    // Generate and shuffle the full deck using DeckFactory
    void Game::initializeDeck() {
        _deck = DeckFactory::createShuffledDeck();
    }

    // Unused placeholder function (required by assignment but logic handled by DeckFactory)
    void Game::shuffleDeck() {}

    // Main game loop that runs until max turns or empty deck
    void Game::startGame() {
        std::cout << "Starting Dead Man's Draw++!\n\n";

        int totalTurns = 0;
        const int maxTurns = 20;

        while (!isGameOver() && totalTurns < maxTurns) {
            std::cout << "--- Round " << _round
                << ", Turn " << _turn << " ---\n";

            auto currentPlayer = _players[_currentPlayerIndex];
            std::cout << currentPlayer->getName() << "'s turn.\n";
            currentPlayer->printBank();

            bool turnOver = false;
            bool isBusted = false;

            while (!turnOver && !isBusted) {
                std::shared_ptr<Card> drawnCard = drawCard();

                // If deck is empty, end game immediately
                if (!drawnCard) {
                    std::cout << "The deck is empty. Ending game early...\n";
                    endGame();
                    return;
                }

                std::cout << currentPlayer->getName()
                    << " draws a " << drawnCard->str() << "\n";

                currentPlayer->addToPlayArea(drawnCard);

                // Check for bust BEFORE triggering the card's effect
                if (currentPlayer->isBust()) {
                    std::cout << "BUST! " << currentPlayer->getName()
                        << " loses all cards in play area.\n\n";
                    moveToDiscard(currentPlayer->getPlayArea());
                    currentPlayer->discardPlayArea();
                    isBusted = true;
                    break;
                }

                // Activate the drawn card's ability
                drawnCard->play(*this, *currentPlayer);

                currentPlayer->printPlayArea();

                // Spacing before prompt for clarity
                std::cout << std::endl;

                std::string input;
                std::cout << "Draw again? (y/n): ";
                std::getline(std::cin, input);

                // If player chooses not to draw again, bank the cards
                if (input != "y" && input != "Y") {
                    std::cout << "Cards banked successfully.\n";
                    currentPlayer->bankCards(*this);
                    currentPlayer->printBank();
                    turnOver = true;
                }
            }

            // Move to next player and increment round/turn counters
            switchPlayer();
            ++_round;
            ++_turn;
            ++totalTurns;
            std::cout << "\n";
        }

        endGame();
    }

    // Draw a card from the back of the deck
    std::shared_ptr<Card> Game::drawCard() {
        if (_deck.empty()) {
            return nullptr;
        }

        auto card = _deck.back();
        _deck.pop_back();
        return card;
    }

    // Toggle between player 0 and player 1
    void Game::switchPlayer() {
        _currentPlayerIndex = 1 - _currentPlayerIndex;
    }

    // Game ends when the deck is empty
    bool Game::isGameOver() const {
        return _deck.empty();
    }

    // Print final scores for both players
    void Game::printFinalScores() const {
        std::cout << "\n=== Final Scores ===\n";
        for (int i = 0; i < 2; ++i) {
            std::cout << _players[i]->getName() << ": "
                << _players[i]->score() << "\n";
        }
    }

    // Move multiple cards to the discard pile
    void Game::moveToDiscard(const std::vector<std::shared_ptr<Card>>& cards) {
        for (const auto& card : cards) {
            _discardPile.push_back(card);
        }
    }

    // Return the non-active player (used by Sword/Cannon effects)
    std::shared_ptr<Player> Game::getOpponent() const {
        return _players[(_currentPlayerIndex + 1) % 2];
    }

    // Give access to discard pile (used in Chest + Key or Map logic)
    std::vector<std::shared_ptr<Card>>& Game::getDiscardPile() {
        return _discardPile;
    }

    // Get the other player based on current Player pointer (used in card logic)
    Player* Game::getOpponent(Player* current) {
        if (_players[0].get() == current) {
            return _players[1].get();
        }
        else {
            return _players[0].get();
        }
    }

    // Unused placeholder for single-card discard (not required by spec)
    void Game::moveToDiscard(std::shared_ptr<Card> card) {}

    // Used by Oracle to preview the next card
    std::shared_ptr<dmd::Card> dmd::Game::peekTopCard() const {
        if (!_deck.empty()) {
            return _deck.back();
        }
        else {
            return nullptr;
        }
    }

    // End-of-game logic with final score comparison and winner announcement
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
