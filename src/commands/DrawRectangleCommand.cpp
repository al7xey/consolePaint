#include "commands/DrawRectangleCommand.h"

#include "PaintContext.h"

DrawRectangleCommand::DrawRectangleCommand(int x1, int y1, int x2, int y2, char symbol)
    : x1(x1), y1(y1), x2(x2), y2(y2), symbol(symbol) {
}

void DrawRectangleCommand::execute(PaintContext& context) {
    context.drawRectangle(x1, y1, x2, y2, symbol == '\0' ? context.getBrushSymbol() : symbol);
}
