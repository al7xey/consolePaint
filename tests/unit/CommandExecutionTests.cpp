#include <gtest/gtest.h>

#include "CommandFactory.h"
#include "PaintContext.h"

TEST(CommandExecutionTests, BrushAffectsDrawingWithoutExplicitSymbol) {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"BRUSH", {"@"}})->execute(context);

    factory.create({"POINT", {"2", "1"}})->execute(context);

    EXPECT_EQ(context.getCanvas().getPixel(2, 1), '@');
}

TEST(CommandExecutionTests, ExplicitSymbolOverridesBrush) {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"BRUSH", {"@"}})->execute(context);

    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    EXPECT_EQ(context.getCanvas().getPixel(2, 1), '*');
}

TEST(CommandExecutionTests, ClearCommandClearsCanvas) {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    factory.create({"CLEAR", {}})->execute(context);

    EXPECT_EQ(context.getCanvas().getPixel(2, 1), ' ');
}

TEST(CommandExecutionTests, ShowCommandKeepsCanvas) {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    factory.create({"SHOW", {}})->execute(context);

    EXPECT_EQ(context.getLastMessage(), "Canvas shown");
    EXPECT_EQ(context.getCanvas().getPixel(2, 1), '*');
}

TEST(CommandExecutionTests, ExitCommandStopsContext) {
    CommandFactory factory;
    PaintContext context;

    factory.create({"EXIT", {}})->execute(context);

    EXPECT_FALSE(context.isRunning());
}

TEST(CommandExecutionTests, OutOfBoundsPointShowsError) {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);

    factory.create({"POINT", {"100", "100", "#"}})->execute(context);

    EXPECT_EQ(context.getLastMessage(), "Coordinates out of bounds");
}
