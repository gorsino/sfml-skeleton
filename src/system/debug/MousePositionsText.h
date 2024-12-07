#ifndef MOUSEPOSITIONSTEXT_H
#define MOUSEPOSITIONSTEXT_H

#include <sstream>
#include "DebugText.h"
#include "../../utils/TypeDefStructs.h"

class MousePositionsText final : public DebugText {
public:
    MousePositionsText(const MousePositions &mousePositions, const sf::Font &font, int characterSize);

    ~MousePositionsText() override = default;
};

#endif //MOUSEPOSITIONSTEXT_H
