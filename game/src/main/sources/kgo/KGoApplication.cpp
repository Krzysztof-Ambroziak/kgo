#include <QApplication>

#include "sources/services/GuiService.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    GuiService guiService;
    guiService.init();
    
    return QApplication::exec();
}
