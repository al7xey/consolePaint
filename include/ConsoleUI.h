#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "PaintContext.h"

#include <iosfwd>
#include <string>

class ConsoleUI {
private:
    std::istream& input;
    std::ostream& output;

public:
    ConsoleUI(std::istream& input, std::ostream& output);

    void showWelcome() const;
    void showPrompt() const;
    void showCanvas(const PaintContext& context) const;
    void showMessage(const std::string& message) const;
    bool readLine(std::string& line) const;
};

#endif
