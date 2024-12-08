#ifndef BASESTATE_H
#define BASESTATE_H

#include <sstream>
#include "../system/debug/MousePositionsText.h"
#include "../utils/TypeDefStructs.h"
#include "StateData.h"

class BaseState {
public:
    virtual ~BaseState() = default;

    virtual void updateInputs() = 0;

    virtual void update() = 0;

    virtual void render() = 0;

    void stackState(BaseState *state) { this->stateData->states->push(state); }

    [[nodiscard]] bool isKeyTime() const { return this->stateData->keyTime->isTime(); }

    std::string name;

    bool exit = false;

protected:
    explicit BaseState(StateData *stateData) : stateData(stateData) {}

    // Variables
    StateData *stateData;
};

#endif //BASESTATE_H