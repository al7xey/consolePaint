#ifndef QUEUE_FILL_STRATEGY_H
#define QUEUE_FILL_STRATEGY_H

class Canvas;

class QueueFillStrategy {
public:
    void fill(Canvas& canvas, int startX, int startY, char symbol) const;
};

#endif
