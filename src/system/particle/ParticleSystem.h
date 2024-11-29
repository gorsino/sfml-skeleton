#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>

#include "SFML/Graphics.hpp"

class ParticleSystem final : public sf::Drawable {
public:
    ParticleSystem();

    ~ParticleSystem() override;

    void init(sf::Vector2u size);

    void update();

    void setEmitter(sf::Vector2i position);

    void reset(size_t count = 1024, float size = 5.f);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    struct Particle {
        sf::Vector2f velocity;
        int lifetime = 0;
        sf::Vector2i emitter;
    };

    std::vector<Particle> particles_;
    sf::VertexArray vertices_;
    sf::Vector2u windowSize_;

    float size_;

    void resetParticle(size_t index, bool first = false);
};

#endif //PARTICLESYSTEM_H
