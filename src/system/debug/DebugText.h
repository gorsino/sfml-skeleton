#ifndef DEBUGTEXT_H
#define DEBUGTEXT_H

#include "SFML/Graphics.hpp"

#include "../../utils/PaletteColors.h"

class DebugText : public sf::Drawable, public sf::Transformable {
public:
    DebugText(const sf::Font &font, int characterSize);

    ~DebugText() override;

    void setString(const std::string &value);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::Text text;
};

#endif //DEBUGTEXT_H
