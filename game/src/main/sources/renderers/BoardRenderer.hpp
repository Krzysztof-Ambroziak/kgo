#ifndef BOARDRENDERER_HPP
#define BOARDRENDERER_HPP

#include "IRenderer.hpp"

#include <QPixmap>

class IBoardModel;

class BoardRenderer : public IRenderer {
public:
    explicit BoardRenderer(const IBoardModel* boardModel);
    
    void render(QPainter& painter) override;
    
    void drawBackground(QPainter& painter);
    void drawGrid(QPainter& painter);
    
    const GoPoint& boardPoint(const QPoint& point) const override;

private:
    QPoint center(int x, int y) const;
    
    QPoint location(int x, int y) const;

private:
    static constexpr float NORMAL_MARGIN = 0.4F;
    static constexpr float ENLARGED_MARGIN = 0.8F;

private:
    int m_fieldSize;
    int m_fieldOffset;
    
    const QPixmap m_background;
    const IBoardModel* const m_boardModel = nullptr;
    
    int centerLine;
};

#endif  // BOARDRENDERER_HPP
