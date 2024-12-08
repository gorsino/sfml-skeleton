#ifndef GAME_H
#define GAME_H

#include "SFML/Graphics.hpp"

#include "states/EditorState.h"
#include "states/InitialState.h"

static const std::string FONTS_PATH = "resources/fonts/";

class Game {
public:
    /// Constructor / Destructor
    Game();

    ~Game();

    /// Functions
    void run();

private:
    /// Functions
    void initWindow();

    void initFont();

    void initDebugSystem();

    void initState();

    void updateStates();

    void render();

    void updateSFMLEvents();

    void debugDeltaTime();

    void debugKeyTime();

    void debugMousePositions();

    /// Variables
    sf::RenderWindow *window_;
    sf::VideoMode mode_;
    sf::Event sfEvent_;
    sf::Font font_;
    sf::Clock dtClock_;

    StackStates states_;
    StateData stateData_;
    KeyTime keyTime_;
    MousePositions mousePositions_;
    DebugSystem debugSystem_;

    float dt_ = 0.f;
};

#endif //GAME_H
