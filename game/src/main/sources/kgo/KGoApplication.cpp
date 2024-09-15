#include <QApplication>

#include "sources/kgo/KGoApplication.hpp"
#include "sources/services/GuiService.hpp"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    KGoApplication application;
    application.start();
    
    return QApplication::exec();
}


KGoApplication::KGoApplication() : m_guiService(new GuiService) {
    addListener();
}

void KGoApplication::start() {
    m_guiService->init();
}

void KGoApplication::addListener() {
    auto* const board = m_guiService->getBoard();
    board->setListener(this);
}

void KGoApplication::fieldClicked(const GoPoint& point) {
}
