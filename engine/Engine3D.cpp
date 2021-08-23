#include "Engine3D.h"

Engine::Engine3D::Engine3D(const sf::VideoMode &videoMode, const std::string &title) : m_window(videoMode, title) {}

int Engine::Engine3D::start() {
    if (!onCreate()) {
        return 1;
    }

    sf::Clock clock;

    while (m_window.isOpen()) {
        sf::Event event{};

        while (m_window.pollEvent(event)) {
            onEvent(event);
        }

        m_window.clear();
        onUpdate(clock.getElapsedTime());
        m_window.display();
        clock.restart();
    }

    return 0;
}
