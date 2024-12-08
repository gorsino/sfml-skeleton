#ifndef STATEDATA_H
#define STATEDATA_H

#include <stack>

#include "SFML/Graphics.hpp"

#include "../system/debug/DebugSystem.h"

class BaseState;

typedef std::stack<BaseState *> StackStates;

class StateData {
public:
    StateData() = default;

    ~StateData() = default;

    sf::RenderWindow *window;
    sf::VideoMode *videoMode;
    sf::Font *font;

    StackStates *states;
    KeyTime *keyTime;
    MousePositions *mousePositions;
    DebugSystem *debug;
};

#endif //STATEDATA_H
