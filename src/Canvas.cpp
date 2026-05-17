#include "Canvas.h"

#include <algorithm>

Canvas::Canvas(int width, int height, char backgroundSymbol)
    : width(width),
      height(height),
      backgroundSymbol(backgroundSymbol),
      pixels(height, std::string(width, backgroundSymbol)) {
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
    if (x >= 0 && x < width && y >= 0 && y < height) {
        pixels[y][x] = symbol;
    }
}

char Canvas::getPixel(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return '\0';
    }

    return pixels[y][x];
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

void Canvas::setRows(const std::vector<std::string>& rows) {
    if (rows.empty()) {
        return;
    }

    const std::size_t rowWidth = rows.front().size();
    if (rowWidth == 0) {
        return;
    }

    for (const std::string& row : rows) {
        if (row.size() != rowWidth) {
            return;
        }
    }

    width = static_cast<int>(rowWidth);
    height = static_cast<int>(rows.size());
    pixels = rows;
}
