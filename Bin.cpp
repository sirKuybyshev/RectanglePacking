#include "Bin.h"


Bin::Bin(int w, int l, int h) : Rectangle(w, l, h) {
    w = this->getWidth();
    l = this->getLength();
    h = this->getHeight();
    std::vector<std::vector<std::vector<CubeType>>> temp(w);
    for (int i = 0; i < w; i++) {
        temp[i].resize(l);
        for (int j = 0; j < l; j++) {
            temp[i][j].resize(h, CubeType::FREE);
        }
    }
    elementaryCubes = temp;
}

Coordinates Bin::Add(const Rectangle &rectangle, const Coordinates &coordinates) {
    auto fit = findFit(rectangle, coordinates);
    if (fit.first() == -1) {
        return fit;
    }
    emplace(rectangle, fit);
    return fit;
}

void Bin::emplace(const Rectangle &rectangle, const Coordinates &coordinates) {
    int x = coordinates.first(), y = coordinates.second(), z = coordinates.third();
    while (x < coordinates.first() + rectangle.getWidth()) {
        while (y < coordinates.second() + rectangle.getLength()) {
            while (z < coordinates.third() + rectangle.getHeight()) {
                elementaryCubes[x][y][z] = CubeType::OCCUPIED;
                z++;
            }
            z = coordinates.third();
            y++;
        }
        y = coordinates.second();
        x++;
    }
}

Coordinates Bin::findFit(const Rectangle &rectangle, const Coordinates &lastCube) {
    Coordinates coord = lastCube.next(scales[0], scales[1], scales[2]);
    while (coord.first() != -1) {
        int x = coord.first(), y = coord.second(), z = coord.third();
        if (elementaryCubes[x][y][z] == CubeType::FREE && isFitting(rectangle, {x, y, z})) {
            break;
        }
        coord = coord.next(scales[0], scales[1], scales[2]);
    }
    return coord;
}

bool Bin::isFitting(const Rectangle &rectangle, const Coordinates &coordinates) {
    int x = coordinates.first(), y = coordinates.second(), z = coordinates.third();
    if ((coordinates.first() + rectangle.getWidth() > scales[0]) ||
        ((coordinates.second() + rectangle.getLength()) > scales[1]) ||
        ((coordinates.third() + rectangle.getHeight()) > scales[2])) {
        return false;
    }
    while (x < coordinates.first() + rectangle.getWidth()) {
        while (y < coordinates.second() + rectangle.getLength()) {
            while (z < coordinates.third() + rectangle.getHeight()) {
                if (elementaryCubes[x][y][z] == CubeType::OCCUPIED) {
                    return false;
                }
                z++;
            }
            z = coordinates.third();
            y++;
        }
        y = coordinates.second();
        x++;
    }
    return true;
}
