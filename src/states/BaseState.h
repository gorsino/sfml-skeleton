#ifndef BASESTATE_H
#define BASESTATE_H

#include <sstream>
#include "../system/debug/MousePositionsText.h"
#include "../utils/TypeDefStructs.h"
#include "StateData.h"

class BaseState {
public:
    virtual ~BaseState();

    virtual void updateInput(const float &dt);

    virtual void update(const float &dt);

    virtual void render() = 0;

    bool &isExit();

    void exit();

protected:
    explicit BaseState(StateData &stateData);

    // Variables
    StateData &stateData;

    MousePositions mousePositions_;

private:
    bool exit_;

    unsigned int defaultGridSize_;
};

#endif //BASESTATE_H
