#include "commands/FillCommand.h"

#include "PaintContext.h"

FillCommand::FillCommand(int x, int y, char symbol)
    : x(x), y(y), symbol(symbol) {
}

void FillCommand::execute(PaintContext& context) {
    context.fill(x, y, symbol == '\0' ? context.getBrushSymbol() : symbol);
}
