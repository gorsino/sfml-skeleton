#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "BaseState.h"
#include "../system/particle/ParticleSystem.h"
#include "../entities/EntityManager.h"

class GameState final : public BaseState {
public:
    explicit GameState(StateData &stateData);

    ~GameState() override;

    void updateInputs(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    EntityManager entityManager_;
};

#endif //GAMESTATE_H
