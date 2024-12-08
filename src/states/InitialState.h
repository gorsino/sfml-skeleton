#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "BaseState.h"
#include "EditorState.h"
#include "../ui/UI.h"

class InitialState final : public BaseState {
public:
    explicit InitialState(StateData *stateData);

    ~InitialState() override = default;

    void updateInputs() override;

    void update() override;

    void render() override;

private:
    sf::RectangleShape background_;
    sf::RectangleShape panel_;

    MapButtons buttons_;
};

#endif //INITIALSTATE_H
