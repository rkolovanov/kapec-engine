#ifndef INC_3D_GAME_ENGINE_ENGINE_H
#define INC_3D_GAME_ENGINE_ENGINE_H

#include "../engine/Engine3D.h"
#include "../engine/primitives/Mesh.h"
#include "../engine/primitives/Matrix.h"
#include "../engine/primitives/Vector3D.h"


namespace Game {
    class Engine : public ::Engine::Engine3D {
    public:
        Engine(const sf::VideoMode& videoMode, const std::string& title);
        bool onCreate() override;
        void onUpdate(sf::Time elapsedTime) override;
        void onEvent(sf::Event event) override;

    private:
        void MultiplyMatrix(::Engine::Primitives::Vector3D& i, ::Engine::Primitives::Vector3D& o,
                            ::Engine::Primitives::Matrix m);
        void drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
        void drawLine(sf::Vector2f a, sf::Vector2f b);

        ::Engine::Primitives::Mesh mesh;
        ::Engine::Primitives::Matrix matrix;
        double angle;
    };
}


#endif // INC_3D_GAME_ENGINE_ENGINE_H
