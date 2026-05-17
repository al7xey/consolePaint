#include "drawing/BresenhamLineStrategy.h"

#include "Canvas.h"

#include <cstdlib>

void BresenhamLineStrategy::drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const {
    const int dx = std::abs(x2 - x1);
    const int sx = x1 < x2 ? 1 : -1;
    const int dy = -std::abs(y2 - y1);
    const int sy = y1 < y2 ? 1 : -1;
    int error = dx + dy;

    while (true) {
        canvas.setPixel(x1, y1, symbol);
        if (x1 == x2 && y1 == y2) {
            break;
        }

        const int nextError = 2 * error;
        if (nextError >= dy) {
            error += dy;
            x1 += sx;
        }
        if (nextError <= dx) {
            error += dx;
            y1 += sy;
        }
    }
}
