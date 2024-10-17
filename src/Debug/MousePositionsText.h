#ifndef SFML_SKELETON_MOUSEPOSITIONSTEXT_H
#define SFML_SKELETON_MOUSEPOSITIONSTEXT_H

#include "DebugText.h"
#include "../Game.h"

class MousePositionsText final : public DebugText {
public:
    MousePositionsText(const MousePositions &mousePositions, const sf::Font &font, int characterSize);

    ~MousePositionsText() override;
};

#endif //SFML_SKELETON_MOUSEPOSITIONSTEXT_H
