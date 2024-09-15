#ifndef KGOAPPLICATION_HPP
#define KGOAPPLICATION_HPP

#include "sources/gui/Board.hpp"

class GuiService;

class KGoApplication : private Board::Listener {
public:
    KGoApplication();
    
    void start();

private:
    void addListener();
    
    void fieldClicked(const GoPoint& point) override;

private:
    GuiService* const m_guiService = nullptr;
};

#endif  // KGOAPPLICATION_HPP
