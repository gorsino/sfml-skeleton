#ifndef STATEDATA_H
#define STATEDATA_H

#include <stack>

#include "SFML/Graphics.hpp"

#include "../system/debug/DebugSystem.h"

class BaseState;

typedef std::stack<BaseState *> StackState;

class StateData {
public:
    StateData() = default;

    ~StateData() = default;

    sf::RenderWindow *window;
    sf::VideoMode *videoMode;
    sf::Font *font;
    KeyTime *keyTime;

    StackState *states;

    DebugSystem *debug;
};

#endif //STATEDATA_H
