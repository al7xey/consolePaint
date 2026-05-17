#include "commands/ClearCommand.h"

#include "PaintContext.h"

void ClearCommand::execute(PaintContext& context) {
    context.clear();
}
