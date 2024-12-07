#include "InitialState.h"

InitialState::InitialState(StateData &stateData) : BaseState(stateData) {
    auto size = sf::Vector2f(
            static_cast<float >(stateData.window->getSize().x),
            static_cast<float >(stateData.window->getSize().y)
    );

    this->background_ = sf::RectangleShape(size);
    this->background_.setFillColor(POMEGRANATE);

    this->buttons_["GAME"] = new ui::Button(
            sf::Vector2f(400.f, 200.f),
            sf::Vector2f(300.f, 100.f),
            *this->stateData.font, "New Game", 30);
}

void InitialState::updateInputs(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->isKeyTime()) {
        this->exit = true;
    }
}

void InitialState::update(const float &dt) {
}

void InitialState::render() {
    this->stateData.window->draw(this->background_);

    for (auto &[fst, snd]: this->buttons_)
        this->stateData.window->draw(*snd);
}