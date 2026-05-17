#include "commands/LoadCommand.h"

#include "PaintContext.h"

#include <utility>

LoadCommand::LoadCommand(std::string filePath)
    : filePath(std::move(filePath)) {
}

void LoadCommand::execute(PaintContext& context) {
    context.load(filePath);
}
