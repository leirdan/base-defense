#include "domain/interfaces/Game.hpp"
#include "domain/interfaces/Menu.hpp"
#include "enums/GameState.h"
#include "common.h"

const float CENTER_X = GAME_WINDOW_WIDTH / 2;
const float CENTER_Y = GAME_WINDOW_HEIGHT / 2;

int main()
{
    auto newHero = std::make_shared<Hero>(50, 50, 15, 100, 600, 400);
    auto newBase = std::make_shared<Base>(50, 500, 500, CENTER_X, CENTER_Y);
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1200, 800), "Game Window");
    Menu mainMenu(window);
    Game game(CENTER_X, CENTER_Y, window);
    game.setHero(newHero);
    game.setBase(newBase);

    // First state is always menu
    auto currentState = GameState::MENU;

    while (window->isOpen())
    {
        switch (currentState)
        {
        case GameState::MENU:
            if (!mainMenu.run()) // Only change state if run returns false
                currentState = GameState::PLAY;
            break;

        case GameState::PLAY:
            game.run();
            currentState = GameState::EXIT; // After game was finished, set state as exit
            break;

        case GameState::EXIT:
            window->close();
            break;
        }
    }

    return EXIT_SUCCESS;
}