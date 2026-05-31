#ifndef PAINT_APPLICATION_H
#define PAINT_APPLICATION_H

#include "CommandFactory.h"
#include "CommandParser.h"
#include "ConsoleUI.h"
#include "PaintContext.h"

#include <iosfwd>

class PaintApplication {
private:
    PaintContext context;
    CommandParser parser;
    CommandFactory factory;
    ConsoleUI ui;

public:
    PaintApplication();
    PaintApplication(std::istream& input, std::ostream& output);

    void run();
};

#endif
