#include "Canvas.h"
#include "CommandFactory.h"
#include "PaintContext.h"
#include "drawing/ShapeDrawer.h"

int main() {
    Canvas canvas(12, 6, '.');
    ShapeDrawer drawer;

    drawer.drawPoint(canvas, 1, 1, '#');
    drawer.drawLine(canvas, 2, 1, 5, 1, '*');
    drawer.drawRectangle(canvas, 6, 2, 10, 4, '+');

    if (canvas.getPixel(1, 1) != '#') {
        return 1;
    }
    if (canvas.getPixel(4, 1) != '*') {
        return 2;
    }
    if (canvas.getPixel(6, 2) != '+') {
        return 3;
    }
    if (canvas.getPixel(8, 3) != '.') {
        return 4;
    }

    PaintContext context;
    CommandFactory factory;
    factory.create({"SHOW", {}})->execute(context);
    if (context.getLastMessage() != "Canvas shown") {
        return 5;
    }

    return 0;
}
