#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include <sstream>

#include "Entity.h"

static const std::string FONTS_PATH = "resources/fonts/";

class Game {
public:
    // Constructor / Destructor
    Game();
    ~Game();

    // Functions
    void run();
    void updateSFMLEvents();
    void update();
    void render() const;

private:
    // Functions
    void initVariables();
    void initWindow();
    void initFont();

    // Variables
    sf::RenderWindow* window_;
    sf::Event sfEvent_;
    sf::Font font_;

    sf::Clock dtClock_;
    float dt_;

    Entity entity_;
};

#endif //GAME_H
