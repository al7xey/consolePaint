#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include "ICommand.h"

#include <string>

class SaveCommand : public ICommand {
private:
    std::string filePath;

public:
    explicit SaveCommand(std::string filePath);

    void execute(PaintContext& context) override;
};

#endif
