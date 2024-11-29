#ifndef COMMONSTRUCTS_H
#define COMMONSTRUCTS_H

namespace st {
    struct MousePositions
    {
        sf::Vector2i screen = sf::Vector2i(0, 0);
        sf::Vector2i window = sf::Vector2i(0, 0);
        sf::Vector2f view = sf::Vector2f(0, 0);
    };
}

#endif //COMMONSTRUCTS_H
