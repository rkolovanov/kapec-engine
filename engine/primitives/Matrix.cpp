#include "Matrix.h"

Engine::Primitives::Matrix::Matrix(size_t sizeX, size_t sizeY) {
    m_rows.resize(sizeY, MatrixRow(sizeX));
}

double& Engine::Primitives::Matrix::get(size_t i, size_t j) {
    return m_rows[i].row[j];
}

Engine::Primitives::Matrix::MatrixRow::MatrixRow(size_t sizeX) {
    row.resize(sizeX, 0.0);
}

