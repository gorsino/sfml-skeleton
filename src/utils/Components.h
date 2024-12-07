#ifndef SFML_SKELETON_COMPONENTS_H
#define SFML_SKELETON_COMPONENTS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Component {
public:
    bool exists = false;
};

class CRect : public Component {
public:
    CRect() = default;

    sf::RectangleShape rect;
};

class CText : public Component {
public:
    CText() = default;

    sf::Text text;
};

class CSprite : public Component {
public:
    CSprite() = default;

    sf::Sprite sprite;
};

#endif //SFML_SKELETON_COMPONENTS_H
