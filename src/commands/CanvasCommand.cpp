#include "commands/CanvasCommand.h"

#include "PaintContext.h"

CanvasCommand::CanvasCommand(int width, int height)
    : width(width), height(height) {
}

void CanvasCommand::execute(PaintContext& context) {
    context.createCanvas(width, height);
}
