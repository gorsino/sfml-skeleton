#include "MousePositionsText.h"

MousePositionsText::MousePositionsText(
        const MousePositions &mousePositions, const sf::Font &font, int characterSize)
        : DebugText(font, characterSize) {

    std::stringstream ss;
    ss << "Mouse positions:" << "\n";
    ss << "------------------" << "\n";
    ss << "Screen: " << mousePositions.screen.x << "  " << mousePositions.screen.y << "\n";
    ss << "Window: " << mousePositions.window.x << "  " << mousePositions.window.y << "\n";
    ss << "View  : " << mousePositions.view.x << "  " << mousePositions.view.y;

    this->setPosition(
            static_cast<float>(mousePositions.window.x) + 30,
            static_cast<float>(mousePositions.window.y)
    );
    this->text.setString(ss.str());
}
