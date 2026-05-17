#include "CommandParser.h"

#include <algorithm>
#include <cctype>
#include <sstream>

ParsedCommand CommandParser::parse(const std::string& line) const {
    std::stringstream stream(line);
    ParsedCommand command;

    stream >> command.name;
    std::transform(command.name.begin(), command.name.end(), command.name.begin(), [](unsigned char c) {
        return static_cast<char>(std::toupper(c));
    });

    std::string arg;
    while (stream >> arg) {
        command.args.push_back(arg);
    }

    return command;
}
