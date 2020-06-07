#ifndef RECTANGLEPACKING_RECTANGLE_H
#define RECTANGLEPACKING_RECTANGLE_H
#include <stdexcept>
#include <algorithm>
#include <vector>

class Rectangle {
protected:
    std::vector<int> scales;
public:
    Rectangle() = default;
    Rectangle(int w, int l, int h);
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getLength() const;
    bool Rotate();
    bool Rotate_back();
};


#endif//RECTANGLEPACKING_RECTANGLE_H
