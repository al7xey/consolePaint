#ifndef CANVAS_COMMAND_H
#define CANVAS_COMMAND_H

#include "ICommand.h"

class CanvasCommand : public ICommand {
private:
    int width;
    int height;

public:
    CanvasCommand(int width, int height);

    void execute(PaintContext& context) override;
};

#endif
