//
// Created by timofey on 03.06.2020.
//

#include "Rectangle.h"
int Rectangle::getHeight() const {
    return height;
}
int Rectangle::getLength() const {
    return length;
}
int Rectangle::getWidth() const {
    return width;
}
Rectangle::Rectangle(int w, int l, int h) {
    if ((w <= 0) || (l <= 0) || (h <= 0)) {
        throw std::out_of_range("Negative scale");
    }
    height = h;
    width = w;
    length = l;
}
