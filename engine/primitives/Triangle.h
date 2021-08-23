#ifndef INC_3D_GAME_ENGINE_TRIANGLE_H
#define INC_3D_GAME_ENGINE_TRIANGLE_H

#include "Vector3D.h"
#include <SFML/Graphics.hpp>


namespace Engine {
    namespace Primitives {
        struct Triangle {
            Vector3D vertexes[3];
        };
    }
}


#endif //INC_3D_GAME_ENGINE_TRIANGLE_H
