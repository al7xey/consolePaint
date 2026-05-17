#include "commands/ExitCommand.h"

#include "PaintContext.h"

void ExitCommand::execute(PaintContext& context) {
    context.stop();
}
