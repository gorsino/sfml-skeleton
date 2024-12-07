#ifndef SFML_SKELETON_ENTITY_H
#define SFML_SKELETON_ENTITY_H

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

    CComponent components;

private:
};

#endif //SFML_SKELETON_ENTITY_H