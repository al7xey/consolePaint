#include <gtest/gtest.h>

#include "Canvas.h"
#include "drawing/QueueFillStrategy.h"
#include "drawing/ShapeDrawer.h"

TEST(FillStrategyTests, FillDoesNotCrossRectangleBorder) {
    Canvas canvas(7, 5, '.');
    ShapeDrawer drawer;
    QueueFillStrategy fill;

    drawer.drawRectangle(canvas, 1, 1, 5, 3, '#');
    fill.fill(canvas, 2, 2, '@');

    EXPECT_EQ(canvas.getPixel(1, 1), '#');
    EXPECT_EQ(canvas.getPixel(2, 2), '@');
    EXPECT_EQ(canvas.getPixel(0, 0), '.');
}

TEST(FillStrategyTests, FillIgnoresOutOfBoundsStart) {
    Canvas canvas(3, 3, '.');
    QueueFillStrategy fill;

    fill.fill(canvas, -1, 0, '@');

    EXPECT_EQ(canvas.getPixel(0, 0), '.');
}
