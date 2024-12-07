#ifndef GUI_H
#define GUI_H

#include "SFML/Graphics/Font.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Text.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Mouse.hpp"

#include "../utils/PaletteColors.h"
#include "../utils/TypeDefStructs.h"

namespace ui {
    /////////////////////////////////
    /// UI
    /////////////////////////////////
    class UI : public sf::Drawable {
    protected:
        UI() = default;

        ~UI() override = default;

        virtual void update(sf::Vector2f mousePos) = 0;

        void setFont(const sf::Font &font) {
            this->font_ = font;
        }

        void setText(const sf::Text &text) {
            this->text_ = text;
        }

        sf::Text &getText() {
            return this->text_;
        }

        sf::RectangleShape &getRect() {
            return this->rect_;
        }

        void draw(sf::RenderTarget &target, const sf::RenderStates states) const override {
            target.draw(this->rect_, states);
            target.draw(this->text_, states);
        }

    private:
        virtual void initRect(sf::Vector2f position, sf::Vector2f size) = 0;

        virtual void initText(sf::Font &font, const std::string &text, unsigned characterSize) = 0;

        sf::Font font_;
        sf::Text text_;
        sf::RectangleShape rect_;
    };

    /////////////////////////////////
    /// Button
    /////////////////////////////////
    class Button final : public UI {
    public:
        Button(sf::Vector2f position, sf::Vector2f size, sf::Font &font, const std::string &text,
               unsigned characterSize);

        ~Button() override;

        // Functions
        void update(sf::Vector2f mousePos) override;

        void disabled();

        void enabled();

        // Accessors
        void setColorStates(const ColorStates &colorStates);

        void setTextColorStates(const ColorStates &colorStates);

        void setTextStyle(const sf::Text::Style &style);

        bool isPressed() const;

    private:
        // Functions
        void initRect(sf::Vector2f position, sf::Vector2f size) override;

        void initText(sf::Font &font, const std::string &text, unsigned characterSize) override;

        void initDefaultColors();

        enum ButtonStates {
            BUTTON_IDLE = 0, BUTTON_HOVER, BUTTON_ACTIVE
        };

        // Variables
        ColorStates textColorStates_;
        ColorStates shapeColorStates_;

        short unsigned buttonState = BUTTON_IDLE;
        bool disabled_ = false;
    };
}

#endif //GUI_H
