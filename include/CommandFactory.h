#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "CommandParser.h"
#include "ICommand.h"

#include <memory>

class CommandFactory {
public:
    std::unique_ptr<ICommand> create(const ParsedCommand& command) const;
};

#endif
