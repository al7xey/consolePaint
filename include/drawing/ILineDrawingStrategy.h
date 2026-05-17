#ifndef I_LINE_DRAWING_STRATEGY_H
#define I_LINE_DRAWING_STRATEGY_H

class Canvas;

class ILineDrawingStrategy {
public:
    virtual ~ILineDrawingStrategy() = default;

    virtual void drawLine(Canvas& canvas, int x1, int y1, int x2, int y2, char symbol) const = 0;
};

#endif
