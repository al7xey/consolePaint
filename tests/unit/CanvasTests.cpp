#include <gtest/gtest.h>

#include "Canvas.h"

TEST(CanvasTests, SetPixelInsideCanvasChangesCell) {
    Canvas canvas(5, 3, '.');

    canvas.setPixel(2, 1, '#');

    EXPECT_EQ(canvas.getPixel(2, 1), '#');
}

TEST(CanvasTests, SetPixelOutOfBoundsDoesNotCrash) {
    Canvas canvas(5, 3, '.');

    EXPECT_NO_THROW(canvas.setPixel(-1, 0, '#'));
    EXPECT_NO_THROW(canvas.setPixel(5, 3, '#'));

    EXPECT_EQ(canvas.getPixel(0, 0), '.');
}

TEST(CanvasTests, ClearRestoresBackgroundSymbol) {
    Canvas canvas(4, 2, '.');
    canvas.setPixel(0, 0, '#');
    canvas.setPixel(3, 1, '*');

    canvas.clear();

    EXPECT_EQ(canvas.getPixel(0, 0), '.');
    EXPECT_EQ(canvas.getPixel(3, 1), '.');
}

TEST(CanvasTests, ResizeRejectsInvalidSize) {
    Canvas canvas(4, 2, '.');

    canvas.resize(0, 3);

    EXPECT_EQ(canvas.getWidth(), 4);
    EXPECT_EQ(canvas.getHeight(), 2);
}

TEST(CanvasTests, SetRowsRejectsRaggedInput) {
    Canvas canvas(4, 2, '.');

    const bool changed = canvas.setRows({"abc", "de"});

    EXPECT_FALSE(changed);
    EXPECT_EQ(canvas.getWidth(), 4);
    EXPECT_EQ(canvas.getHeight(), 2);
}

TEST(CanvasTests, ContainsChecksBounds) {
    Canvas canvas(4, 2, '.');

    EXPECT_TRUE(canvas.contains(0, 0));
    EXPECT_TRUE(canvas.contains(3, 1));
    EXPECT_FALSE(canvas.contains(-1, 0));
    EXPECT_FALSE(canvas.contains(4, 1));
}
