#include "Game.h"

////////////////////////////////
/// Constructor / Destructor ///
////////////////////////////////
Game::Game() : window_(nullptr), sfEvent_(sf::Event()), stateData_(StateData()) {
    this->initFont();
    this->initWindow();
    this->initDebugSystem();
    this->initState();
}

Game::~Game() {
    while (!this->states_.empty()) {
        delete this->states_.top();
        this->states_.pop();
    }

    delete this->window_;
}

//////////////////////////
/// MAIN LOOP function ///
//////////////////////////
void Game::run() {
    while (this->window_->isOpen()) {
        // Clear debug system first
        this->debugSystem_.clear();

        // Update delta time
        this->dt_ = this->dtClock_.restart().asSeconds();

        // Update key time
        this->keyTime_.update(this->dt_);

        // Update mouse positions
        this->mousePositions_.update(*this->window_);

        // Update SFML events
        this->updateSFMLEvents();

        // Update states
        this->updateStates();

        // Rendering
        this->render();
    }
}

////////////////////////
/// Update functions ///
////////////////////////
void Game::updateSFMLEvents() {
    while (this->window_->pollEvent(this->sfEvent_)) {
        // Toggle show/hide debug system
        if (this->sfEvent_.key.code == sf::Keyboard::T && this->keyTime_.isTime())
            this->debugSystem_.toggleActive();

        // End Game/Application
        if (this->sfEvent_.type == sf::Event::Closed)
            this->window_->close();
    }
}

void Game::updateStates() {
    if (this->states_.empty())
        // End Game/Application
        this->window_->close();
    else {
        // Update current active state
        this->states_.top()->updateInputs(this->dt_);
        this->states_.top()->update(this->dt_);

        // Delete state when exit
        if (this->states_.top()->exit) {
            delete this->states_.top();
            this->states_.pop();
        }
    }
}

/////////////////
/// Rendering ///
/////////////////
void Game::render() {
    /// Clear before rendering
    this->window_->clear();

    /// Render active state
    {
        if (!this->states_.empty())
            this->states_.top()->render();
    }

    /// DEBUG START
    this->debugDeltaTime();
    this->debugKeyTime();
    this->debugMousePositions();

    this->window_->draw(this->debugSystem_);
    /// DEBUG END

    this->window_->display();
}

///////////////////////
/// Debug functions ///
///////////////////////
void Game::debugDeltaTime() {
    std::stringstream ss;
    ss << "DeltaTime: " << this->dt_;

    DebugText deltaTimeText(this->font_, 22);
    deltaTimeText.setString(ss.str());

    this->debugSystem_.add(deltaTimeText, DELTA_TIME, sf::Vector2f(20, 80));
}

void Game::debugKeyTime() {
    std::stringstream ss;
    ss << "KeyTime: " << this->keyTime_.time;

    DebugText keyTimeText(this->font_, 22);
    keyTimeText.setString(ss.str());

    this->debugSystem_.add(keyTimeText, KEY_TIME, sf::Vector2f(20, 110));
}

void Game::debugMousePositions() {
    MousePositionsText mousePositionsText(
            this->mousePositions_, this->font_, 20);

    this->debugSystem_.add(
            mousePositionsText, MOUSE_POSITIONS, sf::Vector2f(20, 160));
}

//////////////////////
/// Init functions ///
//////////////////////
void Game::initWindow() {
    const std::string title = "SFML Skeleton";

    this->mode_ = sf::VideoMode(1920u, 1080u);

    this->window_ = new sf::RenderWindow(this->mode_, title, sf::Style::Titlebar | sf::Style::Close);
    this->window_->setFramerateLimit(144);
}

void Game::initFont() {
    if (!this->font_.loadFromFile(FONTS_PATH + "courbd.ttf"))
        throw std::runtime_error("ERROR::Game::initFont(): Failed to load font");
}

void Game::initDebugSystem() {
    this->debugSystem_ =
            DebugSystem(sf::Vector2f(50, 50), sf::Vector2f(300, 600), this->font_);
}

void Game::initState() {
    this->stateData_.window = this->window_;
    this->stateData_.videoMode = &this->mode_;
    this->stateData_.font = &this->font_;
    this->stateData_.states = &this->states_;
    this->stateData_.keyTime = &this->keyTime_;
    this->stateData_.mousePositions = &this->mousePositions_;
    this->stateData_.debug = &this->debugSystem_;

    this->states_.push(new InitialState(&this->stateData_));
}