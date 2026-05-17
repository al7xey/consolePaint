#ifndef SHOW_COMMAND_H
#define SHOW_COMMAND_H

#include "ICommand.h"

class ShowCommand : public ICommand {
public:
    void execute(PaintContext& context) override;
};

#endif
