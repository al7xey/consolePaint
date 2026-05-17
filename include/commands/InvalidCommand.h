#ifndef INVALID_COMMAND_H
#define INVALID_COMMAND_H

#include "ICommand.h"

#include <string>

class InvalidCommand : public ICommand {
private:
    std::string message;

public:
    explicit InvalidCommand(std::string message);

    void execute(PaintContext& context) override;
};

#endif
