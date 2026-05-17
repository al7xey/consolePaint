#include "commands/ShowCommand.h"

#include "PaintContext.h"

void ShowCommand::execute(PaintContext& context) {
    context.setLastMessage("Canvas shown");
}
