#include "commands/BrushCommand.h"

#include "PaintContext.h"

BrushCommand::BrushCommand(char symbol)
    : symbol(symbol) {
}

void BrushCommand::execute(PaintContext& context) {
    context.setBrushSymbol(symbol);
}
