#include "DebugText.h"

DebugText::DebugText(const sf::Font &font, int characterSize) {
    this->text_.setFont(font);
    this->text_.setCharacterSize(characterSize);
    this->text_.setFillColor(sf::Color::White);
}

DebugText::~DebugText() = default;

// Public functions
void DebugText::setString(const std::string &value) {
    this->text_.setString(value);
}

void DebugText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();

    states.texture = nullptr;

    target.draw(this->text_, states);
}