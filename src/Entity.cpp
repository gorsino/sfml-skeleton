#include "Entity.h"

#include "SFML/Graphics/RenderTarget.hpp"

Entity::Entity() {
    this->circleShape_.setFillColor(sf::Color::Green);
    this->circleShape_.setRadius(50.f);
    this->circleShape_.setOutlineThickness(1.f);
    this->circleShape_.setOutlineColor(sf::Color::White);
}

Entity::~Entity() = default;

void Entity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->circleShape_, states);
}
