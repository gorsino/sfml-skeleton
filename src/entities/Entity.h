#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "../utils/Components.h"

typedef std::tuple<CRect, CSprite, CText> TupleComponents;

class Entity final : public sf::Drawable {
public:
    Entity() = default;

    ~Entity() override = default;

    static std::shared_ptr<Entity> create(const std::string &tag);

    template<typename T>
    T &get();

    template<typename T>
    bool has() const;

    template<typename T>
    void remove();

    template<typename T, typename... TArgs>
    T &add(TArgs &&... args);

    /// Variables
    std::string tag = "None";

    std::string layer = "Default";

    sf::RectangleShape rect = sf::RectangleShape();

    TupleComponents components;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

#endif //ENTITY_H