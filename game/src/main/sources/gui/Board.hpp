#ifndef BOARD_HPP
#define BOARD_HPP

#include <QWidget>

class IRenderer;

class Board : public QWidget {
public:
    explicit Board(QWidget* parent = nullptr);
    
    void setRenderer(IRenderer* renderer);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    IRenderer* m_renderer = nullptr;
};

#endif  // BOARD_HPP
