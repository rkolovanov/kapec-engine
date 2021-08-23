#include "Engine.h"

int main(int argc, char** argv) {
    Game::Engine engine(sf::VideoMode(800, 600), "3D Game");
    return engine.start();
}