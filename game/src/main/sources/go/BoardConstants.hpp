#ifndef BOARDCONSTANTS_HPP
#define BOARDCONSTANTS_HPP

#include "sources/go/GoPoint.hpp"

struct BoardConstants {
public:
    static const BoardConstants& instance(int boardSize);
    
    BoardConstants(const BoardConstants& obj) = delete;

private:
    BoardConstants(int count, const GoPoint** goPoints);

private:
    static const BoardConstants s_BOARD_CONSTANTS[];
    
    const int m_count;
    const GoPoint** m_starPoints;
};

#endif  // BOARDCONSTANTS_HPP
