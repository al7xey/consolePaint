#include "drawing/ShapeDrawer.h"

#include "Canvas.h"

void ShapeDrawer::drawPoint(Canvas& canvas, int x, int y, char symbol) const {
    canvas.setPixel(x, y, symbol);
}

void ShapeDrawer::drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const {
    lineStrategy.drawLine(canvas, x1, y1, x2, y2, symbol);
}

void ShapeDrawer::drawRectangle(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const {
    drawLine(canvas, x1, y1, x2, y1, symbol);
    drawLine(canvas, x2, y1, x2, y2, symbol);
    drawLine(canvas, x2, y2, x1, y2, symbol);
    drawLine(canvas, x1, y2, x1, y1, symbol);
}
