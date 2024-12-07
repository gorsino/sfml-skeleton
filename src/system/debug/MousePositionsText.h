#ifndef SFML_SKELETON_MOUSEPOSITIONSTEXT_H
#define SFML_SKELETON_MOUSEPOSITIONSTEXT_H

#include <sstream>
#include "DebugText.h"
#include "../../utils/TypeDefStructs.h"

class MousePositionsText final : public DebugText {
public:
    MousePositionsText(const MousePositions &mousePositions, const sf::Font &font, int characterSize);

    ~MousePositionsText() override = default;
};

#endif //SFML_SKELETON_MOUSEPOSITIONSTEXT_H
