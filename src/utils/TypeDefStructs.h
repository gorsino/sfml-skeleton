#ifndef TYPEDEFSTRUCTS_H
#define TYPEDEFSTRUCTS_H

#include <SFML/Graphics.hpp>

/////////////////////////////////////////////////////////
/// This namespace define some commons typedef structure
////////////////////////////////////////////////////////
/// Key time
typedef struct KeyTime {
    void update(const float &dt) {
        if (this->time < this->timeMax)
            this->time += 5.f * dt;
    }

    bool isTime() {
        if (this->time >= this->timeMax) {
            this->time = 0.f;
            return true;
        }

        return false;
    }

    float time = 0.f;
    float timeMax = 1.f;
} KeyTime;

/// Mouse positions
typedef struct MousePositions {
    void update(sf::RenderWindow &w) {
        this->screen = sf::Mouse::getPosition();
        this->window = sf::Mouse::getPosition(w);
        this->view = w.mapPixelToCoords(this->window);
    }

    sf::Vector2i screen = sf::Vector2i(0, 0);
    sf::Vector2i window = sf::Vector2i(0, 0);
    sf::Vector2f view = sf::Vector2f(0.f, 0.f);
} MousePositions;

/// Color states
typedef struct ColorStates {
    sf::Color idle = CLOUDS;
    sf::Color hover = CLOUDS;
    sf::Color active = CLOUDS;
} ColorStates;

#endif //TYPEDEFSTRUCTS_H
