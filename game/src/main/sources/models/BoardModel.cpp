#include "BoardModel.hpp"

const QPixmap& BoardModel::background() const {
    return m_background;
}

void BoardModel::setBackground(const QPixmap& background) {
    m_background = background;
}

const QPixmap& BoardModel::grid() const {
    return m_grid;
}

void BoardModel::setGrid(const QPixmap& grid) {
    m_grid = grid;
}
