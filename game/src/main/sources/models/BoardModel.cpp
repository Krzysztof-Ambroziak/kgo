#include "BoardModel.hpp"
#include "sources/go/Size.hpp"

BoardModel::BoardModel() : m_size{Size::B_19},
                           m_coordinateLabelsVisible(true) {}

Size BoardModel::size() const {
    return m_size;
}

void BoardModel::setSize(Size size) {
    m_size = size;
}

bool BoardModel::isCoordinateLabelsVisible() const {
    return m_coordinateLabelsVisible;
}

void BoardModel::setCoordinateLabelsVisible(bool visible) {
    m_coordinateLabelsVisible = visible;
}
