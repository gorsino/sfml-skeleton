#include "Game.h"

#include "Debug/DebugText.h"

// Constructor / Destructor
Game::Game() {
    this->initVariables();
    this->initFont();
    this->initWindow();
}

Game::~Game() {
    delete this->window_;
}

// Public functions
void Game::run() {
    while (this->window_->isOpen()) {
        // Update delta time
        this->dt_ = this->dtClock_.restart().asSeconds();

        // Update SFML events
        this->updateSFMLEvents();

        // Update and render
        this->update();
        this->render();
    }
}

void Game::updateSFMLEvents() {
    while (this->window_->pollEvent(this->sfEvent_)) {
        if (this->sfEvent_.type == sf::Event::Closed)
            this->window_->close();
    }
}

void Game::update() {
    // Game logic here...
}

void Game::render() const {
    this->window_->clear();

    // Render all game objects before display (player, enemies, etc...)
    // - HERE -

    // ----------------------------------------------------------------
    // DEBUG: display delta time
    DebugText debugText;
    debugText.setFont(this->font_);

    std::stringstream ss;
    ss << "DeltaTime: " << this->dt_;

    debugText.setText(ss.str());

    this->window_->draw(debugText.getText());
    // END DEBUG
    // ----------------------------------------------------------------

    this->window_->display();
}

// Private functions
void Game::initVariables() {
    this->dt_ = 0.f;
    this->window_ = nullptr;
}

void Game::initWindow() {
    const std::string title = "SFML Skeleton";
    const sf::VideoMode vm(1920u, 1080u);

    this->window_ = new sf::RenderWindow(sf::VideoMode(vm.width, vm.height), title);
    this->window_->setFramerateLimit(144);
}

void Game::initFont() {
    if (!this->font_.loadFromFile(FONTS_PATH + "arialbd.ttf"))
        throw std::runtime_error("ERROR::Game::initFont(): Failed to load font");
}
