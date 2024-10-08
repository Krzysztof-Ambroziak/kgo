#ifndef GUISERVICE_HPP
#define GUISERVICE_HPP

#include "sources/gui/MainWindow.hpp"

class Board;
class BoardModel;
class BoardRenderer;

class GuiService : public QObject {
public:
    GuiService();
    
    Board* getBoard() const;
    
    void init();

private:
    void repaintGrid(int dim);
    void repaintStarPoints(int dim);

private slots:
    void setBoardSize(int dim);

private:
    Board* const m_board = nullptr;
    MainWindow m_mainWindow;
    
    BoardModel* const m_boardModel = nullptr;
    
    BoardRenderer* const m_boardRenderer = nullptr;
};

#endif  // GUISERVICE_HPP
