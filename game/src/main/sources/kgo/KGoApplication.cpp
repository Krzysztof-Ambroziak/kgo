#include <QApplication>

#include "sources/gui/Board.hpp"
#include "sources/gui/MainWindow.hpp"


int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    MainWindow window(new Board);
    window.show();
    
    return QApplication::exec();
}
