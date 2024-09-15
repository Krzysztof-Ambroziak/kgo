#ifndef BOARD_HPP
#define BOARD_HPP

#include <QWidget>

struct GoPoint;
class IRenderer;

class Board : public QWidget {
    Q_OBJECT

public:
    class Listener {
    public:
        virtual void fieldClicked(const GoPoint& point) = 0;
    };

public:
    explicit Board(QWidget* parent = nullptr);
    
    void setListener(Listener* listener);
    
    void setRenderer(IRenderer* renderer);

protected:
    void paintEvent(QPaintEvent* event) override;
    
    void resizeEvent(QResizeEvent* event) override;
    
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void sizeChanged(int dim);

private:
    Listener* m_listener = nullptr;
    IRenderer* m_renderer = nullptr;
};

#endif  // BOARD_HPP
