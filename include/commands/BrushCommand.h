#ifndef BRUSH_COMMAND_H
#define BRUSH_COMMAND_H

#include "ICommand.h"

class BrushCommand : public ICommand {
private:
    char symbol;

public:
    explicit BrushCommand(char symbol);

    void execute(PaintContext& context) override;
};

#endif
