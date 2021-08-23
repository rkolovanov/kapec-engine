#include "Engine.h"
#include <cmath>


Game::Engine::Engine(const sf::VideoMode& videoMode, const std::string& title) :
Engine3D(videoMode, title), matrix(4, 4) {}

bool Game::Engine::onCreate() {
    mesh.triangles = {
            // FRONT
            {0,0,0, 0,1,0, 1,1,0},
            {0,0,0, 1,1,0, 1,0,0},

            // BACK
            {1,0,1, 1,1,1, 0,1,1},
            {1,0,1, 0,1,1, 0,0,1},

            // LEFT
            {0,0,1, 0,1,1, 0,1,0},
            {0,0,1, 0,1,0, 0,0,0},

            // RIGHT
            {1,0,0, 1,1,0, 1,1,1},
            {1,0,0, 1,1,1, 1,0,1},

            // TOP
            {0,1,0, 0,1,1, 1,1,1},
            {0,1,0, 1,1,1, 1,1,0},

            // BOTTOM
            {0,0,0, 0,0,1, 1,0,1},
            {0,0,0, 1,0,1, 1,0,0}
    };

    double near = 0.1;
    double far = 1000.0;
    double fov = 90;
    double aspectRatio = (double)m_window.getSize().y / (double)m_window.getSize().x;
    double fovRat = 1.0 / (tan(fov * 0.5 / 180.0 * M_PI));

    matrix.get(0, 0) = aspectRatio * fovRat;
    matrix.get(1, 1) = fovRat;
    matrix.get(2, 2) = far / (far - near);
    matrix.get(3, 2) = -far * near / (far - near);
    matrix.get(2, 3) = 1.0;
    matrix.get(3, 3) = 0.0;

    return true;
}

void Game::Engine::onUpdate(sf::Time elapsedTime) {
    ::Engine::Primitives::Matrix rotZ(4, 4), rotX(4, 4);
    angle += elapsedTime.asSeconds() * 3.0;

    rotZ.get(0, 0) = cos(angle);
    rotZ.get(0, 1) = sin(angle);
    rotZ.get(1, 0) = -sin(angle);
    rotZ.get(1, 1) = cos(angle);
    rotZ.get(2, 2) = 1.0;
    rotZ.get(3, 3) = 1.0;

    rotX.get(0, 0) = 1.0;
    rotX.get(1, 1) = cos(angle * 0.5);
    rotX.get(1, 2) = sin(angle * 0.5);
    rotX.get(2, 1) = -sin(angle * 0.5);
    rotX.get(2, 2) = cos(angle * 0.5);
    rotX.get(3, 3) = 1.0;

    for (auto triangle : mesh.triangles) {
        ::Engine::Primitives::Triangle projective, translated, rotatedZ, rotatedZX;

        MultiplyMatrix(triangle.vertexes[0], rotatedZ.vertexes[0], rotZ);
        MultiplyMatrix(triangle.vertexes[1], rotatedZ.vertexes[1], rotZ);
        MultiplyMatrix(triangle.vertexes[2], rotatedZ.vertexes[2], rotZ);

        MultiplyMatrix(rotatedZ.vertexes[0], rotatedZX.vertexes[0], rotX);
        MultiplyMatrix(rotatedZ.vertexes[1], rotatedZX.vertexes[1], rotX);
        MultiplyMatrix(rotatedZ.vertexes[2], rotatedZX.vertexes[2], rotX);

        translated = rotatedZX;
        translated.vertexes[0].z = rotatedZX.vertexes[0].z + 3.0;
        translated.vertexes[1].z = rotatedZX.vertexes[1].z + 3.0;
        translated.vertexes[2].z = rotatedZX.vertexes[2].z + 3.0;

        MultiplyMatrix(translated.vertexes[0], projective.vertexes[0], matrix);
        MultiplyMatrix(translated.vertexes[1], projective.vertexes[1], matrix);
        MultiplyMatrix(translated.vertexes[2], projective.vertexes[2], matrix);

        projective.vertexes[0].x += 1.0; projective.vertexes[0].y += 1.0;
        projective.vertexes[1].x += 1.0; projective.vertexes[1].y += 1.0;
        projective.vertexes[2].x += 1.0; projective.vertexes[2].y += 1.0;

        projective.vertexes[0].x *= 0.5 * (double)m_window.getSize().x;
        projective.vertexes[0].y *= 0.5 * (double)m_window.getSize().y;
        projective.vertexes[1].x *= 0.5 * (double)m_window.getSize().x;
        projective.vertexes[1].y *= 0.5 * (double)m_window.getSize().y;
        projective.vertexes[2].x *= 0.5 * (double)m_window.getSize().x;
        projective.vertexes[2].y *= 0.5 * (double)m_window.getSize().y;

        drawTriangle(projective.vertexes[0].x, projective.vertexes[0].y,
                     projective.vertexes[1].x, projective.vertexes[1].y,
                     projective.vertexes[2].x, projective.vertexes[2].y);
    }
}

void Game::Engine::onEvent(sf::Event event) {
    if (event.type == sf::Event::Closed) {
        m_window.close();
    }
}

void Game::Engine::MultiplyMatrix(::Engine::Primitives::Vector3D &i, ::Engine::Primitives::Vector3D &o,
                                  ::Engine::Primitives::Matrix m) {
    o.x = i.x * m.get(0, 0) + i.y * m.get(1, 0) + i.z * m.get(2, 0) + m.get(3, 0);
    o.y = i.x * m.get(0, 1) + i.y * m.get(1, 1) + i.z * m.get(2, 1) + m.get(3, 1);
    o.z = i.x * m.get(0, 2) + i.y * m.get(1, 2) + i.z * m.get(2, 2) + m.get(3, 2);
    float w = i.x * m.get(0, 3) + i.y * m.get(1, 3) + i.z * m.get(2, 3) + m.get(3, 3);
    if (w != 0) {
        o.x /= w; o.y /= w; o.z /= w;
    }
}

void Game::Engine::drawTriangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    drawLine(sf::Vector2f(x1, y1), sf::Vector2f(x2, y2));
    drawLine(sf::Vector2f(x2, y2), sf::Vector2f(x3, y3));
    drawLine(sf::Vector2f(x3, y3), sf::Vector2f(x1, y1));
}

void Game::Engine::drawLine(sf::Vector2f a, sf::Vector2f b) {
    sf::Vertex line[] =
            {
            sf::Vertex(a),
            sf::Vertex(b)
            };

    m_window.draw(line, 2, sf::Lines);
}
