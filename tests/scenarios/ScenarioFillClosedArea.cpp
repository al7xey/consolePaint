#include "Canvas.h"
#include "drawing/QueueFillStrategy.h"
#include "drawing/ShapeDrawer.h"

int main() {
    Canvas canvas(8, 6, '.');
    ShapeDrawer drawer;
    QueueFillStrategy fill;

    drawer.drawRectangle(canvas, 1, 1, 6, 4, '#');
    fill.fill(canvas, 2, 2, '@');

    if (canvas.getPixel(1, 1) != '#') {
        return 1;
    }
    if (canvas.getPixel(2, 2) != '@') {
        return 2;
    }
    if (canvas.getPixel(0, 0) != '.') {
        return 3;
    }

    return 0;
}
