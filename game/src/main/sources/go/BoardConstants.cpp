#include "BoardConstants.hpp"

static const GoPoint* nullStarPoints[]  =   {};
static const GoPoint* starPointsOn5x5[] =   {&GoPoint::point(2, 2)};
static const GoPoint* starPointsOn7x7[] =   {&GoPoint::point(2, 2), &GoPoint::point( 4, 2), &GoPoint::point( 2,  4), &GoPoint::point( 4,  4)};
static const GoPoint* starPointsOn8x8[] =   {&GoPoint::point(2, 2), &GoPoint::point( 5, 2), &GoPoint::point( 2,  5), &GoPoint::point( 5,  5)};
static const GoPoint* starPointsOn9x9[] =   {&GoPoint::point(2, 2), &GoPoint::point( 6, 2), &GoPoint::point( 4,  4), &GoPoint::point( 2,  6), &GoPoint::point( 6,  6)};
static const GoPoint* starPointsOn10x10[] = {&GoPoint::point(2, 2), &GoPoint::point( 7, 2), &GoPoint::point( 2,  7), &GoPoint::point( 7,  7)};
static const GoPoint* starPointsOn11x11[] = {&GoPoint::point(2, 2), &GoPoint::point( 8, 2), &GoPoint::point( 5,  5), &GoPoint::point( 2,  8), &GoPoint::point( 8,  8)};
static const GoPoint* starPointsOn12x12[] = {&GoPoint::point(2, 2), &GoPoint::point( 9, 2), &GoPoint::point( 2,  9), &GoPoint::point( 9,  9)};
static const GoPoint* starPointsOn13x13[] = {&GoPoint::point(3, 3), &GoPoint::point( 9, 3), &GoPoint::point( 6,  6), &GoPoint::point( 3,  9), &GoPoint::point( 9,  9)};
static const GoPoint* starPointsOn14x14[] = {&GoPoint::point(3, 3), &GoPoint::point(10, 3), &GoPoint::point( 3, 10), &GoPoint::point(10, 10)};
static const GoPoint* starPointsOn15x15[] = {&GoPoint::point(3, 3), &GoPoint::point(11, 3), &GoPoint::point( 7,  7), &GoPoint::point( 3,  9), &GoPoint::point( 9,  9)};
static const GoPoint* starPointsOn16x16[] = {&GoPoint::point(3, 3), &GoPoint::point(12, 3), &GoPoint::point( 3, 12), &GoPoint::point(12, 12)};
static const GoPoint* starPointsOn17x17[] = {&GoPoint::point(3, 3), &GoPoint::point(13, 3), &GoPoint::point( 8,  8), &GoPoint::point( 3,  9), &GoPoint::point( 9,  9)};
static const GoPoint* starPointsOn18x18[] = {&GoPoint::point(3, 3), &GoPoint::point(14, 3), &GoPoint::point( 3, 14), &GoPoint::point(14, 14)};
static const GoPoint* starPointsOn19x19[] = {&GoPoint::point(3, 3), &GoPoint::point( 9, 3), &GoPoint::point(15,  3), &GoPoint::point( 3,  9), &GoPoint::point( 9,  9), &GoPoint::point(15,  9), &GoPoint::point(3, 15), &GoPoint::point( 9, 15), &GoPoint::point(15, 15)};
static const GoPoint* starPointsOn20x20[] = {&GoPoint::point(3, 3), &GoPoint::point(16, 3), &GoPoint::point( 3, 16), &GoPoint::point(16, 16)};
static const GoPoint* starPointsOn21x21[] = {&GoPoint::point(3, 3), &GoPoint::point(10, 3), &GoPoint::point(17,  3), &GoPoint::point( 3, 10), &GoPoint::point(10, 10), &GoPoint::point(17, 10), &GoPoint::point(3, 17), &GoPoint::point(10, 17), &GoPoint::point(17, 17)};
static const GoPoint* starPointsOn22x22[] = {&GoPoint::point(3, 3), &GoPoint::point(18, 3), &GoPoint::point( 3, 18), &GoPoint::point(18, 18)};
static const GoPoint* starPointsOn23x23[] = {&GoPoint::point(3, 3), &GoPoint::point(11, 3), &GoPoint::point(19,  3), &GoPoint::point( 3, 11), &GoPoint::point(11, 11), &GoPoint::point(19, 11), &GoPoint::point(3, 19), &GoPoint::point(11, 19), &GoPoint::point(19, 19)};
static const GoPoint* starPointsOn24x24[] = {&GoPoint::point(3, 3), &GoPoint::point(20, 3), &GoPoint::point( 3, 20), &GoPoint::point(20, 20)};
static const GoPoint* starPointsOn25x25[] = {&GoPoint::point(3, 3), &GoPoint::point(12, 3), &GoPoint::point(21,  3), &GoPoint::point( 3, 12), &GoPoint::point(12, 12), &GoPoint::point(21, 12), &GoPoint::point(3, 21), &GoPoint::point(12, 21), &GoPoint::point(21, 21)};

const BoardConstants BoardConstants::s_BOARD_CONSTANTS[] {
    {0, nullStarPoints},     // 0
    {0, nullStarPoints},     // 1
    {0, nullStarPoints},     // 2
    {0, nullStarPoints},     // 3
    {0, nullStarPoints},     // 4
    {1, starPointsOn5x5},    // 5
    {0, nullStarPoints},     // 6
    {4, starPointsOn7x7},    // 7
    {4, starPointsOn8x8},    // 8
    {5, starPointsOn9x9},    // 9
    {4, starPointsOn10x10},  // 10
    {5, starPointsOn11x11},  // 11
    {4, starPointsOn12x12},  // 12
    {5, starPointsOn13x13},  // 13
    {4, starPointsOn14x14},  // 14
    {5, starPointsOn15x15},  // 15
    {4, starPointsOn16x16},  // 16
    {5, starPointsOn17x17},  // 17
    {4, starPointsOn18x18},  // 18
    {9, starPointsOn19x19},  // 19
    {4, starPointsOn20x20},  // 20
    {9, starPointsOn21x21},  // 21
    {4, starPointsOn22x22},  // 22
    {9, starPointsOn23x23},  // 23
    {4, starPointsOn24x24},  // 24
    {9, starPointsOn25x25}   // 25
};

const BoardConstants& BoardConstants::instance(int boardSize) {
    return s_BOARD_CONSTANTS[boardSize];
}

BoardConstants::BoardConstants(int count, const GoPoint** goPoints) : m_count(count),
    m_starPoints{goPoints} {}

int BoardConstants::count() const {
    return m_count;
}

const GoPoint** BoardConstants::points() const {
    return m_starPoints;
}
