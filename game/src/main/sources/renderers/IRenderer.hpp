#ifndef IRENDERER_HPP
#define IRENDERER_HPP

struct GoPoint;
class QPainter;
class QPoint;

class IRenderer {
public:
    virtual void render(QPainter& painter) = 0;
    
    virtual const GoPoint& boardPoint(const QPoint& point) const = 0;
};

#endif  // IRENDERER_HPP
