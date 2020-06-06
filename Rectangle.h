//
// Created by timofey on 03.06.2020.
//

#ifndef RECTANGLEPACKING_RECTANGLE_H
#define RECTANGLEPACKING_RECTANGLE_H
#include <stdexcept>

class Rectangle {
protected:
    int height, width, length;
public:
    Rectangle() = default;
    Rectangle(int w, int l, int h);
    [[nodiscard]] int getHeight() const;
    [[nodiscard]] int getWidth() const;
    [[nodiscard]] int getLength() const;
};


#endif//RECTANGLEPACKING_RECTANGLE_H
