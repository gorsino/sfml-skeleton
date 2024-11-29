#ifndef BASESTATE_H
#define BASESTATE_H

#include <sstream>
#include "StateData.h"

class BaseState {
public:
    virtual ~BaseState();

    virtual void updateInput(const float &dt) = 0;

    virtual void update(const float &dt) = 0;

    virtual void render() = 0;

    bool isKeyTime();

    bool &isExit();

    void exit();

protected:
    explicit BaseState(StateData &stateData);

    void updateKeyTime(const float &dt);

    // Variables
    StateData &stateData;

    float keyTime_ = 0.f;
    float keyTimeMax_ = 1.f;

private:
    bool exit_;

    unsigned int defaultGridSize_;
};

#endif //BASESTATE_H
