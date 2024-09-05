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
    const int halfCellSize = cellSize / 2;
    
    QImage img({dim, dim}, QImage::Format::Format_ARGB32);
    QPainter painter(&img);
    
    // from Center point
    // drawing inner cross lines
    const int centerLine = dim / 2;
    painter.setPen(QPen(Qt::black));
    for(int y = 0; y < boardSize / 2 ; y++) {
        const int yTop    = centerLine - y*cellSize;
        const int yBottom = centerLine + y*cellSize;
        const int yTopBegin    = yTop - halfCellSize;
        const int yTopEnd      = yTop + halfCellSize;
        const int yBottomBegin = yBottom - halfCellSize;
        const int yBottomEnd   = yBottom + halfCellSize;
        
        for(int x = 0; x < boardSize / 2; x++) {
            const int xLeft  = centerLine - x*cellSize;
            const int xRight = centerLine + x*cellSize;
            const int xLeftBegin  = xLeft - halfCellSize;
            const int xLeftEnd    = xLeft + halfCellSize;
            const int xRightBegin = xRight - halfCellSize;
            const int xRightEnd   = xRight + halfCellSize;
            
            // cross lines inner top-left quadrant
            painter.drawLine(xLeftBegin, yTop, xLeftEnd, yTop);
            painter.drawLine(xLeft, yTopBegin, xLeft, yTopEnd);
            
            // cross lines inner top-right quadrant
            painter.drawLine(xRightBegin, yTop, xRightEnd, yTop);
            painter.drawLine(xRight, yTopBegin, xRight, yTopEnd);
            
            // cross lines inner bottom-right quadrant
            painter.drawLine(xRightBegin, yBottom, xRightEnd, yBottom);
            painter.drawLine(xRight, yBottomBegin, xRight, yBottomEnd);
            
            // cross lines inner bottom-left quadrant
            painter.drawLine(xLeftBegin, yBottom, xLeftEnd, yBottom);
            painter.drawLine(xLeft, yBottomBegin, xLeft, yBottomEnd);
        }
    }
    
    const int higher = centerLine + (boardSize / 2) * cellSize;
    const int lower  = centerLine - (boardSize / 2) * cellSize;
    for (int i = 0; i < boardSize / 2; i++) {
        const int lowerStep   = centerLine - i*cellSize;
        const int higherStep  = centerLine + i*cellSize;
        const int lowerBegin  = lowerStep  - halfCellSize;
        const int lowerEnd    = lowerStep  + halfCellSize;
        const int higherBegin = higherStep - halfCellSize;
        const int higherEnd    = higherStep + halfCellSize;
        
        // cross lines in top side
        painter.drawLine(lowerBegin, lower,   lowerEnd, lower);
        painter.drawLine(lowerBegin, lower-1, lowerEnd, lower-1);
        painter.drawLine(lowerStep, lower, lowerStep, lower+halfCellSize);
        
        painter.drawLine(higherBegin, lower,   higherEnd, lower);
        painter.drawLine(higherBegin, lower-1, higherEnd, lower-1);
        painter.drawLine(higherStep, lower, higherStep, lower+halfCellSize);
        
        // cross lines in right side
        painter.drawLine(higher, lowerBegin, higher, lowerEnd);
        painter.drawLine(higher+1, lowerBegin, higher+1, lowerEnd);
        painter.drawLine(higher, lowerStep, higher-halfCellSize, lowerStep);
        
        painter.drawLine(higher, higherBegin, higher, higherEnd);
        painter.drawLine(higher+1, higherBegin, higher+1, higherEnd);
        painter.drawLine(higher, higherStep, higher-halfCellSize, higherStep);
        
        // cross lines in bottom side
        painter.drawLine(lowerBegin, higher,   lowerEnd, higher);
        painter.drawLine(lowerBegin, higher+1, lowerEnd, higher+1);
        painter.drawLine(lowerStep, higher, lowerStep, higher-halfCellSize);
        
        painter.drawLine(higherBegin, higher,   higherEnd, higher);
        painter.drawLine(higherBegin, higher+1, higherEnd, higher+1);
        painter.drawLine(higherStep, higher, higherStep, higher-halfCellSize);
        
        // cross lines in left side
        painter.drawLine(lower, lowerBegin, lower, lowerEnd);
        painter.drawLine(lower-1, lowerBegin, lower-1, lowerEnd);
        painter.drawLine(lower, lowerStep, lower+halfCellSize, lowerStep);
        
        painter.drawLine(lower, higherBegin, lower, higherEnd);
        painter.drawLine(lower-1, higherBegin, lower-1, higherEnd);
        painter.drawLine(lower, higherStep, lower+halfCellSize, higherStep);
    }
    
    const QPoint pointsTL[3]  = { {lower, lower+halfCellSize}, {lower, lower}, {lower+halfCellSize, lower} };
    const QPoint pointsTL1[3] = { {lower-1, lower+halfCellSize}, {lower-1, lower-1}, {lower+halfCellSize, lower-1} };
    painter.drawPolyline(pointsTL, 3);
    painter.drawPolyline(pointsTL1, 3);
    const QPoint pointsTR[3]  = { {higher-halfCellSize, lower}, {higher, lower}, {higher, lower+halfCellSize} };
    const QPoint pointsTR1[3] = { {higher-halfCellSize, lower-1}, {higher+1, lower-1}, {higher+1, lower+halfCellSize} };
    painter.drawPolyline(pointsTR, 3);
    painter.drawPolyline(pointsTR1, 3);
    const QPoint pointsBR[3]  = { {higher, higher-halfCellSize}, {higher, higher}, {higher-halfCellSize, higher} };
    const QPoint pointsBR1[3] = { {higher+1, higher-halfCellSize}, {higher+1, higher+1}, {higher-halfCellSize, higher+1} };
    painter.drawPolyline(pointsBR, 3);
    painter.drawPolyline(pointsBR1, 3);
    const QPoint pointsBL[3]  = { {lower+halfCellSize, higher}, {lower, higher}, {lower, higher-halfCellSize} };
    const QPoint pointsBL1[3] = { {lower+halfCellSize, higher+1}, {lower-1, higher+1}, {lower-1, higher-halfCellSize} };
    painter.drawPolyline(pointsBL, 3);
    painter.drawPolyline(pointsBL1, 3);
    
    m_boardModel->setGrid(QPixmap::fromImage(img).copy());
}
