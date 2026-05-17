#ifndef HELP_COMMAND_H
#define HELP_COMMAND_H

#include "ICommand.h"

class HelpCommand : public ICommand {
public:
    void execute(PaintContext& context) override;
};

#endif
