#include "PaintApplication.h"

#include <iostream>
#include <memory>
#include <string>

PaintApplication::PaintApplication()
    : ui(std::cin, std::cout) {
}

PaintApplication::PaintApplication(std::istream& input, std::ostream& output)
    : ui(input, output) {
}

void PaintApplication::run() {
    ui.showWelcome();
    ui.showCanvas(context);

    while (context.isRunning()) {
        ui.showPrompt();
        std::string line;
        if (!ui.readLine(line)) {
            break;
        }

        const ParsedCommand parsed = parser.parse(line);
        std::unique_ptr<ICommand> command = factory.create(parsed);

        command->execute(context);
        ui.showMessage(context.getLastMessage());

        if (context.isRunning()) {
            ui.showCanvas(context);
        }
    }
}
