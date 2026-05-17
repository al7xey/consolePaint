#include "commands/InvalidCommand.h"

#include "PaintContext.h"

#include <utility>

InvalidCommand::InvalidCommand(std::string message)
    : message(std::move(message)) {
}

void InvalidCommand::execute(PaintContext& context) {
    context.setLastMessage(message);
}
