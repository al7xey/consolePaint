#include "CommandFactory.h"

#include "PaintContext.h"
#include "commands/BrushCommand.h"
#include "commands/CanvasCommand.h"
#include "commands/ClearCommand.h"
#include "commands/DrawLineCommand.h"
#include "commands/DrawPointCommand.h"
#include "commands/DrawRectangleCommand.h"
#include "commands/ExitCommand.h"
#include "commands/FillCommand.h"
#include "commands/HelpCommand.h"
#include "commands/InvalidCommand.h"
#include "commands/LoadCommand.h"
#include "commands/SaveCommand.h"

#include <cstdlib>
#include <memory>
#include <string>

namespace {
bool parseInt(const std::string& value, int& result) {
    char* end = nullptr;
    const long parsed = std::strtol(value.c_str(), &end, 10);
    if (end == value.c_str() || *end != '\0') {
        return false;
    }

    result = static_cast<int>(parsed);
    return true;
}

bool parseSymbol(const std::vector<std::string>& args, std::size_t index, char defaultSymbol, char& result) {
    if (args.size() <= index) {
        result = defaultSymbol;
        return true;
    }

    if (args[index].empty()) {
        return false;
    }

    result = args[index][0];
    return true;
}

std::unique_ptr<ICommand> invalid(const std::string& message) {
    return std::make_unique<InvalidCommand>(message);
}
}

std::unique_ptr<ICommand> CommandFactory::create(const ParsedCommand& command) const {
    if (command.name.empty()) {
        return invalid("Empty command");
    }

    if (command.name == "HELP") {
        return std::make_unique<HelpCommand>();
    }

    if (command.name == "EXIT") {
        return std::make_unique<ExitCommand>();
    }

    if (command.name == "CLEAR") {
        return std::make_unique<ClearCommand>();
    }

    if (command.name == "CANVAS") {
        if (command.args.size() != 2) {
            return invalid("Usage: CANVAS width height");
        }

        int width = 0;
        int height = 0;
        if (!parseInt(command.args[0], width) || !parseInt(command.args[1], height) || width <= 0 || height <= 0) {
            return invalid("Canvas size must be positive numbers");
        }

        return std::make_unique<CanvasCommand>(width, height);
    }

    if (command.name == "BRUSH") {
        if (command.args.size() != 1 || command.args[0].empty()) {
            return invalid("Usage: BRUSH symbol");
        }

        return std::make_unique<BrushCommand>(command.args[0][0]);
    }

    if (command.name == "POINT") {
        if (command.args.size() < 2 || command.args.size() > 3) {
            return invalid("Usage: POINT x y [symbol]");
        }

        int x = 0;
        int y = 0;
        char symbol = '\0';
        if (!parseInt(command.args[0], x) || !parseInt(command.args[1], y) || !parseSymbol(command.args, 2, symbol, symbol)) {
            return invalid("Invalid POINT arguments");
        }

        return std::make_unique<DrawPointCommand>(x, y, symbol);
    }

    if (command.name == "LINE") {
        if (command.args.size() < 4 || command.args.size() > 5) {
            return invalid("Usage: LINE x1 y1 x2 y2 [symbol]");
        }

        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        char symbol = '\0';
        if (!parseInt(command.args[0], x1) || !parseInt(command.args[1], y1) ||
            !parseInt(command.args[2], x2) || !parseInt(command.args[3], y2) ||
            !parseSymbol(command.args, 4, symbol, symbol)) {
            return invalid("Invalid LINE arguments");
        }

        return std::make_unique<DrawLineCommand>(x1, y1, x2, y2, symbol);
    }

    if (command.name == "RECT") {
        if (command.args.size() < 4 || command.args.size() > 5) {
            return invalid("Usage: RECT x1 y1 x2 y2 [symbol]");
        }

        int x1 = 0;
        int y1 = 0;
        int x2 = 0;
        int y2 = 0;
        char symbol = '\0';
        if (!parseInt(command.args[0], x1) || !parseInt(command.args[1], y1) ||
            !parseInt(command.args[2], x2) || !parseInt(command.args[3], y2) ||
            !parseSymbol(command.args, 4, symbol, symbol)) {
            return invalid("Invalid RECT arguments");
        }

        return std::make_unique<DrawRectangleCommand>(x1, y1, x2, y2, symbol);
    }

    if (command.name == "FILL") {
        if (command.args.size() < 2 || command.args.size() > 3) {
            return invalid("Usage: FILL x y [symbol]");
        }

        int x = 0;
        int y = 0;
        char symbol = '\0';
        if (!parseInt(command.args[0], x) || !parseInt(command.args[1], y) || !parseSymbol(command.args, 2, symbol, symbol)) {
            return invalid("Invalid FILL arguments");
        }

        return std::make_unique<FillCommand>(x, y, symbol);
    }

    if (command.name == "SAVE") {
        if (command.args.size() != 1) {
            return invalid("Usage: SAVE file");
        }

        return std::make_unique<SaveCommand>(command.args[0]);
    }

    if (command.name == "LOAD") {
        if (command.args.size() != 1) {
            return invalid("Usage: LOAD file");
        }

        return std::make_unique<LoadCommand>(command.args[0]);
    }

    return invalid("Unknown command");
}
