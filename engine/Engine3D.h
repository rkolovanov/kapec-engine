#ifndef INC_3D_GAME_ENGINE_ENGINE3D_H
#define INC_3D_GAME_ENGINE_ENGINE3D_H

#include <SFML/Graphics.hpp>


namespace Engine {
    class Engine3D {
    public:
        Engine3D(const sf::VideoMode& videoMode, const std::string& title);
        int start();

        virtual bool onCreate() = 0;
        virtual void onUpdate(sf::Time elapsedTime) = 0;
        virtual void onEvent(sf::Event event) = 0;

    protected:
        sf::RenderWindow m_window;
    };
}


#endif // INC_3D_GAME_ENGINE_ENGINE3D_H
