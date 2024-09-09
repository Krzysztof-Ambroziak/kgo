#ifndef IBOARDMODEL_HPP
#define IBOARDMODEL_HPP

enum struct Size;

class IBoardModel {
public:
    virtual Size size() const = 0;
    
    virtual bool isCoordinateLabelsVisible() const = 0;
};

#endif  // IBOARDMODEL_HPP
