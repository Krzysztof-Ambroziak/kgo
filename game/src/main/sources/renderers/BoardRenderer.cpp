#include "BoardRenderer.hpp"

#include <QPainter>

#include "sources/models/BoardModel.hpp"

BoardRenderer::BoardRenderer(const BoardModel* const boardModel) : m_boardModel{boardModel} {}

void BoardRenderer::render(QPainter& painter) {
    painter.drawPixmap(0, 0, m_boardModel->background());
    painter.drawPixmap(0, 0, m_boardModel->grid());
}
