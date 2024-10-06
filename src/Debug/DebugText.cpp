#include "DebugText.h"

DebugText::DebugText() {
    this->text_.setCharacterSize(16);
    this->text_.setFillColor(sf::Color::White);
}

DebugText::~DebugText() = default;

void DebugText::setFont(const sf::Font &font) {
    this->text_.setFont(font);
}

// Public functions
void DebugText::setText(const std::string &text) {
    this->text_.setString(text);
}

sf::Text DebugText::getText() {
    return this->text_;
}
