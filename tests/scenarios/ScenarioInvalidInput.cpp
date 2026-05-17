#include "CommandFactory.h"
#include "PaintContext.h"

int main() {
    CommandFactory factory;
    PaintContext context;

    factory.create({"LINE", {"0", "0"}})->execute(context);
    if (context.getLastMessage() != "Usage: LINE x1 y1 x2 y2 [symbol]") {
        return 1;
    }

    factory.create({"UNKNOWN", {}})->execute(context);
    if (context.getLastMessage() != "Unknown command") {
        return 2;
    }

    factory.create({"CANVAS", {"-1", "2"}})->execute(context);
    if (context.getLastMessage() != "Canvas size must be positive numbers") {
        return 3;
    }

    return 0;
}
