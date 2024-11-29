#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "BaseState.h"
#include "../system/particle/ParticleSystem.h"

class GameState final : public BaseState {
public:
    explicit GameState(StateData &stateData);

    ~GameState() override = default;

    void updateInput(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    ParticleSystem particles_;
};

#endif //GAMESTATE_H
