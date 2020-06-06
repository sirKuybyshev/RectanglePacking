#ifndef RECTANGLEPACKING_BIN_H
#define RECTANGLEPACKING_BIN_H

#include <algorithm>
#include <vector>

#include "Coordinates.h"
#include "Rectangle.h"

enum CubeType {
    FREE,
    OCCUPIED
};

class Bin : public Rectangle {
private:
    std::vector<std::vector<std::vector<CubeType>>> elementaryCubes;
    void emplace(const Rectangle &rectangle, const Coordinates &coordinates);
    bool isFitting(const Rectangle &rectangle, const Coordinates &coordinates);
    Coordinates findFit(const Rectangle& rectangle, const Coordinates& badCube);

public:
    Bin(int w, int l, int h);
    Coordinates add(const Rectangle &rectangle, const Coordinates &coordinates);
};


#endif//RECTANGLEPACKING_BIN_H
