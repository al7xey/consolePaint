#include <gtest/gtest.h>

#include "Canvas.h"
#include "drawing/ShapeDrawer.h"

TEST(ShapeDrawerTests, DrawPointSetsCell) {
    Canvas canvas(5, 5, '.');
    ShapeDrawer drawer;

    drawer.drawPoint(canvas, 2, 3, '#');

    EXPECT_EQ(canvas.getPixel(2, 3), '#');
}

TEST(ShapeDrawerTests, DrawHorizontalLineSetsAllCells) {
    Canvas canvas(5, 3, '.');
    ShapeDrawer drawer;

    drawer.drawLine(canvas, 1, 1, 3, 1, '*');

    EXPECT_EQ(canvas.getPixel(1, 1), '*');
    EXPECT_EQ(canvas.getPixel(2, 1), '*');
    EXPECT_EQ(canvas.getPixel(3, 1), '*');
}

TEST(ShapeDrawerTests, DrawRectangleDrawsCorners) {
    Canvas canvas(6, 5, '.');
    ShapeDrawer drawer;

    drawer.drawRectangle(canvas, 1, 1, 4, 3, '+');

    EXPECT_EQ(canvas.getPixel(1, 1), '+');
    EXPECT_EQ(canvas.getPixel(4, 1), '+');
    EXPECT_EQ(canvas.getPixel(1, 3), '+');
    EXPECT_EQ(canvas.getPixel(4, 3), '+');
    EXPECT_EQ(canvas.getPixel(2, 2), '.');
}
