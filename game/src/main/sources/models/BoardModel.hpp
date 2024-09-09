#ifndef BOARDMODEL_HPP
#define BOARDMODEL_HPP

#include "IBoardModel.hpp"

class BoardModel : public IBoardModel {
public:
    BoardModel();
    
    Size size() const override;
    void setSize(Size size);
    
    bool isCoordinateLabelsVisible() const override;
    void setCoordinateLabelsVisible(bool coordinateLabelsVisible);

private:
    Size m_size;
    bool m_coordinateLabelsVisible;
};

#endif  // BOARDMODEL_HPP
