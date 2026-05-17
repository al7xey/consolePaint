#ifndef PAINT_APPLICATION_H
#define PAINT_APPLICATION_H

#include "CommandFactory.h"
#include "CommandParser.h"
#include "ConsoleUI.h"
#include "PaintContext.h"

class PaintApplication {
private:
    PaintContext context;
    CommandParser parser;
    CommandFactory factory;
    ConsoleUI ui;

public:
    PaintApplication();

    void run();
};

#endif
