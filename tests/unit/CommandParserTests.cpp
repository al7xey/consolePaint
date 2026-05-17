#include <gtest/gtest.h>

#include "CommandParser.h"

TEST(CommandParserTests, ParsesCanvasCommand) {
    CommandParser parser;

    ParsedCommand command = parser.parse("CANVAS 40 20");

    EXPECT_EQ(command.name, "CANVAS");
    ASSERT_EQ(command.args.size(), 2);
    EXPECT_EQ(command.args[0], "40");
    EXPECT_EQ(command.args[1], "20");
}

TEST(CommandParserTests, HandlesExtraSpaces) {
    CommandParser parser;

    ParsedCommand command = parser.parse("  POINT   5   7   #  ");

    EXPECT_EQ(command.name, "POINT");
    ASSERT_EQ(command.args.size(), 3);
    EXPECT_EQ(command.args[2], "#");
}

TEST(CommandParserTests, UppercasesCommandName) {
    CommandParser parser;

    ParsedCommand command = parser.parse("line 0 0 3 3 *");

    EXPECT_EQ(command.name, "LINE");
}

TEST(CommandParserTests, EmptyCommandIsInvalid) {
    CommandParser parser;

    ParsedCommand command = parser.parse("   ");

    EXPECT_TRUE(command.name.empty());
    EXPECT_TRUE(command.args.empty());
}
