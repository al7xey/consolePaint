#ifndef FILL_COMMAND_H
#define FILL_COMMAND_H

#include "ICommand.h"

class FillCommand : public ICommand {
private:
    int x;
    int y;
    char symbol;

public:
    FillCommand(int x, int y, char symbol);

    void execute(PaintContext& context) override;
};

#endif
