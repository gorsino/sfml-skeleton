#ifndef DEBUGSYSTEM_H
#define DEBUGSYSTEM_H

#include "SFML/Graphics.hpp"

#include "DebugText.h"

enum DebugType {
    DELTA_TIME = 0, KEY_TIME, MOUSE_POSITIONS, TOTAL_ENTITIES
};

class DebugSystem final : public sf::Drawable, public sf::Transformable
{
public:
    DebugSystem();

    DebugSystem(sf::Vector2f position, sf::Vector2f size, const sf::Font& font);

    ~DebugSystem() override;

    void toggleActive();

    bool isActive() const;

    void add(DebugText &debugText, int index, sf::Vector2f offsetPos);

    void clear();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    sf::RectangleShape container_;
    sf::Text title_;

    std::map<int, DebugText> debugTexts_;

    bool active_;
};

#endif //DEBUGSYSTEM_H
