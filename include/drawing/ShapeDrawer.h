#ifndef SHAPE_DRAWER_H
#define SHAPE_DRAWER_H

#include "drawing/BresenhamLineStrategy.h"

class Canvas;

class ShapeDrawer {
private:
    BresenhamLineStrategy lineStrategy;

public:
    void drawPoint(Canvas& canvas, int x, int y, char symbol) const;
    void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const;
    void drawRectangle(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const;
};

#endif
