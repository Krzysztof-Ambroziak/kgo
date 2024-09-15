#include "Board.hpp"
#include "sources/renderers/NullRenderer.hpp"

#include <QPainter>
#include <QResizeEvent>

Board::Board(QWidget* const parent) : QWidget{parent},
                                      m_renderer(&NullRenderer::instance()) {
    QPalette palette(QColor(239, 187, 134));
    setAutoFillBackground(true);
    setPalette(palette);
}

void Board::setListener(Listener* const listener) {
    m_listener = listener;
}

void Board::setRenderer(IRenderer* const renderer) {
    m_renderer = renderer;
}

void Board::paintEvent(QPaintEvent* const event) {
    static QPainter painter;
    
    painter.begin(this);
    m_renderer->render(painter);
    painter.end();
}


void Board::resizeEvent(QResizeEvent* const event) {
    emit sizeChanged(event->size().width());
}

void Board::mousePressEvent(QMouseEvent* const event) {
    if(m_listener != nullptr) {
        const auto& goPoint = m_renderer->boardPoint(event->pos());
        m_listener->fieldClicked(goPoint);
    }
}


