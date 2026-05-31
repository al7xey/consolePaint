#include <catch2/catch_test_macros.hpp>

#include "CommandParser.h"

TEST_CASE("CommandParser parses canvas command", "[parser]") {
    CommandParser parser;

    ParsedCommand command = parser.parse("CANVAS 40 20");

    REQUIRE(command.name == "CANVAS");
    REQUIRE(command.args.size() == 2);
    REQUIRE(command.args[0] == "40");
    REQUIRE(command.args[1] == "20");
}

TEST_CASE("CommandParser handles extra spaces", "[parser]") {
    CommandParser parser;

    ParsedCommand command = parser.parse("  POINT   5   7   #  ");

    REQUIRE(command.name == "POINT");
    REQUIRE(command.args.size() == 3);
    REQUIRE(command.args[2] == "#");
}

TEST_CASE("CommandParser uppercases command name", "[parser]") {
    CommandParser parser;

    ParsedCommand command = parser.parse("line 0 0 3 3 *");

    REQUIRE(command.name == "LINE");
}

TEST_CASE("CommandParser treats empty input as invalid", "[parser]") {
    CommandParser parser;

    ParsedCommand command = parser.parse("   ");

    REQUIRE(command.name.empty());
    REQUIRE(command.args.empty());
}
