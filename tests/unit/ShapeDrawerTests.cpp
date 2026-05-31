#include <catch2/catch_test_macros.hpp>

#include "Canvas.h"
#include "drawing/ShapeDrawer.h"

TEST_CASE("ShapeDrawer draws a point", "[drawing]") {
    Canvas canvas(5, 5, '.');
    ShapeDrawer drawer;

    drawer.drawPoint(canvas, 2, 3, '#');

    REQUIRE(canvas.getPixel(2, 3) == '#');
}

TEST_CASE("ShapeDrawer draws a horizontal line", "[drawing]") {
    Canvas canvas(5, 3, '.');
    ShapeDrawer drawer;

    drawer.drawLine(canvas, 1, 1, 3, 1, '*');

    REQUIRE(canvas.getPixel(1, 1) == '*');
    REQUIRE(canvas.getPixel(2, 1) == '*');
    REQUIRE(canvas.getPixel(3, 1) == '*');
}

TEST_CASE("ShapeDrawer draws rectangle corners", "[drawing]") {
    Canvas canvas(6, 5, '.');
    ShapeDrawer drawer;

    drawer.drawRectangle(canvas, 1, 1, 4, 3, '+');

    REQUIRE(canvas.getPixel(1, 1) == '+');
    REQUIRE(canvas.getPixel(4, 1) == '+');
    REQUIRE(canvas.getPixel(1, 3) == '+');
    REQUIRE(canvas.getPixel(4, 3) == '+');
    REQUIRE(canvas.getPixel(2, 2) == '.');
}
