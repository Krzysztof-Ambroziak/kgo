#ifndef BOARDRENDERER_HPP
#define BOARDRENDERER_HPP

#include "IRenderer.hpp"

class BoardModel;

class BoardRenderer : public IRenderer {
public:
    explicit BoardRenderer(const BoardModel* boardModel);
    
    void render(QPainter& painter) override;

private:
    const BoardModel* const m_boardModel = nullptr;
};

#endif  // BOARDRENDERER_HPP
