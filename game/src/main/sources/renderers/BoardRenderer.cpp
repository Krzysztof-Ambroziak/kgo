#include "BoardRenderer.hpp"
#include "sources/go/BoardConstants.hpp"
#include "sources/go/GoPoint.hpp"
#include "sources/models/IBoardModel.hpp"

#include <QPainter>


BoardRenderer::BoardRenderer(const IBoardModel* const boardModel) : m_background{":/bg/wood1.jpg"},
                                                                    m_boardModel{boardModel} {}

void BoardRenderer::render(QPainter& painter) {
    const float margin = m_boardModel->isCoordinateLabelsVisible() ? ENLARGED_MARGIN : NORMAL_MARGIN;
    const int screenWidth = painter.window().width();
    const int baordSize = static_cast<int>(m_boardModel->size());
    m_fieldSize = int(screenWidth / (baordSize + 2*margin) + 0.5f);
    m_fieldOffset = (screenWidth - baordSize*m_fieldSize) / 2;
    
    drawBackground(painter);
    drawGrid(painter);
}

void BoardRenderer::drawBackground(QPainter& painter) {
    if(!m_background.isNull())
        painter.drawPixmap(0, 0, m_background);
}

void BoardRenderer::drawGrid(QPainter& painter) {
    const int size = static_cast<int>(m_boardModel->size());
    
    for(int y = 0; y < size; y++) {
        const QPoint& left = center(0, y);
        const QPoint& right = center(size - 1, y);
        
        painter.drawLine(left, right);
    }
    for(int x = 0; x < size; x++) {
        const QPoint& top = center(x, 0);
        const QPoint& bottom = center(x, size - 1);
        
        painter.drawLine(top, bottom);
    }
    
    const BoardConstants& constants = BoardConstants::instance(size);
    const GoPoint** const points = constants.points();
    painter.setBrush(Qt::BrushStyle::SolidPattern);
    painter.setRenderHints(QPainter::Antialiasing);
    for(int i = 0; i < constants.count(); ++i) {
        const GoPoint& p = *points[i];
        const QPoint& c = center(p.col(), p.row());
        painter.drawEllipse(c.x()-2, c.y()-2, 5, 5);
    }
    painter.setRenderHints(QPainter::Antialiasing, false);
}

const GoPoint& BoardRenderer::boardPoint(const QPoint& point) const {
    const int size = static_cast<int>(m_boardModel->size());
    const int col = (point.x() - m_fieldOffset) / m_fieldSize;
    const int row = size - ((point.x() - m_fieldOffset) / m_fieldSize) - 1;
    
    return (col >= 0 && col < size && row >= 0 && row < size) ? GoPoint::point(col, row)
                                                              : GoPoint::NULL_POINT;
}

QPoint BoardRenderer::center(int x, int y) const {
    QPoint point = location(x, y);
    const int halfFieldSize = m_fieldSize / 2;
    
    point.rx() += halfFieldSize;
    point.ry() += halfFieldSize;
    
    return point;
}

QPoint BoardRenderer::location(int x, int y) const {
    return {m_fieldOffset + x*m_fieldSize,
            m_fieldOffset + (static_cast<int>(m_boardModel->size()) - y - 1)*m_fieldSize};
}
