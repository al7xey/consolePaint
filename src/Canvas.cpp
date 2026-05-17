#include "Canvas.h"

#include <algorithm>

Canvas::Canvas(int width, int height, char backgroundSymbol)
    : width(width > 0 ? width : 1),
      height(height > 0 ? height : 1),
      backgroundSymbol(backgroundSymbol),
      pixels(this->height, std::string(this->width, backgroundSymbol)) {
}

void Canvas::resize(int newWidth, int newHeight, char fillSymbol) {
    if (newWidth <= 0 || newHeight <= 0) {
        return;
    }

    width = newWidth;
    height = newHeight;
    backgroundSymbol = fillSymbol;
    pixels.assign(height, std::string(width, backgroundSymbol));
}

void Canvas::clear() {
    for (std::string& row : pixels) {
        std::fill(row.begin(), row.end(), backgroundSymbol);
    }
}

void Canvas::setPixel(int x, int y, char symbol) {
    if (contains(x, y)) {
        pixels[y][x] = symbol;
    }
}

char Canvas::getPixel(int x, int y) const {
    if (!contains(x, y)) {
        return '\0';
    }

    return pixels[y][x];
}

bool Canvas::contains(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int Canvas::getWidth() const {
    return width;
}

int Canvas::getHeight() const {
    return height;
}

const std::vector<std::string>& Canvas::getRows() const {
    return pixels;
}

bool Canvas::setRows(const std::vector<std::string>& rows) {
    if (rows.empty()) {
        return false;
    }

    const std::size_t rowWidth = rows.front().size();
    if (rowWidth == 0) {
        return false;
    }

    for (const std::string& row : rows) {
        if (row.size() != rowWidth) {
            return false;
        }
    }

    width = static_cast<int>(rowWidth);
    height = static_cast<int>(rows.size());
    pixels = rows;
    return true;
}
