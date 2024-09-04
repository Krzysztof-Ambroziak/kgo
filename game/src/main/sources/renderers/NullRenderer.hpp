#ifndef NULLRENDERER_HPP
#define NULLRENDERER_HPP

#include "IRenderer.hpp"

class NullRenderer : public IRenderer {
public:
    static NullRenderer& instance();

public:
    NullRenderer(const NullRenderer& renderer) = delete;
    
    void render(QPainter& painter) override;

private:
    NullRenderer() = default;
};

inline NullRenderer& NullRenderer::instance() {
    static NullRenderer renderer;
    return renderer;
}

inline void NullRenderer::render(QPainter& painter) {
    // Do nothing
}

#endif  // NULLRENDERER_HPP
