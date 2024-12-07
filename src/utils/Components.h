#ifndef SFML_SKELETON_COMPONENTS_H
#define SFML_SKELETON_COMPONENTS_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Component {
};

class CRect : public Component {
public:
    sf::RectangleShape rect;
};

class CText : public Component {
public:
    sf::Text text;
};

class CSprite : public Component {
public:
    sf::Sprite sprite;
};

#endif //SFML_SKELETON_COMPONENTS_H
