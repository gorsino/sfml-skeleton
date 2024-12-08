#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <memory>

#include <SFML/Graphics/RectangleShape.hpp>

#include "../utils/Components.h"

using CComponent = std::tuple<CRect, CSprite, CText>;

class Entity {
public:
    Entity() = default;

    ~Entity() = default;

    static std::shared_ptr<Entity> create(const std::string &tag);

    std::string tag = "None";

    std::string layer = "Default";

    sf::RectangleShape rect = sf::RectangleShape();
};

#endif //ENTITY_H