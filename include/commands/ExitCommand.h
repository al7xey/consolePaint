#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H

#include "ICommand.h"

class ExitCommand : public ICommand {
public:
    void execute(PaintContext& context) override;
};

#endif
