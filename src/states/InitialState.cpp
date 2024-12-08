#include "InitialState.h"

InitialState::InitialState(StateData *stateData) : BaseState(stateData) {
    this->name = "Initial";

    auto size = sf::Vector2f(
            static_cast<float >(stateData->window->getSize().x),
            static_cast<float >(stateData->window->getSize().y)
    );

    this->background_ = sf::RectangleShape(size);
    this->background_.setFillColor(POMEGRANATE);

    auto posX = (static_cast<float >(stateData->window->getSize().x) - 300.f) / 2.f;
    this->buttons_["EDITOR"] = new ui::Button(
            sf::Vector2f(posX, 200.f),
            sf::Vector2f(300.f, 100.f),
            *this->stateData->font, "Editor", 30);

    this->buttons_["EXIT"] = new ui::Button(
            sf::Vector2f(posX, 310.f),
            sf::Vector2f(300.f, 100.f),
            *this->stateData->font, "Exit", 30);
}

void InitialState::updateInputs(const float &dt) {
    if ((this->buttons_["EXIT"]->isPressed() || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) && this->isKeyTime()) {
        this->exit = true;
    }

    if (this->buttons_["EDITOR"]->isPressed() && this->isKeyTime())
        this->stateData->states->push(new EditorState(this->stateData));
}

void InitialState::update(const float &dt) {
    for (auto &[fst, snd]: this->buttons_)
        snd->update(static_cast<sf::Vector2f>(this->stateData->mousePositions->window));
}

void InitialState::render() {
    this->stateData->window->draw(this->background_);

    for (auto &[fst, snd]: this->buttons_)
        this->stateData->window->draw(*snd);
}