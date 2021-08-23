cmake_minimum_required(VERSION 3.20)
project(3d-game-engine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
find_package(GTest REQUIRED)

add_executable(3d-game-engine game/main.cpp game/Engine.cpp game/Engine.h engine/Engine3D.cpp engine/Engine3D.h engine/primitives/Triangle.h engine/primitives/Mesh.h engine/primitives/Vector3D.h engine/primitives/Matrix.cpp engine/primitives/Matrix.h)
target_link_libraries(3d-game-engine sfml-graphics sfml-audio)
