#include <catch2/catch_test_macros.hpp>

#include "CommandFactory.h"
#include "PaintContext.h"

TEST_CASE("Brush affects drawing without explicit symbol", "[commands]") {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"BRUSH", {"@"}})->execute(context);

    factory.create({"POINT", {"2", "1"}})->execute(context);

    REQUIRE(context.getCanvas().getPixel(2, 1) == '@');
}

TEST_CASE("Explicit symbol overrides brush", "[commands]") {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"BRUSH", {"@"}})->execute(context);

    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    REQUIRE(context.getCanvas().getPixel(2, 1) == '*');
}

TEST_CASE("Clear command clears canvas", "[commands]") {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    factory.create({"CLEAR", {}})->execute(context);

    REQUIRE(context.getCanvas().getPixel(2, 1) == ' ');
}

TEST_CASE("Show command keeps canvas", "[commands]") {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);
    factory.create({"POINT", {"2", "1", "*"}})->execute(context);

    factory.create({"SHOW", {}})->execute(context);

    REQUIRE(context.getLastMessage() == "Canvas shown");
    REQUIRE(context.getCanvas().getPixel(2, 1) == '*');
}

TEST_CASE("Exit command stops context", "[commands]") {
    CommandFactory factory;
    PaintContext context;

    factory.create({"EXIT", {}})->execute(context);

    REQUIRE_FALSE(context.isRunning());
}

TEST_CASE("Out-of-bounds point shows error", "[commands]") {
    CommandFactory factory;
    PaintContext context;
    factory.create({"CANVAS", {"5", "3"}})->execute(context);

    factory.create({"POINT", {"100", "100", "#"}})->execute(context);

    REQUIRE(context.getLastMessage() == "Coordinates out of bounds");
}
