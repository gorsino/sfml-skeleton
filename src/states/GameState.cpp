#include "GameState.h"

GameState::GameState(StateData &stateData): BaseState(stateData) {
    this->particles_.init(stateData.window->getSize());
}

void GameState::updateInput(const float &dt) {
    BaseState::updateInput(dt);

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->stateData.keyTime->isTime()) {
        this->particles_.setEmitter(sf::Mouse::getPosition(*this->stateData.window));
    }
}

void GameState::update(const float &dt) {
    BaseState::update(dt);

    this->particles_.update();
}

void GameState::render() {
    this->stateData.window->draw(this->particles_);
}