#ifndef SFML_SKELETON_MOUSEPOSITIONSTEXT_H
#define SFML_SKELETON_MOUSEPOSITIONSTEXT_H

#include <sstream>
#include "DebugText.h"
#include "../../utils/CommonStructs.h"

class MousePositionsText final : public DebugText {
public:
    MousePositionsText(const st::MousePositions &mousePositions, const sf::Font &font, int characterSize);

    ~MousePositionsText() override = default;
};

#endif //SFML_SKELETON_MOUSEPOSITIONSTEXT_H
