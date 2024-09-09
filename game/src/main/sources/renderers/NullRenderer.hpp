#ifndef NULLRENDERER_HPP
#define NULLRENDERER_HPP

#include "IRenderer.hpp"

class NullRenderer : public IRenderer {
public:
    static NullRenderer& instance() {
        static NullRenderer renderer;
        return renderer;
    }

public:
    NullRenderer(const NullRenderer& renderer) = delete;
    
    void render(QPainter& painter) override {
        // Do nothing
    }
    
    const GoPoint& boardPoint(const QPoint& point) const override {
        return GoPoint::NULL_POINT;
    }

private:
    NullRenderer() = default;
};

#endif  // NULLRENDERER_HPP
