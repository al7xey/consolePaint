#include "PaintApplication.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace {

void printUsage(const char* programName) {
    std::cout << "Usage:\n"
              << "  " << programName << "\n"
              << "  " << programName << " --command \"CANVAS 8 4\" --command \"SHOW\" --command \"EXIT\"\n"
              << "  " << programName << " --script commands.txt\n"
              << "  " << programName << " CANVAS 8 4\n";
}

}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        PaintApplication app;
        app.run();
        return 0;
    }

    std::ostringstream commandInput;

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];

        if (arg == "--help" || arg == "-h") {
            printUsage(argv[0]);
            return 0;
        }

        if (arg == "--command" || arg == "-c") {
            if (i + 1 >= argc) {
                std::cerr << "Missing command after " << arg << '\n';
                return 1;
            }

            commandInput << argv[++i] << '\n';
            continue;
        }

        if (arg == "--script" || arg == "-s") {
            if (i + 1 >= argc) {
                std::cerr << "Missing file path after " << arg << '\n';
                return 1;
            }

            std::ifstream script(argv[++i]);
            if (!script) {
                std::cerr << "Cannot open script file: " << argv[i] << '\n';
                return 1;
            }

            commandInput << script.rdbuf();
            commandInput << '\n';
            continue;
        }

        for (int j = i; j < argc; ++j) {
            if (j > i) {
                commandInput << ' ';
            }
            commandInput << argv[j];
        }
        commandInput << '\n';
        break;
    }

    std::istringstream input(commandInput.str());
    PaintApplication app(input, std::cout);
    app.run();
    return 0;
}
