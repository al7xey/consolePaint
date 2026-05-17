#ifndef DRAW_LINE_COMMAND_H
#define DRAW_LINE_COMMAND_H

#include "ICommand.h"

class DrawLineCommand : public ICommand {
private:
    int x1;
    int y1;
    int x2;
    int y2;
    char symbol;

public:
    DrawLineCommand(int x1, int y1, int x2, int y2, char symbol);

    void execute(PaintContext& context) override;
};

#endif
