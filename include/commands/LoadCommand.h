#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include "ICommand.h"

#include <string>

class LoadCommand : public ICommand {
private:
    std::string filePath;

public:
    explicit LoadCommand(std::string filePath);

    void execute(PaintContext& context) override;
};

#endif
