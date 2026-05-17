#include <gtest/gtest.h>

#include "Canvas.h"
#include "FileManager.h"

#include <cstdio>

TEST(FileManagerTests, SavesAndLoadsCanvas) {
    const char* fileName = "file_manager_test_art.txt";
    Canvas canvas(4, 2, '.');
    FileManager files;
    canvas.setPixel(0, 0, 'X');
    canvas.setPixel(3, 1, '#');

    ASSERT_TRUE(files.saveCanvas(canvas, fileName));

    Canvas loaded(1, 1, '.');
    ASSERT_TRUE(files.loadCanvas(loaded, fileName));

    EXPECT_EQ(loaded.getWidth(), 4);
    EXPECT_EQ(loaded.getHeight(), 2);
    EXPECT_EQ(loaded.getPixel(0, 0), 'X');
    EXPECT_EQ(loaded.getPixel(3, 1), '#');

    std::remove(fileName);
}

TEST(FileManagerTests, LoadMissingFileFails) {
    Canvas canvas(4, 2, '.');
    FileManager files;

    EXPECT_FALSE(files.loadCanvas(canvas, "missing_console_paint_file.txt"));
}
