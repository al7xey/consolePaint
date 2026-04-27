#include "Canvas.h"

#include <algorithm>
#include <iostream>

Canvas::Canvas(int width, int height)
    : width(width), height(height), pixels(height, std::string(width, ' ')) {
}

void Canvas::clear() {
    for (std::string& row : pixels) {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void Canvas::setPixel(int x, int y, char symbol) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[y][x] = symbol;
    }
}

void Canvas::print() const {
    for (const std::string& row : pixels) {
        std::cout << row << '\n';
    }
}
