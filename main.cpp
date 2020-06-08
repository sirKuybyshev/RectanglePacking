#include <iostream>

#include "Bin.h"
using namespace std;

template<typename vectorIt>
bool place(vectorIt begin, vectorIt end, Bin &storage, Coordinates lastBadCube = {0, 0, -1}) {
    if (begin == end) {
        return true;
    }
    bool success = false;
    bool hadNotBeenPlaced = true;
    Bin unperformedStorage = storage;
    begin++;
    while (!success) {
        if (!hadNotBeenPlaced) {
            lastBadCube = lastBadCube.next(storage.getWidth(), storage.getLength(), storage.getHeight());
        }
        hadNotBeenPlaced = false;
        begin--;
        storage = unperformedStorage;
        Coordinates coordinates = storage.add((*begin), lastBadCube);
        while (coordinates.first() == -1) {
            if (!begin->Rotate()) {
                return false;
            }
            coordinates = storage.add((*begin), {0, 0, -1});
        }
        begin++;
        success = place(begin, end, storage, coordinates);
    }
    return true;
}

int main() {
    int height, width, length, maxPossibleScale = 0, totalVolume = 0;
    cout << "Input storage scale" << endl;
    cin >> width >> length >> height;
    Bin storage(width, length, height);
    vector<Rectangle> rectangles;
    cout << "Input boxes scales" << endl
         << "Then finish, please, print -1" << endl;
    while (true) {
        cin >> width;
        if (width == -1) {
            break;
        }
        cin >> length >> height;
        rectangles.emplace_back(width, length, height);
        maxPossibleScale += max(width, max(length, height));
        totalVolume += width * length * height;
    }
    if (totalVolume > (storage.getWidth() * storage.getLength() * storage.getHeight())) { //Проверяем, что объем ящиков не больше объема склада
        cout << "Storage is small";
        return 0;
    }
    if (maxPossibleScale <= min(storage.getWidth(), min(storage.getLength(), storage.getHeight()))) { //Проверяем, что ящики хотя бы при какой-то раскладке могут не поместиться
        cout << "Storage is more than good";
        return 0;
    }
    sort(rectangles.begin(), rectangles.end(), [](const Rectangle &lhs, const Rectangle &rhs) {//Сортируем по "неподходящести" для упаковки
        return lhs.getHeight() + lhs.getLength() + lhs.getWidth() >
               rhs.getHeight() + rhs.getLength() + rhs.getWidth();
    });
    if (place(rectangles.begin(), rectangles.end(), storage)) {
        cout << "Storage is OK" << endl;
    } else {
        cout << "Storage is too small" << endl;
    }
    cout << totalVolume << ' ' << (storage.getWidth() * storage.getLength() * storage.getHeight());
    return 0;
}
