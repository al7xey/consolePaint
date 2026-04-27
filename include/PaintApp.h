#ifndef PAINT_APP_H
#define PAINT_APP_H

#include "Canvas.h"

class PaintApp {
private:
    Canvas canvas;

public:
    PaintApp();

    void run();
};

#endif
