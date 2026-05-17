#include "CommandFactory.h"
#include "PaintContext.h"

int main() {
    CommandFactory factory;
    PaintContext context;

    factory.create({"CANVAS", {"5", "5"}})->execute(context);
    factory.create({"POINT", {"100", "100", "#"}})->execute(context);
    if (context.getLastMessage() != "Coordinates out of bounds") {
        return 1;
    }

    factory.create({"LINE", {"0", "0"}})->execute(context);
    if (context.getLastMessage() != "Usage: LINE x1 y1 x2 y2 [symbol]") {
        return 2;
    }

    factory.create({"UNKNOWN", {}})->execute(context);
    if (context.getLastMessage() != "Unknown command") {
        return 3;
    }

    factory.create({"CANVAS", {"-1", "2"}})->execute(context);
    if (context.getLastMessage() != "Canvas size must be positive numbers") {
        return 4;
    }

    return 0;
}
