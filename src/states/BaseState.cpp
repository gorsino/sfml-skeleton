#include "BaseState.h"

BaseState::BaseState(StateData &stateData) : stateData(stateData), exit_(false), defaultGridSize_(50) {
}

BaseState::~BaseState() = default;

void BaseState::updateKeyTime(const float &dt) {
    if (this->keyTime_ < this->keyTimeMax_)
        this->keyTime_ += 5 * dt;

    std::stringstream ss;
    ss << "KeyTime: " << this->keyTime_;

    DebugText keyTimeText(*this->stateData.font, 20);
    keyTimeText.setString(ss.str());

    this->stateData.debug->add(keyTimeText, KEY_TIME, sf::Vector2f(20, 100));
}

bool BaseState::isKeyTime() {
    if (this->keyTime_ >= this->keyTimeMax_) {
        this->keyTime_ = 0.f;
        return true;
    }

    return false;
}

bool &BaseState::isExit() {
    return this->exit_;
}

void BaseState::exit() {
    this->exit_ = true;
}