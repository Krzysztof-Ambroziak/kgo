#include "GuiService.hpp"
#include "sources/gui/Board.hpp"
#include "sources/gui/MainWindow.hpp"
#include "sources/models/BoardModel.hpp"
#include "sources/renderers/BoardRenderer.hpp"

#include <QPainter>

GuiService::GuiService() : m_board{new Board},
                           m_mainWindow{m_board},
                           m_boardModel{new BoardModel},
                           m_boardRenderer{new BoardRenderer(m_boardModel)} {
    QObject::connect(m_board, &Board::sizeChanged, this, &GuiService::setBoardSize);
}

void GuiService::init() {
    m_boardModel->setBackground(QPixmap(":/bg/wood1.jpg"));
    m_board->setRenderer(m_boardRenderer);
    
    m_mainWindow.show();
}

void GuiService::setBoardSize(int dim) {
    constexpr int boardSize = 19;  // TODO hardcoded
    
    const int m = dim / boardSize / 3;
    const int cellSize = (dim - 2 * m) / boardSize;
    const int centerLine = dim / 2;
    
    QImage img({dim, dim}, QImage::Format::Format_ARGB32);
    QPainter painter(&img);
    
    // from center point
    const int hig = centerLine + (boardSize / 2) * cellSize;
    const int low  = centerLine - (boardSize / 2) * cellSize;
    painter.drawRect(low, low, (boardSize-1) * cellSize, (boardSize-1) * cellSize);
    painter.drawRect(low-1, low-1, (boardSize-1) * cellSize+2, (boardSize-1) * cellSize+2);
    for (int i = 0; i < boardSize / 2; i++) {
        painter.drawLine(low, centerLine - i*cellSize, hig, centerLine - i*cellSize);
        painter.drawLine(centerLine - i*cellSize, low, centerLine - i*cellSize, hig);
        
        painter.drawLine(low, centerLine + i*cellSize, hig, centerLine + i*cellSize);
        painter.drawLine(centerLine + i*cellSize, low, centerLine + i*cellSize, hig);
    }
    
    m_boardModel->setGrid(QPixmap::fromImage(img).copy());
}
