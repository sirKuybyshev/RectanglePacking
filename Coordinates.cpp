#include "Coordinates.h"
#include "Rectangle.h"

Coordinates::Coordinates(int x, int y, int z) {
    std::vector<int> temp(3, 0);
    temp[0] = x;
    temp[1] = y;
    temp[2] = z;
    coord = temp;
}
Coordinates::Coordinates() {
    std::vector<int> temp(3, 0);
    coord = temp;
}
int Coordinates::first() const {
    return coord[0];
}
int Coordinates::second() const {
    return coord[1];
}
int Coordinates::third() const {
    return coord[2];
}
Coordinates Coordinates::next(int width, int length, int height) const{
    if (coord[2] >= height - 1) {
        if(coord[1] >= length - 1) {
            if (coord[0] >= width - 1) {
                return {-1, -1, -1};
            } else {
                return {coord[0] + 1, 0, 0};
            }
        } else {
            return {coord[0], coord[1] + 1, 0};
        }
    } else {
        return {coord[0], coord[1], coord[2] + 1};
    }
}
