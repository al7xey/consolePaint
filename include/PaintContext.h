#ifndef PAINT_CONTEXT_H
#define PAINT_CONTEXT_H

#include "Canvas.h"
#include "FileManager.h"
#include "drawing/QueueFillStrategy.h"
#include "drawing/ShapeDrawer.h"

#include <string>

class PaintContext {
private:
    Canvas canvas;
    ShapeDrawer drawer;
    QueueFillStrategy fillStrategy;
    FileManager fileManager;
    char brushSymbol;
    bool running;
    std::string lastMessage;

public:
    PaintContext();

    Canvas& getCanvas();
    const Canvas& getCanvas() const;
    char getBrushSymbol() const;
    bool isRunning() const;
    const std::string& getLastMessage() const;

    void createCanvas(int width, int height);
    void setBrushSymbol(char symbol);
    void drawPoint(int x, int y, char symbol);
    void drawLine(int x1, int y1, int x2, int y2, char symbol);
    void drawRectangle(int x1, int y1, int x2, int y2, char symbol);
    void fill(int x, int y, char symbol);
    void clear();
    bool save(const std::string& filePath) const;
    bool load(const std::string& filePath);
    void stop();
    void setLastMessage(const std::string& message);
};

#endif
