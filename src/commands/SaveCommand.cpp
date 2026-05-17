#include "commands/SaveCommand.h"

#include "PaintContext.h"

#include <utility>

SaveCommand::SaveCommand(std::string filePath)
    : filePath(std::move(filePath)) {
}

void SaveCommand::execute(PaintContext& context) {
    context.setLastMessage(context.save(filePath) ? "Canvas saved" : "Cannot save file");
}
