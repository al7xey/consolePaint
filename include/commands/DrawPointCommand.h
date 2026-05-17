#ifndef DRAW_POINT_COMMAND_H
#define DRAW_POINT_COMMAND_H

#include "ICommand.h"

class DrawPointCommand : public ICommand {
private:
    int x;
    int y;
    char symbol;

public:
    DrawPointCommand(int x, int y, char symbol);

    void execute(PaintContext& context) override;
};

#endif
