#include "MainWindow.hpp"

#include <algorithm>

#include <QResizeEvent>

MainWindow::MainWindow(QWidget* const boardPanel, QWidget* const parent) : QMainWindow{parent} {
    setupUI(boardPanel);
}

void MainWindow::setupUI(QWidget* const boardPanel) {
    class CentralWidget : public QWidget {
    public:
        explicit CentralWidget(QWidget* const boardPanel,
                               QWidget* const parent = nullptr) : QWidget{parent},
                                                                  m_boardPanel{boardPanel} {
            QPalette palette(Qt::gray);
            setAutoFillBackground(true);
            setPalette(palette);
            m_boardPanel->setParent(this);
        }
    
    protected:
        void resizeEvent(QResizeEvent* const event) override {
            const int width = event->size().width();
            const int height = event->size().height();
            const int min = std::min(width, height);
            const int max = std::max(width, height);
            const int corner = (max - min) / 2;
            
            if(width > height)
                m_boardPanel->setGeometry(corner, 0, min, min);
            else
                m_boardPanel->setGeometry(0, corner, min, min);
        }
    
    private:
        QWidget* const m_boardPanel = nullptr;
    }* const centralWidget = new CentralWidget(boardPanel, this);
    
    setCentralWidget(centralWidget);
}
