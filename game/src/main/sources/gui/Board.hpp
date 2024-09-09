#ifndef BOARD_HPP
#define BOARD_HPP

#include <QWidget>

class IRenderer;

class Board : public QWidget {
    Q_OBJECT

public:
    explicit Board(QWidget* parent = nullptr);
    
    void setRenderer(IRenderer* renderer);

protected:
    void paintEvent(QPaintEvent* event) override;
    
    void resizeEvent(QResizeEvent* event) override;
    
    void mousePressEvent(QMouseEvent* event) override;

signals:
    void sizeChanged(int dim);

private:
    IRenderer* m_renderer = nullptr;
};

#endif  // BOARD_HPP
