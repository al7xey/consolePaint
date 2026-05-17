#include "commands/DrawPointCommand.h"

#include "PaintContext.h"

DrawPointCommand::DrawPointCommand(int x, int y, char symbol)
    : x(x), y(y), symbol(symbol) {
}

void DrawPointCommand::execute(PaintContext& context) {
    context.drawPoint(x, y, symbol == '\0' ? context.getBrushSymbol() : symbol);
}
