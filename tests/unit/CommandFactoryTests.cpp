#include <gtest/gtest.h>

#include "CommandFactory.h"
#include "PaintContext.h"

TEST(CommandFactoryTests, CreatesCanvasCommand) {
    CommandFactory factory;
    PaintContext context;

    factory.create({"CANVAS", {"10", "4"}})->execute(context);

    EXPECT_EQ(context.getCanvas().getWidth(), 10);
    EXPECT_EQ(context.getCanvas().getHeight(), 4);
}

TEST(CommandFactoryTests, RejectsBadCanvasSize) {
    CommandFactory factory;
    PaintContext context;

    factory.create({"CANVAS", {"0", "4"}})->execute(context);

    EXPECT_EQ(context.getLastMessage(), "Canvas size must be positive numbers");
}

TEST(CommandFactoryTests, UnknownCommandProducesMessage) {
    CommandFactory factory;
    PaintContext context;

    factory.create({"NOPE", {}})->execute(context);

    EXPECT_EQ(context.getLastMessage(), "Unknown command");
}

TEST(CommandFactoryTests, EmptyCommandProducesMessage) {
    CommandFactory factory;
    PaintContext context;

    factory.create({"", {}})->execute(context);

    EXPECT_EQ(context.getLastMessage(), "Empty command");
}
