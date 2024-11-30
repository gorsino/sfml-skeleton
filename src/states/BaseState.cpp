#include "BaseState.h"

BaseState::BaseState(StateData &stateData) : stateData(stateData), exit_(false), defaultGridSize_(50) {
}

BaseState::~BaseState() = default;

void BaseState::update(const float &dt) {
    this->updateKeyTime(dt);
    this->updateMousePositions();
}

void BaseState::updateKeyTime(const float &dt) {
    if (this->keyTime_ < this->keyTimeMax_)
        this->keyTime_ += 5 * dt;

    std::stringstream ss;
    ss << "KeyTime: " << this->keyTime_;

    DebugText keyTimeText(*this->stateData.font, 20);
    keyTimeText.setString(ss.str());

    this->stateData.debug->add(keyTimeText, KEY_TIME, sf::Vector2f(20, 100));
}

void BaseState::updateMousePositions() {
    this->mousePositions_.screen = sf::Mouse::getPosition();
    this->mousePositions_.window = sf::Mouse::getPosition(*this->stateData.window);
    this->mousePositions_.view = this->stateData.window->mapPixelToCoords(this->mousePositions_.window);

    MousePositionsText mousePositionsText(this->mousePositions_, *this->stateData.font, 20);

    this->stateData.debug->add(mousePositionsText, MOUSE_POSITIONS, sf::Vector2f(20, 140));
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