#ifndef EDITORSTATE_H
#define EDITORSTATE_H

#include "BaseState.h"
#include "../system/particle/ParticleSystem.h"
#include "../entities/EntityManager.h"

class EditorState final : public BaseState {
public:
    explicit EditorState(StateData *stateData);

    ~EditorState() override;

    void updateInputs(const float &dt) override;

    void update(const float &dt) override;

    void render() override;

private:
    void debugTotalEntities();

    EntityManager entityManager_;
};

#endif //EDITORSTATE_H
