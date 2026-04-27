#include "PaintApp.h"

#include <iostream>
#include <sstream>
#include <string>

PaintApp::PaintApp()
    : canvas(20, 10) {
}

void PaintApp::run() {
    std::cout << "Simple Paint\n";
    std::cout << "Only command: POINT x y symbol\n";
    std::cout << "Exit: EXIT\n";

    canvas.print();

    std::string line;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "EXIT") {
            break;
        }

        std::stringstream ss(line);
        std::string command;
        int x;
        int y;
        char symbol;

        ss >> command >> x >> y >> symbol;

        if (command == "POINT") {
            canvas.setPixel(x, y, symbol);
            canvas.print();
        } else {
            std::cout << "Unknown command\n";
        }
    }
}
