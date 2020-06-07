#include "Rectangle.h"
int Rectangle::getHeight() const {
    return scales[2];
}
int Rectangle::getLength() const {
    return scales[1];
}
int Rectangle::getWidth() const {
    return scales[0];
}

Rectangle::Rectangle(int w, int l, int h) {
    if ((w <= 0) || (l <= 0) || (h <= 0)) {
        throw std::out_of_range("Negative scale");
    }
    scales = {w, l, h};
    std::sort(scales.begin(), scales.end());
}
bool Rectangle::Rotate() {
    return std::next_permutation(scales.begin(), scales.end());
}
bool Rectangle::Rotate_back() {
    return std::prev_permutation(scales.begin(), scales.end());
}
