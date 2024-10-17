#include "DebugText.h"

#include "../PaletteColors.h"

DebugText::DebugText(const sf::Font &font, int characterSize) {
    this->text.setFont(font);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(SILVER);
}

DebugText::~DebugText() = default;

// Public functions
void DebugText::setString(const std::string &value) {
    this->text.setString(value);
}

void DebugText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = nullptr;

    target.draw(this->text, states);
}