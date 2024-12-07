#ifndef STATEDATA_H
#define STATEDATA_H

#include <stack>

#include "SFML/Graphics.hpp"

#include "../system/debug/DebugSystem.h"

class BaseState;

class StateData {
public:
    StateData() = default;

    ~StateData() = default;

    sf::RenderWindow *window;
    sf::VideoMode *videoMode;
    sf::Font *font;
    KeyTime *keyTime;

    std::stack<BaseState *> *states;

    DebugSystem *debug;
};

#endif //STATEDATA_H
