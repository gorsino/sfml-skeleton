#ifndef DEBUGTEXT_H
#define DEBUGTEXT_H

#include "SFML/Graphics/Text.hpp"

class DebugText {
public:
    DebugText();
    ~DebugText();

    void setFont(const sf::Font& font);

    void setText(const std::string &text);
    sf::Text getText();

private:
    sf::Text text_;
};

#endif //DEBUGTEXT_H
