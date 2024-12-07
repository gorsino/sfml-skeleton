#include "MainMenuState.h"

MainMenuState::MainMenuState(StateData &stateData) : BaseState(stateData) {
    auto size = sf::Vector2f(
            static_cast<float >(stateData.window->getSize().x),
            static_cast<float >(stateData.window->getSize().y)
    );

    this->background_ = sf::RectangleShape(size);
    this->background_.setFillColor(POMEGRANATE);
}

void MainMenuState::updateInput(const float &dt) {
    BaseState::updateInput(dt);
}

void MainMenuState::update(const float &dt) {
    BaseState::update(dt);
}

void MainMenuState::render() {
    this->stateData.window->draw(this->background_);
}