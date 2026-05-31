#include <catch2/catch_test_macros.hpp>

#include "Canvas.h"

TEST_CASE("Canvas sets pixels inside bounds", "[canvas]") {
    Canvas canvas(5, 3, '.');

    canvas.setPixel(2, 1, '#');

    REQUIRE(canvas.getPixel(2, 1) == '#');
}

TEST_CASE("Canvas ignores out-of-bounds pixels", "[canvas]") {
    Canvas canvas(5, 3, '.');

    REQUIRE_NOTHROW(canvas.setPixel(-1, 0, '#'));
    REQUIRE_NOTHROW(canvas.setPixel(5, 3, '#'));

    REQUIRE(canvas.getPixel(0, 0) == '.');
}

TEST_CASE("Canvas clear restores background symbol", "[canvas]") {
    Canvas canvas(4, 2, '.');
    canvas.setPixel(0, 0, '#');
    canvas.setPixel(3, 1, '*');

    canvas.clear();

    REQUIRE(canvas.getPixel(0, 0) == '.');
    REQUIRE(canvas.getPixel(3, 1) == '.');
}

TEST_CASE("Canvas resize rejects invalid size", "[canvas]") {
    Canvas canvas(4, 2, '.');

    canvas.resize(0, 3);

    REQUIRE(canvas.getWidth() == 4);
    REQUIRE(canvas.getHeight() == 2);
}

TEST_CASE("Canvas rejects ragged rows", "[canvas]") {
    Canvas canvas(4, 2, '.');

    const bool changed = canvas.setRows({"abc", "de"});

    REQUIRE_FALSE(changed);
    REQUIRE(canvas.getWidth() == 4);
    REQUIRE(canvas.getHeight() == 2);
}

TEST_CASE("Canvas contains checks bounds", "[canvas]") {
    Canvas canvas(4, 2, '.');

    REQUIRE(canvas.contains(0, 0));
    REQUIRE(canvas.contains(3, 1));
    REQUIRE_FALSE(canvas.contains(-1, 0));
    REQUIRE_FALSE(canvas.contains(4, 1));
}
