#ifndef INC_3D_GAME_ENGINE_MESH_H
#define INC_3D_GAME_ENGINE_MESH_H

#include "Triangle.h"
#include <vector>


namespace Engine {
    namespace Primitives {
        struct Mesh {
            std::vector<Triangle> triangles;
        };
    }
}


#endif //INC_3D_GAME_ENGINE_MESH_H
