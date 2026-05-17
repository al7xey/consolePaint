#ifndef BRESENHAM_LINE_STRATEGY_H
#define BRESENHAM_LINE_STRATEGY_H

#include "drawing/ILineDrawingStrategy.h"

class BresenhamLineStrategy : public ILineDrawingStrategy {
public:
    void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const override;
};

#endif
