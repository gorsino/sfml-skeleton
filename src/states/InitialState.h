#ifndef INITIALSTATE_H
#define INITIALSTATE_H

#include "BaseState.h"
#include "../ui/UI.h"

class InitialState final : public BaseState {
public:
    explicit InitialState(StateData &stateData);

    ~InitialState() override = default;

    void updateInputs(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    sf::RectangleShape background_;

    std::map<std::string, ui::Button *> buttons_;
};

#endif //INITIALSTATE_H
