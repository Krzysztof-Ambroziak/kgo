#include "Board.hpp"
#include "sources/renderers/NullRenderer.hpp"

#include <QPainter>

Board::Board(QWidget* const parent) : QWidget{parent},
                                      m_renderer(&NullRenderer::instance()) {
    QPalette palette(Qt::darkGray);
    setAutoFillBackground(true);
    setPalette(palette);
}

void Board::setRenderer(IRenderer* renderer) {
    m_renderer = renderer;
}

void Board::paintEvent(QPaintEvent* event) {
    static QPainter painter;
    
    painter.begin(this);
    m_renderer->render(painter);
    painter.end();
}
