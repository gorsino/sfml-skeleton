#include "BaseState.h"

BaseState::BaseState(StateData &stateData) : stateData(stateData), exit_(false), defaultGridSize_(50) {
}

BaseState::~BaseState() = default;

void BaseState::updateInput(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->stateData.keyTime->isTime())
        this->exit_ = true;
}

void BaseState::update(const float &dt) {
}

bool &BaseState::isExit() {
    return this->exit_;
}

void BaseState::exit() {
    this->exit_ = true;
}