#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "BaseState.h"
#include "EditorState.h"
#include "../ui/UI.h"

class InitialState final : public BaseState {
public:
    explicit InitialState(StateData *stateData);

    ~InitialState() override = default;

    void updateInputs(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    sf::RectangleShape background_;

    MapButtons buttons_;
};

#endif //INITIALSTATE_H
