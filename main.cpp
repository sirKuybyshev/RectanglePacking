#include <iostream>

#include "Bin.h"
using namespace std;

template<typename vectorIt>
bool place(vectorIt begin, vectorIt end, Bin &storage, const Coordinates& lastBadCube = {0, 0, -1}) {
    if (begin == end) {
        return true;
    }
    Bin unperformedStorage = storage;
    auto coord = storage.add(*begin, lastBadCube);
    if (coord.first() == -1) {
        return false;
    } else {
        begin++;
        bool success = place(begin, end, storage);
        while (!success) {
            bool check = ((*begin).Rotate());
            if (!check) {
                begin--;
            }
            coord = unperformedStorage.add(*begin, coord);
            if (coord.first() == -1) {
                return false;
            }
            success = place(begin, end, unperformedStorage, coord);
        }
        return success;
    }
}

int main() {
    int height, width, length, totalWidth = 0, totalHeight = 0, totalLength = 0, totalVolume = 0;
    cin >> width >> length >> height;
    Bin storage(width, length, height);
    vector<Rectangle> rectangles;
    while (true) {
        cin >> width >> length >> height;
        if (width == -1) {
            break;
        }
        rectangles.emplace_back(width, length, height);
        totalWidth += width;
        totalHeight += height;
        totalLength += length;
        totalVolume += width * length * height;
    }
    if (totalVolume > (storage.getWidth() * storage.getLength() * storage.getHeight())) {
        cout << false;
        return 0;
    }
    if ((totalHeight < storage.getHeight()) && (totalLength < storage.getLength()) && (totalWidth < storage.getWidth())) {
        cout << true;
        return 0;
    }
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle &lhs, const Rectangle &rhs) {
        return max(lhs.getHeight(), max(lhs.getLength(), lhs.getWidth())) >
               max(rhs.getHeight(), max(rhs.getLength(), rhs.getWidth()));
    });
    cout << place(rectangles.begin(), rectangles.end(), storage) << endl;
    cout << totalVolume << ' ' << (storage.getWidth() * storage.getLength() * storage.getHeight());
    return 0;
}
