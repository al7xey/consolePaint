#include "PaintApplication.h"

#include <iostream>
#include <memory>

PaintApplication::PaintApplication()
    : ui(std::cin, std::cout) {
}

void PaintApplication::run() {
    ui.showWelcome();
    ui.showCanvas(context);

    while (context.isRunning()) {
        ui.showPrompt();
        const ParsedCommand parsed = parser.parse(ui.readLine());
        std::unique_ptr<ICommand> command = factory.create(parsed);

        command->execute(context);
        ui.showMessage(context.getLastMessage());

        if (context.isRunning()) {
            ui.showCanvas(context);
        }
    }
}
