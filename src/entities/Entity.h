#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "../utils/Components.h"

using CComponent = std::tuple<CRect, CSprite, CText>;

class Entity final : public sf::Drawable {
public:
    Entity() = default;

    ~Entity() override = default;

    static std::shared_ptr<Entity> create(const std::string &tag);

    std::string tag = "None";

    std::string layer = "Default";

    sf::RectangleShape rect = sf::RectangleShape();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif //ENTITY_H