#include "ConsoleUI.h"

#include <iostream>

ConsoleUI::ConsoleUI(std::istream& input, std::ostream& output)
    : input(input), output(output) {
}

void ConsoleUI::showWelcome() const {
    output << "Console Paint\n";
    output << "Type HELP to show commands, EXIT to quit.\n";
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

std::string ConsoleUI::readLine() const {
    std::string line;
    std::getline(input, line);
    return line;
}
