#include "ConsoleUI.h"

#include <iostream>

ConsoleUI::ConsoleUI(std::istream& input, std::ostream& output)
    : input(input), output(output) {
}

void ConsoleUI::showWelcome() const {
    output << "Console Paint\n";
    output << "Commands:\n";
    output << "  CANVAS width height\n";
    output << "  BRUSH symbol\n";
    output << "  POINT x y [symbol]\n";
    output << "  LINE x1 y1 x2 y2 [symbol]\n";
    output << "  RECT x1 y1 x2 y2 [symbol]\n";
    output << "  FILL x y [symbol]\n";
    output << "  CLEAR\n";
    output << "  SHOW\n";
    output << "  SAVE file\n";
    output << "  LOAD file\n";
    output << "  HELP\n";
    output << "  EXIT\n";
}

void ConsoleUI::showPrompt() const {
    output << "> ";
}

void ConsoleUI::showCanvas(const PaintContext& context) const {
    for (const std::string& row : context.getCanvas().getRows()) {
        output << row << '\n';
    }
}

void ConsoleUI::showMessage(const std::string& message) const {
    output << message << '\n';
}

bool ConsoleUI::readLine(std::string& line) const {
    return static_cast<bool>(std::getline(input, line));
}
