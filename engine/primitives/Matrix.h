#ifndef INC_3D_GAME_ENGINE_MATRIX_H
#define INC_3D_GAME_ENGINE_MATRIX_H

#include <vector>


namespace Engine {
    namespace Primitives {
        class Matrix {
        public:
            Matrix(size_t sizeX, size_t sizeY);
            double& get(size_t i, size_t j);

        private:
            struct MatrixRow {
                std::vector<double> row;

                explicit MatrixRow(size_t sizeX);
            };

            std::vector<MatrixRow> m_rows;
        };
    }
}


#endif //INC_3D_GAME_ENGINE_MATRIX_H
