#ifndef SFML_SKELETON_MAINMENUSTATE_H
#define SFML_SKELETON_MAINMENUSTATE_H

#include "BaseState.h"

class MainMenuState final : public BaseState {
public:
    explicit MainMenuState(StateData &stateData);

    ~MainMenuState() override = default;

    void updateInput(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    sf::RectangleShape background_;
};

#endif //SFML_SKELETON_MAINMENUSTATE_H
