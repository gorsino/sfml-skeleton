#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Drawable.hpp"

class Entity : public sf::Drawable {
public:
    Entity();

    ~Entity() override;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::CircleShape circleShape_;
};

#endif //ENTITY_H
