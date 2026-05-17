#ifndef DRAW_RECTANGLE_COMMAND_H
#define DRAW_RECTANGLE_COMMAND_H

#include "ICommand.h"

class DrawRectangleCommand : public ICommand {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    char symbol;

public:
    DrawRectangleCommand(int x1, int y1, int x2, int y2, char symbol);

    void execute(PaintContext& context) override;
};

#endif
