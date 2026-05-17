#ifndef I_COMMAND_H
#define I_COMMAND_H

class PaintContext;

class ICommand {
public:
    virtual ~ICommand() = default;

    virtual void execute(PaintContext& context) = 0;
};

#endif
