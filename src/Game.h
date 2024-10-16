#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"
#include "Debug/DebugText.h"
#include "ParticleSystem.h"

#include <sstream>

static const std::string FONTS_PATH = "resources/fonts/";

// Structs
struct MousePositions {
    sf::Vector2i screen;
    sf::Vector2i window;
    sf::Vector2f view;
};

class Game {
public:
    // Constructor / Destructor
    Game();

    ~Game();

    // Functions
    void run();

private:
    // Functions
    void initWindow();

    void initFont();

    void update();

    void render() const;

    void updateSFMLEvents();

    void updateMousePositions();

    // Variables
    sf::RenderWindow *window_;
    sf::VideoMode mode_;
    sf::Event sfEvent_;
    sf::Font font_;

    MousePositions mousePositions_;

    sf::Clock dtClock_;
    float dt_;

    ParticleSystem particles_;
};

#endif //GAME_H
