#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "../utils/Components.h"

#include <SFML/Graphics/RectangleShape.hpp>

using CComponent = std::tuple<CRect, CSprite, CText>;

class Entity {
public:
    Entity() = default;

    ~Entity() = default;

    std::string tag = "None";

    std::string layer = "Default";

    sf::RectangleShape rect = sf::RectangleShape();
};

#endif //ENTITY_H