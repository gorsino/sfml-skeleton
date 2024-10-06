#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include <sstream>

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
};

#endif //GAME_H
