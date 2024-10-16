#include "MousePositionsText.h"

MousePositionsText::MousePositionsText(MousePositions mousePositions, const sf::Font &font, int characterSize)
        : DebugText(font, characterSize) {

    std::stringstream ss;
    ss << "S: " << mousePositions.screen.x << "  " << mousePositions.screen.y << "\n";
    ss << "W: " << mousePositions.window.x << "  " << mousePositions.window.y << "\n";
    ss << "V: " << mousePositions.view.x << "  " << mousePositions.view.y;
    this->setPosition(
            static_cast<float>(mousePositions.window.x) + 30,
            static_cast<float >(mousePositions.window.y)
    );
    this->text.setString(ss.str());
}

void MousePositionsText::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    DebugText::draw(target, states);
}

MousePositionsText::~MousePositionsText() = default;
