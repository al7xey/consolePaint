#include <catch2/catch_test_macros.hpp>

#include "Canvas.h"
#include "drawing/QueueFillStrategy.h"
#include "drawing/ShapeDrawer.h"

TEST_CASE("Fill strategy does not cross rectangle border", "[fill]") {
    Canvas canvas(7, 5, '.');
    ShapeDrawer drawer;
    QueueFillStrategy fill;

    drawer.drawRectangle(canvas, 1, 1, 5, 3, '#');
    fill.fill(canvas, 2, 2, '@');

    REQUIRE(canvas.getPixel(1, 1) == '#');
    REQUIRE(canvas.getPixel(2, 2) == '@');
    REQUIRE(canvas.getPixel(0, 0) == '.');
}

TEST_CASE("Fill strategy ignores out-of-bounds start", "[fill]") {
    Canvas canvas(3, 3, '.');
    QueueFillStrategy fill;

    fill.fill(canvas, -1, 0, '@');

    REQUIRE(canvas.getPixel(0, 0) == '.');
}
