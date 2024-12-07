#include "UI.h"

/////////////////////////////////
/// Button
/////////////////////////////////
ui::Button::Button(const sf::Vector2f position, const sf::Vector2f size, sf::Font &font, const std::string &text, const unsigned characterSize) {
    this->initDefaultColors();
    this->initRect(position, size);
    this->initText(font, text, characterSize);
}

ui::Button::~Button() = default;

void ui::Button::setColorStates(const ColorStates &colorStates) {
    this->shapeColorStates_ = colorStates;
}

void ui::Button::setTextColorStates(const ColorStates &colorStates) {
    this->textColorStates_ = colorStates;
}

void ui::Button::setTextStyle(const sf::Text::Style &style) {
    this->getText().setStyle(style);
}

bool ui::Button::isPressed() const {
    return (this->buttonState == BUTTON_ACTIVE);
}

void ui::Button::initRect(const sf::Vector2f position, const sf::Vector2f size) {
    this->getRect().setPosition(position);
    this->getRect().setFillColor(this->shapeColorStates_.idle);
    this->getRect().setSize(size);
}

void ui::Button::initText(sf::Font &font, const std::string &text, const unsigned characterSize) {
    this->setFont(font);
    this->getText().setFont(font);
    this->getText().setString(text);
    this->getText().setFillColor(this->textColorStates_.idle);
    this->getText().setCharacterSize(characterSize);
    this->getText().setPosition(
        this->getRect().getPosition().x + this->getRect().getGlobalBounds().width / 2.f
        - this->getText().getGlobalBounds().width / 2.f,
        this->getRect().getPosition().y + this->getRect().getGlobalBounds().height / 3.f
        - this->getText().getGlobalBounds().height / 3.f
    );
}

void ui::Button::update(const sf::Vector2f mousePos) {
    this->buttonState = BUTTON_IDLE;

    if (this->disabled_) {
        this->getRect().setFillColor(SILVER);
        this->getText().setFillColor(WET_ASPHALT);
        return;
    }

    if (this->getRect().getGlobalBounds().contains(mousePos)) {
        this->buttonState = BUTTON_HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            this->buttonState = BUTTON_ACTIVE;
    }

    switch (this->buttonState) {
        case BUTTON_IDLE:
            this->getRect().setFillColor(this->shapeColorStates_.idle);
            this->getText().setFillColor(this->textColorStates_.idle);
            break;
        case BUTTON_HOVER:
            this->getRect().setFillColor(this->shapeColorStates_.hover);
            this->getText().setFillColor(this->textColorStates_.hover);
            break;
        case BUTTON_ACTIVE:
            this->getRect().setFillColor(this->shapeColorStates_.active);
            this->getText().setFillColor(this->textColorStates_.active);
            break;
        default:
            this->getRect().setFillColor(POMEGRANATE);
            this->getText().setFillColor(BELIZE_HOLE);
            break;
    }
}

void ui::Button::disabled() {
    this->disabled_ = true;
}

void ui::Button::enabled() {
    this->disabled_ = false;
}

void ui::Button::initDefaultColors() {
    this->textColorStates_.idle = CLOUDS;
    this->textColorStates_.hover = CLOUDS;
    this->textColorStates_.active = CLOUDS;

    this->shapeColorStates_.idle = WET_ASPHALT;
    this->shapeColorStates_.hover = BELIZE_HOLE;
    this->shapeColorStates_.active = NEPHRITIS;
}