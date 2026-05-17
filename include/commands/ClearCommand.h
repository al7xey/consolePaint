#ifndef CLEAR_COMMAND_H
#define CLEAR_COMMAND_H

#include "ICommand.h"

class ClearCommand : public ICommand {
public:
    void execute(PaintContext& context) override;
};

#endif
