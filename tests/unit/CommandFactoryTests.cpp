#include <catch2/catch_test_macros.hpp>

#include "CommandFactory.h"
#include "PaintContext.h"

TEST_CASE("CommandFactory creates canvas command", "[factory]") {
    CommandFactory factory;
    PaintContext context;

    factory.create({"CANVAS", {"10", "4"}})->execute(context);

    REQUIRE(context.getCanvas().getWidth() == 10);
    REQUIRE(context.getCanvas().getHeight() == 4);
}

TEST_CASE("CommandFactory rejects bad canvas size", "[factory]") {
    CommandFactory factory;
    PaintContext context;

    factory.create({"CANVAS", {"0", "4"}})->execute(context);

    REQUIRE(context.getLastMessage() == "Canvas size must be positive numbers");
}

TEST_CASE("CommandFactory reports unknown commands", "[factory]") {
    CommandFactory factory;
    PaintContext context;

    factory.create({"NOPE", {}})->execute(context);

    REQUIRE(context.getLastMessage() == "Unknown command");
}

TEST_CASE("CommandFactory reports empty commands", "[factory]") {
    CommandFactory factory;
    PaintContext context;

    factory.create({"", {}})->execute(context);

    REQUIRE(context.getLastMessage() == "Empty command");
}
