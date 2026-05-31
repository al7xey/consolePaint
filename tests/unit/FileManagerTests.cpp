#include <catch2/catch_test_macros.hpp>

#include "Canvas.h"
#include "FileManager.h"

#include <cstdio>

TEST_CASE("FileManager saves and loads canvas", "[files]") {
    const char* fileName = "file_manager_test_art.txt";
    Canvas canvas(4, 2, '.');
    FileManager files;
    canvas.setPixel(0, 0, 'X');
    canvas.setPixel(3, 1, '#');

    REQUIRE(files.saveCanvas(canvas, fileName));

    Canvas loaded(1, 1, '.');
    REQUIRE(files.loadCanvas(loaded, fileName));

    REQUIRE(loaded.getWidth() == 4);
    REQUIRE(loaded.getHeight() == 2);
    REQUIRE(loaded.getPixel(0, 0) == 'X');
    REQUIRE(loaded.getPixel(3, 1) == '#');

    std::remove(fileName);
}

TEST_CASE("FileManager fails on missing file", "[files]") {
    Canvas canvas(4, 2, '.');
    FileManager files;

    REQUIRE_FALSE(files.loadCanvas(canvas, "missing_console_paint_file.txt"));
}
