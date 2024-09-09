#include "GuiService.hpp"
#include "sources/gui/Board.hpp"
#include "sources/gui/MainWindow.hpp"
#include "sources/models/BoardModel.hpp"
#include "sources/renderers/BoardRenderer.hpp"

#include <QImage>
#include <QPainter>

GuiService::GuiService() : m_board{new Board},
                           m_mainWindow{m_board},
                           m_boardModel{new BoardModel},
                           m_boardRenderer{new BoardRenderer(m_boardModel)} {
    QObject::connect(m_board, &Board::sizeChanged, this, &GuiService::setBoardSize);
}

void GuiService::init() {
    m_board->setRenderer(m_boardRenderer);
    
    m_mainWindow.show();
}

void GuiService::repaintGrid(int dim) {
    const int size = static_cast<int>(m_boardModel->size());
    
    const int m = dim / static_cast<int>(m_boardModel->size()) / 3;
    const int cellSize = (dim - 2 * m) / size;
    const int centerLine = dim / 2;
    
    QImage img({dim, dim}, QImage::Format::Format_ARGB32);
    QPainter painter(&img);
    
    // from center point
    const int low = centerLine - (size / 2) * cellSize;
    const int hig = centerLine + (size / 2) * cellSize;
    painter.drawRect(low, low, (size-1) * cellSize, (size-1) * cellSize);
    painter.drawRect(low-1, low-1, (size-1) * cellSize+2, (size-1) * cellSize+2);
    for (int i = 0; i < size / 2; i++) {
        painter.drawLine(low, centerLine - i*cellSize, hig, centerLine - i*cellSize);
        painter.drawLine(centerLine - i*cellSize, low, centerLine - i*cellSize, hig);
        
        painter.drawLine(low, centerLine + i*cellSize, hig, centerLine + i*cellSize);
        painter.drawLine(centerLine + i*cellSize, low, centerLine + i*cellSize, hig);
    }
}

void GuiService::repaintStarPoints(int dim) {
}

void GuiService::setBoardSize(int dim) {
    repaintGrid(dim);
    repaintStarPoints(dim);
}
