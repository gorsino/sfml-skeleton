#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "states/GameState.h"

static const std::string FONTS_PATH = "resources/fonts/";

class Game {
public:
    /// Constructor / Destructor
    Game();

    ~Game();

    /// Functions
    void run();

private:
    /// Functions
    void initWindow();

    void initFont();

    void initState();

    void update();

    void render() const;

    void updateSFMLEvents();

    void debugDeltaTime() const;

    /// Variables
    sf::RenderWindow *window_;
    sf::VideoMode mode_;
    sf::Event sfEvent_;
    sf::Font font_;
    sf::Clock dtClock_;

    std::stack<BaseState *> states_;
    StateData stateData_;

    float dt_ = 0.f;
};

#endif //GAME_H
