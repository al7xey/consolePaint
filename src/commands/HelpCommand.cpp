#include "commands/HelpCommand.h"

#include "PaintContext.h"

void HelpCommand::execute(PaintContext& context) {
    context.setLastMessage(
        "Commands: CANVAS w h, BRUSH c, POINT x y [c], LINE x1 y1 x2 y2 [c], "
        "RECT x1 y1 x2 y2 [c], FILL x y [c], CLEAR, SAVE file, LOAD file, EXIT");
}
