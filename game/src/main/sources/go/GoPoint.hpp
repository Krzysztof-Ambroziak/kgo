#ifndef GOPOINT_HPP
#define GOPOINT_HPP

struct GoPoint {
    static const GoPoint& point(int col, int row);
    
    GoPoint(const GoPoint& obj) = delete;
    
    bool operator==(const GoPoint& obj) const;

private:
    GoPoint(int col, int row) : m_col(col), m_row(row) {}

public:
    static constexpr int s_DEFAULT_SIZE = 19;
    static constexpr int s_MAX_SIZE = 25;
    
    static const GoPoint NULL_POINT;

private:
    static const GoPoint s_POINTS[][s_MAX_SIZE];
    
    const int m_col;
    const int m_row;
};

#endif  // GOPOINT_HPP
