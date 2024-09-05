#ifndef BOARDMODEL_HPP
#define BOARDMODEL_HPP

#include <QPixmap>

class BoardModel {
public:
    const QPixmap& background() const;
    void setBackground(const QPixmap& background);
    
    const QPixmap& grid() const;
    void setGrid(const QPixmap& grid);

private:
    QPixmap m_background;
    QPixmap m_grid;
};

#endif  // BOARDMODEL_HPP
