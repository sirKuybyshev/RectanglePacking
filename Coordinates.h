#ifndef RECTANGLEPACKING_COORDINATES_H
#define RECTANGLEPACKING_COORDINATES_H

#include "Rectangle.h"
#include <vector>

class Coordinates {
private:
    std::vector<int> coord;

public:
    Coordinates();
    Coordinates(int x, int y, int z);
    [[nodiscard]] int first() const;
    [[nodiscard]] int second() const;
    [[nodiscard]] int third() const;
    [[nodiscard]] Coordinates next(int width, int length, int height) const;
};




#endif//RECTANGLEPACKING_COORDINATES_H
